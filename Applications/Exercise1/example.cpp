#include <GL/freeglut.h>
#include "fileutils.h"
#include "geomutils.h"
#include "matrixutils.h"
#include "renderer.h"
#include "renderable.h"
#include "surface.h"
#include "camera.h"
#include "light.h"

#define WIDTH 1024
#define HEIGHT 768
#define NUM_SAMPLES 4
#define POINT_RADIUS 0.003

//use this macro to convert from degrees to radiants
#define DEG_TO_RAD(x) { x*0.01745f }

// structure to represent a rigid object with its
// transformation (rotation and translation)
struct RObject
{
    std::vector<vec3> vertices;
    std::vector<vec3> normals;
    std::vector<ivec3> triangles;
    mat4 modelMatrix;

    RObject()
    {
        vertices.clear();
        normals.clear();
        triangles.clear();
        modelMatrix = mat4::Identity();
    }

    void setTransformation(const mat3& R, const vec3& t)
    {
        modelMatrix << R , t, 0, 0, 0, 1;
    }
};

// structure defining an keyframe
struct Keyframe
{
    unsigned int time;
    vec3 translation;
    float rotX;         // rotation about global x
    float rotY;         // rotation about global y
    float rotZ;         // rotation about global z

    Keyframe()
    {
        time = 0;
        translation = vec3::Zero();
        rotX = rotY = rotZ = 0.0f;
    }

    Keyframe(unsigned int t, const vec3& trans, float x, float y, float z)
    {
        time = t;
        translation = trans;
        rotX = x;
        rotY = y;
        rotZ = z;
    }

    Keyframe(const Keyframe& other)
    {
        time = other.time;
        translation = other.translation;
        rotX = other.rotX;
        rotY = other.rotY;
        rotZ = other.rotZ;
    }

    bool operator<(const Keyframe& rhs) { return (time < rhs.time); }
};

Renderer* renderer;
ArcballCamera* camera;
RObject* rigid;
unsigned int frame;
bool runAnimation;


// the animation sequence
std::vector<Keyframe> animation;
unsigned int lastKnownAnimationPosition;
Keyframe lastKnownKeyframe;

void interpolateTransformation(mat3& outR, vec3& outT)
{
	mat3 Rx = mat3::Identity();
	mat3 Ry = mat3::Identity();
	mat3 Rz = mat3::Identity();

	vec3 interpolatedTranslation = vec3::Zero();

	int nextFrame;

	// TODO: search neighbouring keyrames for current 'frame'
	Keyframe previous = animation[lastKnownAnimationPosition];
	if( lastKnownAnimationPosition == animation.size()-1 )
		nextFrame = 0;
	else
		nextFrame = lastKnownAnimationPosition+1;

	Keyframe next = animation[nextFrame];

    // TODO: calculate u as the fractional part of frame between neighbouring keyframes' times
	
    // TODO: linear interpolate the translation and store it to outT
	outT = (animation[nextFrame].translation - animation[lastKnownAnimationPosition].translation)*((float)frame / animation[nextFrame].time);

    // TODO: linear interpolate euler angles and construct rotation matrix (use fixed angles approach)... store it to outR
	float interpolatedX = (animation[nextFrame].rotX - animation[lastKnownAnimationPosition].rotX)*((float)frame / animation[nextFrame].time);
	float interpolatedY = (animation[nextFrame].rotY - animation[lastKnownAnimationPosition].rotY)*((float)frame / animation[nextFrame].time);
	float interpolatedZ = (animation[nextFrame].rotZ - animation[lastKnownAnimationPosition].rotZ)*((float)frame / animation[nextFrame].time);

	Rx << 1, 0, 0,
		  0, cos(interpolatedX), -sin(interpolatedX),
		  0, sin(interpolatedX),  cos(interpolatedX);

	Ry << cos(interpolatedY), 0, -sin(interpolatedY),
		  0, 1, 0,
		  sin(interpolatedY), 0, cos(interpolatedY);

	Rz << cos(interpolatedZ), -sin(interpolatedZ), 0, 
		  sin(interpolatedZ),  cos(interpolatedZ), 0,
		  0, 0, 1;

	outR = Rz*Ry*Rx;

}

