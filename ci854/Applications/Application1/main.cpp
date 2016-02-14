#include <iostream>
#include <Eigen/Eigen>

int main(int argc, char ** argv)
{
	// basic vectors
	Eigen::Vector3f v1 = Eigen::Vector3f::Zero();
	v1.x() = 1;
	v1.y() = -1;
	v1.z() = 2.0f;
	std::cerr << "v1: " << v1 << std::endl;

	Eigen::Vector3f v2(6, 5, 4.5f);
	std::cerr << "v2:\n" << v2 << std::endl;
	v2[2] = 0.0f;
	std::cerr << "v2 (new):\n" << v2 << std::endl;

	// simple operations
	std::cerr << "v1 + v2:\n" << v1 + v2 << std::endl;
	std::cerr << "v2 - v1:\n" << v2 - v1 << std::endl;
	std::cerr << "v1 | v2:\n" << v1.dot(v2) << std::endl;
	v1 = Eigen::Vector3f(1, 0, 0);
	v2 = Eigen::Vector3f(0, 1, 0);
	std::cerr << "v1 x v2:\n" << v1.cross(v2) << std::endl;

	// simple norm
	std::cerr << "distance v1 to v2:\n" << (v2 - v1).norm() << std::endl;

	// basic matrix
	Eigen::Matrix3f M1 = Eigen::Matrix3f::Zero();
	M1(1, 1) = 3.1415f;
	std::cerr << "M1:\n" << M1 << std::endl;
	
	Eigen::Matrix3f M2 = Eigen::Matrix3f::Identity();
	std::cerr << "M2:\n" << M2 << std::endl;

	// simple operations
	std::cerr << "M1 + M2:\n" << M1 + M2 << std::endl;
	std::cerr << "M1 - M2:\n" << M1 - M2 << std::endl;
	std::cerr << "M1 * M2:\n" << M1 * M2 << std::endl;
	std::cerr << "M1 * v1:\n" << M1 * v1 << std::endl;
	//std::cerr << "M1 \ M2: " << M1 / M2 << std::endl;
	std::cerr << "M1 / 10.0f:\n" << M1 / 10.0f << std::endl;

	// advanced matrix initialization
	Eigen::Matrix3f M3 = Eigen::Matrix3f::Zero();
	M3 <<	1, 2, 2,
			0, 1, 2,
			0, 0, 1;
	std::cerr << "M3:\n" << M3 << std::endl;

	// simple example transpose
	std::cerr << "M3^T:\n" << M3.transpose() << std::endl;
	Eigen::Matrix3f M4 = M3.transpose();
	std::cerr << "M4:\n" << M4 << std::endl;

	// matrix aliasing
	M4 = M4.transpose();
	std::cerr << "M4^t:\n" << M4 << std::endl;
	
	// from the beginning
	M4 = M3.transpose();
	std::cerr << "M4:\n" << M4 << std::endl;

	M4.transposeInPlace();
	std::cerr << "M4^t:\n" << M4 << std::endl;

	// simple example inverse
	Eigen::Matrix3f M5 = M4.inverse();
	std::cerr << "M5:\n" << M5 << std::endl;
	
	// simple example orthogonal
	Eigen::Matrix3f M6;
	M6 << 0, 1, 0,
		-1, 0, 0,
		0, 0, 1;
	std::cerr << "det of M6:\n" << M6.determinant() << std::endl;

	// block operations
	Eigen::Matrix4f M7;
	M7 << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;
	std::cerr << "M7\n" << M7 << std::endl;
	std::cerr << "slice of M7:\n" << M7.block<3, 1>(0, 1) << std::endl;
	std::cerr << "another slice of M7:\n" << M7.block<2, 3>(0, 0) << std::endl;

	Eigen::Matrix3f RotM;
	RotM = M6;
	Eigen::Vector3f trans(1.0f, 0.0f, 0.0f);
	Eigen::Vector3f x(0.0f, 0.5f, 0.333f);

	std::cerr << "transformation of x:\n" << RotM*x + trans << std::endl;

	// finale
	Eigen::Matrix4f T;
	T << RotM, trans, 0, 0, 0, 1;

	Eigen::Vector4f x_4d;
	x_4d << x, 1.0f;

	std::cerr << "(alternative-)transformation of x\n" << T * x_4d << std::endl;

	return 0;
}
