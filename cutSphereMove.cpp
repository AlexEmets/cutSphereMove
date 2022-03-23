#include <string>

#include "mwTPoint3d.hpp"
#include "mwArcFunction.hpp"
#include "CreateSkin.hpp"
#include "iostream"
#include "fstream"

//#############################################################################

int main(int argc, char* argv[])
{

	//Point cloud reference point at 0, 0, 0
	cadcam::mwTPoint3d<double> referencePoint( 0., 0., 0. );

	//Number of points in x direction
	const unsigned long nx = 1000;

	//Number of points in y direction
	const unsigned long ny = 500;

	//Number of points in z direction
	const unsigned long nz = 100;

	//Distance between points in the point grid (same fo x, y and z directions)
	const double delta = 1.;

	//Discrete step for move function calculation
	const double deltaT = 0.01;

	//Radius of the sphere
	const double sphereRad = 5.;

	//Name of the file to write the skin data to
	const std::string skinFileName( R"(C:\Users\oleksandr.yemets\Documents\testTaskSphere\test.asc)" );
    std::ofstream out(skinFileName);
    for(int i = -50; i < 50; ++i) {
        for(int j = -50; j < 50; ++j) {
            for (int k = -50; k < 50; ++k) {

                if((i <= -30 || i >= 30) || (j <= -30 || j >= 30))
                    out << i*3 << " " << j*3 << " " << k*3 << '\n';

            }
        }
    }
	//Function object to be evaluated
	mwArcFunction func( 0., 1., 150. );

	//Evaluation here
	CreateSkin( referencePoint, nx, ny, nz, sphereRad, func, deltaT, delta, skinFileName );
    std::cout << delta;
	return 0;
}
