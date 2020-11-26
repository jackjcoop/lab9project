#include <iostream>
#include "lab8.h"
#include "..\..\eigen-3.3.8\Eigen\Eigen" // need to change

using namespace std;
using namespace Eigen;

Plane fitPlane(vector<Point> pointsVec) { //argument is a vector of type point

    //initialize resultant plant
    Plane result = Plane();

    int numPoints = pointsVec.size();

    //PROCEDURE 1: Calculate approximate plane parameters

    //create matrix A
    MatrixXd A = MatrixXd(numPoints, 3);
    //create matrix L, filled with 1's
    MatrixXd L = MatrixXd::Constant(numPoints, 3, 1);

    //put points x,y,z into each row of A
    for(int i = 0; i < numPoints - 1; i++) {
        for (int j = 1; j < 4; j++) {
            if (j == 1) {
                A(i,j) = pointsVec[i].x;
            }
            if (j == 2) {
                A(i,j) = pointsVec[i].y;
            }
            if (j == 3) {
                A(i,j) = pointsVec[i].z;
            }
        }
    }
    //make new matrix deltaX as product of A and L
    MatrixXd deltaX = (A*A.transpose()).inverse()*(A.transpose()*L);

    //new variable u, assigned to length of deltaX
    double u = deltaX.norm();

    //unit vector!
    deltaX = deltaX/u;

    //update the plane parameters
    result.Set(deltaX(0,1), deltaX(0,2), deltaX(0,3), -1/u);

    return result;
}
