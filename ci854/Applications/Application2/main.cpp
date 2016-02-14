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

Renderer* renderer;
ArcballCamera* camera;

//Exercise 1 - Add a data structure to hold the originally loaded mesh
//Cause the mesh is vectorized after the load
std::vector<vec3> _originalV(0); //vectors
std::vector<ivec3> _originalT(0);		//triangles

//Exercise 2
void updateTransformation()
{
	std::vector<vec3> _N(_originalV.size(), vec3::Zero());
	std::vector<vec3> _V(_originalV.size(), vec3::Zero());
	std::vector<ivec3> _T(_originalT.size(), ivec3::Zero());
	//std::vector<vec3>::iterator i;

	mat3 R;
	R << 	0, 1, 0,
		-2, 0, 0,
		0, 0, 1;

	vec3 t(0.0f, 0.2f, 0.0f);

	for (unsigned int i = 0; i < _originalV.size(); ++i)
	{
		_V[i] = R*_originalV[i]+t;
	}


	//for (i = _originalV.begin(); i < _originalV.end(); i++)
	//{
	//	*i = *i + _originalV(0.5f, 0.0f, 0.0f);
	//}

	computeTriangleMeshNormals(_V, _originalT, _N);

        Renderable *pt = renderer->getPtRenderable("mesh");
        
	pt->updateVerticesAndNormals(_V, _N);

        glutPostRedisplay();

}

void resetTransformation()
{
	std::vector<vec3> normals;
	computeTriangleMeshNormals(_originalV,_originalT, normals);
	renderer->getPtRenderable("mesh")->updateVerticesAndNormals(_originalV, normals);
}

void init(void)
{
	// init camera
	camera = new ArcballCamera();
	camera->setLookAt(vec3(0, 0, 3), vec3(0, 0, 0), vec3(0, 1, 0));

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
	sDesc.ambient = vec4(REAL(0.3), REAL(0.1), REAL(0.1), REAL(1));
	sDesc.diffuse = vec4(REAL(0.96), REAL(0.76), REAL(0.76), REAL(1));
	sDesc.specular = vec4(REAL(0.04), REAL(0.02), REAL(0.02), REAL(1));
	sDesc.shine = REAL(2);
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
	
	glutPostRedisplay();
}

void importMesh(const std::string& filename)
{
	// load model
	std::vector<vec3> _V(0), _N(0);
	std::vector<ivec3> _T(0);
	mat4 M;
	M.setIdentity();

	if (!importTriangleMeshFromOFF(filename, _V, _T))
	{
		LOG("failed to load " << filename);
		exit(1);
	}
	centerMesh(_V);
	computeTriangleMeshNormals(_V, _T, _N);
	
	_originalV = _V;
	_originalT = _T;

	Renderable *pt = renderer->getPtRenderable("mesh");
	if (!pt)
		renderer->addRenderable("mesh", _V, _T, "mesh", M);
	else
		pt->updateVerticesAndNormals(_V, _N);

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
	//

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

	case 'u':
		updateTransformation();
		break;

	case 'r':
		resetTransformation();
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
	importMesh("../Media/avatar.off");

	glutMainLoop();
	
	return 0;
}