void init(void)
{
	runAnimation = false;

    //reset global application state
    frame = 0;
	lastKnownAnimationPosition = 0;

    // init object emtpy
    rigid = new RObject;

	// init camera
	camera = new ArcballCamera();
	camera->setLookAt(vec3(3, 0, 0), vec3(0, 0, 0), vec3(0, 1, 0));

	// init renderer
	renderer = new Renderer();
	if (!renderer->init(WIDTH, HEIGHT, "./shader/", 1))
	{
		LOG("gl initialization failed");
		SAFE_DELETE(camera);
		exit(1);
	}
	renderer->setClearColor(vec4(0.1f, 0.1f, 0.2f, 1.0f));

	// load a surface material
	SurfaceDesc sDesc;
	sDesc.shaderType = SurfaceDesc::SHADER_PHONG;
	sDesc.diffuse_map = "";
	sDesc.normal_map = "";
	sDesc.ambient = vec4(0.1f, 0.1f, 0.1f, 1.0f);
	sDesc.diffuse = vec4(0.6f, 0.6f, 0.6f, 1.0f);
	sDesc.specular = vec4(0.4f, 0.2f, 0.3f, 1.0f);
	sDesc.shine = 2.0f;

	if (!renderer->addSurface("mesh", sDesc))
	{
		LOG("add surface failed");
		SAFE_DELETE(camera);
		exit(1);
	}

	// init miner's light
	LightDesc lDesc;
	lDesc.color = vec4(1, 1, 1, 1);
	lDesc.position = vec3(0, 5, 0);
	lDesc.direction = vec3(0, -1, 0);
	renderer->addLight("light1", lDesc);
	
    // init animation
    animation.clear();
    animation.push_back(Keyframe(0,   vec3(0,0,0),      0.0f, 0.0f,     0.0f));
    animation.push_back(Keyframe(100, vec3(0,0.3f,0),   0.0f, 90.0f,    20.0f));
    animation.push_back(Keyframe(200, vec3(0,0,0),      0.0f, 180.0f,   0.0f));
    animation.push_back(Keyframe(300, vec3(0,-0.3f,0),  0.0f, 270.0f,   -10.0f));
    animation.push_back(Keyframe(400, vec3(0,0,0),      0.0f, 360.0f,   0.0f));

	glutPostRedisplay();
}

void importMesh(const std::string& filename)
{
    if(rigid == NULL)
        return;

	// load model
	if (!importTriangleMeshFromOFF(filename, rigid->vertices, rigid->triangles))
	{
		LOG("failed to load " << filename);
		exit(1);
	}

	centerMesh(rigid->vertices);
	computeTriangleMeshNormals(rigid->vertices, rigid->triangles, rigid->normals);

	Renderable *pt = renderer->getPtRenderable("mesh");
	if (!pt)
		renderer->addRenderable("mesh", rigid->vertices, rigid->triangles, "mesh", rigid->modelMatrix);
	else
		pt->updateVerticesAndNormals(rigid->vertices, rigid->normals);

	glutPostRedisplay();
}

void shutdown(void)
{
	SAFE_DELETE(camera);
	SAFE_DELETE(renderer);
}

void display(void)
{  
	// setup light to be a miners lamp
	mat4 lM;
	vec3 lPos, lDir;
	camera->getViewMatrix(lM);
	extractEyePosFromViewMatrix(lM, lPos);
	lM.transposeInPlace();
	lDir = -lM.block<3, 1>(0, 2).normalized();
	renderer->getPtLight("light1")->setPosition(lPos);
	renderer->getPtLight("light1")->setDirection(lDir);
	
    // update render mesh from rigid
    Renderable* pt = renderer->getPtRenderable("mesh");
    if(pt)
        pt->setModelMatrix(rigid->modelMatrix);

	// render the scene
	renderer->render((Camera*)camera);

	glutSwapBuffers();
}

