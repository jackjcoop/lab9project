#include <iostream>
#include "Lab9Structures.h"
#include "Eigen/Eigen"

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
    //NOTE: assumes xi,yi,zi are in the second, third, and fourth columns of the input vector
    for(int i = 0; i < numPoints - 1; i++) {
        for (int j = 1; j < 4; j++) {
            if (j == 1) {
                A(i,j) = pointsVec[i].xi;
            }
            if (j == 2) {
                A(i,j) = pointsVec[i].yi;
            }
            if (j == 3) {
                A(i,j) = pointsVec[i].zi;
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
    result.Set(deltaX(0,1), deltaX(0,2), deltaX(0,3), -1/u); //CHECK

    //PROCEDURE 2. Update the plane parameters

    for (int counter = 0; counter < 10; counter++) {
        //create matrix A
        MatrixXd A = MatrixXd(numPoints, 4);
        //create matrix L, filled with 1's
        MatrixXd W = MatrixXd(numPoints, 1);

        //normalize nx,ny,nz
        u = deltaX.norm();

        for (int i = 0; i < numPoints - 1; i++) {
            for (int j = 0; j < 4; j++) {

                //i-th row of A is set to [xi,yi,zi,1]
                if (j == 0) {
                A(i,j) = pointsVec[i].xi;
                }
                if (j == 1) {
                A(i,j) = pointsVec[i].yi;
                }
                if (j == 2) {
                    A(i,j) = pointsVec[i].zi;
                }
                if (j == 3) {
                    A(i,j) = 1;
                }

                //i-th row of W is set to -(nxXi + nyYi + nzZi + d)
                if (j == 0) { //this is a slightly silly if statement, but it only runs once per i increment so I win
                   // W(i,0) = -1*(result.get(nx_plane)*pointsVec[i].xi + result.get(ny_plane)*pointsVec[i].yi + result.get(nz_plane)*pointsVec[i].zi + pointsVec[i].id);
                } //**CODE ABOVE COMMENTED OUT** Need to figure out how to access the Plane 'result' member values

            }
        }

        //create unit vector H
        MatrixXd H = MatrixXd(1,4);
//            H(0,0) = result.get(nx_plane)/u;
//            H(0,1) = result.get(ny_plane)/u;  // **NEED PLANE GET FUNCTION** (don't mean to be aggressive haha)
//            H(0,2) = result.get(nz_plane)u;
            H(0,3) = 0;

        //create 1-by-1 matrix Hc
        MatrixXd Hc = MatrixXd(1,1);
            Hc(0,0) = (1-u);

        //create new matrix N
        MatrixXd N = MatrixXd();
        N = A.transpose()*A;

        //create new matrix U
        MatrixXd U = MatrixXd();
        U = A.transpose()*W;

        //create new matrix Uc
        MatrixXd Uc = MatrixXd();
       // Uc << U << Hc;                HOW DO YOU CONCATENATE MATRICES???

        //create new matrix K
        MatrixXd K = MatrixXd();
        //K << N << H.transpose() << H << 0;       HOW DO YOU CONCATENATE MATRICES???

        deltaX = K.inverse()*Uc;

        //result.Set(deltaX(0,1) + result.get(nx_plane), deltaX(0,2) + result.get(ny_plane), deltaX(0,3) + result.get(nz_plane), deltaX(0,4) + result.get(d_plane)); // **NEED PLANE GET FUNCTION** (don't mean to be aggressive haha)

    }


    return result;
}