void resize(int w, int h)
{
	REAL aspect = REAL(w) / REAL((h == 0) ? 1 : h);
	renderer->resize(w, h);
	camera->resize(w, h);
	camera->setPerspectiveProjection(REAL(45), aspect, REAL(0.1), REAL(100.0));
	glutPostRedisplay();
}

void idle()
{
    // interpolate from keyframes
    mat3 R = mat3::Identity();
    vec3 t = vec3::Zero(); 

    // advance time
    // TODO: advance the frame-counter
	
	if(runAnimation)
		frame++; //Add one to the frame counter

    // TODO: implement cyclic animation here
	if( frame != animation[lastKnownAnimationPosition + 1].time )
	{
		interpolateTransformation(R, t);
	}
	else
	{
		mat3 Rx = mat3::Identity();
		mat3 Ry = mat3::Identity();
		mat3 Rz = mat3::Identity();

		Rx << 1, 0, 0,
			0, cos(animation[lastKnownAnimationPosition].rotX), -sin(animation[lastKnownAnimationPosition].rotX),
			0, sin(animation[lastKnownAnimationPosition].rotX),  cos(animation[lastKnownAnimationPosition].rotX);

		Ry << cos(animation[lastKnownAnimationPosition].rotY), 0, -sin(animation[lastKnownAnimationPosition].rotY),
			0, 1, 0,
			sin(animation[lastKnownAnimationPosition].rotY), 0, cos(animation[lastKnownAnimationPosition].rotY);

		Rz << cos(animation[lastKnownAnimationPosition].rotZ), -sin(animation[lastKnownAnimationPosition].rotZ), 0, 
			sin(animation[lastKnownAnimationPosition].rotZ),  cos(animation[lastKnownAnimationPosition].rotZ), 0,
			0, 0, 1;

		R = Rx*Ry*Rz;

		t = animation[lastKnownAnimationPosition].translation;

		lastKnownAnimationPosition++;
		if( lastKnownAnimationPosition >= animation.size()-1 )
		{
			lastKnownAnimationPosition = 0;
			frame = 0;
		}
	}

	interpolateTransformation(R, t);
    rigid->setTransformation(R, t);
	
    glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y)
{
    // catch the wheel event
    if(button == 3)
    {
        camera->addRadius(0.01f);
        return;
    }
    
    if(button == 4)
    {
        camera->addRadius(-0.01f);
        return;
    }

	switch (state)
	{
	case GLUT_DOWN:
		if (button == GLUT_RIGHT_BUTTON)
		{
			camera->startMovement(x, y);
		}
		break;

	case GLUT_UP:
		if (button == GLUT_RIGHT_BUTTON)
		{
			// deactivate camera movement
			camera->stopMovement();
		}
		break;

	default:
		break;
	}
}

void mouseMove(int x, int y)
{
	camera->move(x, y);

	glutPostRedisplay();
}

void mouseWheel(int button, int dir, int x, int y)
{
    std::cerr << "wheel " << dir/30.0f;

	glutPostRedisplay();
}

void key(unsigned char key, int x, int y)
{
	switch (key) {

	case 27: // ESCAPE KEY
		shutdown();
		exit(0);
		break;

    case '+':
        // uncomment for manual frame forwarding
        frame++;
        std::cerr << frame << std::endl;
        break;

	case ' ':
		runAnimation = !runAnimation;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	// init window and gl
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Animation Framework");
		
	// register callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutIdleFunc(idle);
	glutKeyboardFunc(key);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutCloseFunc(shutdown);

	init();
	importMesh("../Media/p26.off");

	glutMainLoop();
	
	return 0;
}
