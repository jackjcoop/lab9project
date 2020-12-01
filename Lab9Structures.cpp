#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Eigen/Dense"
#include "Eigen/Eigen"
#include <cmath>
#include <math.h>
#include "Lab9Structures.h"

using namespace std;
using namespace Eigen;
//Default Constructor to Set to Zero
Plane::Plane()
    {
        nx_plane = 0;
        ny_plane = 0;
        nz_plane = 0;
        d_plane = 0;
    }


//Overload Constructor to receive values for private data members
Plane::Plane(double nx, double ny, double nz, double nd)
    {
        nx_plane = nx;
        ny_plane = ny;
        nz_plane = nz;
        d_plane = nd;

        return;
    }

//Set function. Sets values for data members.
void Plane::Set(double nx, double ny, double nz, double nd)
    {
        nx_plane = nx;
        ny_plane = ny;
        nz_plane = nz;
        d_plane = nd;

        return;
    }

//Get function. Retrieves values. Help Jackson! How do I make this???
int Plane::get_nx_plane() const { return nx_plane; }
int Plane::get_ny_plane() const { return ny_plane; }
int Plane::get_nz_plane() const { return nz_plane; }
int Plane::get_d_plane() const { return d_plane; }

//Function to calculate distance between point and plane.
double Plane::pointdistance(Point& P) const
{
    double pdistance;
    struct Point arr = P;
    Plane A;

    double numerator = ((arr.xi * nx_plane) + (arr.yi * ny_plane) + (arr.zi * nz_plane) + d_plane);
    double newnumerator = pow(numerator, 2);
    double finalnumerator = sqrt(newnumerator);
    double denominator = sqrt(pow(nx_plane,2) + pow(ny_plane,2) + pow(nz_plane,2));

    pdistance = (finalnumerator/denominator);

    return pdistance;

}

void Plane::algorithm1(Eigen::MatrixXd matrix)
{
    // Calculate the approximate plane parameters; Procedure 1
    Eigen::MatrixXd A(matrix.rows(), 3);
    Eigen::MatrixXd L;
    L.setOnes(matrix.rows(), 1);

    for(int i = 0; i < A.rows()-1; i++)
    {
        // matrix starts 1,2,3 because 0 column is ID
        A(i, 0) = matrix(i, 1);
        A(i, 1) = matrix(i, 2);
        A(i, 2) = matrix(i, 3);
    }

    Eigen::MatrixXd deltax = (A.transpose()*A);
    deltax = deltax.inverse();
    deltax *= (A.transpose() * L);

    double u = sqrt(pow(A(0,0),2) + pow(A(1,0),2) + pow(A(2,0),2));

    deltax = deltax/u;

    nx_plane = deltax(0,0);
    ny_plane = deltax(1,0);
    nz_plane = deltax(2,0);
    d_plane = -1/u;

    // End Procedure 1

    // Update the plane parameters. Procedure 2

    Eigen::MatrixXd B(matrix.rows(), 4);
    Eigen::MatrixXd W(matrix.rows(), 1);
    //finds the normal
    double unorm = sqrt(nx_plane + ny_plane + nz_plane);

    for (int i = 0; i < 10; i++)
    {


            for(int i = 0; i < B.rows()-1; i++)
        {
        // matrix starts 1,2,3 because 0 column is ID
        B(i, 0) = matrix(i, 1);
        B(i, 1) = matrix(i, 2);
        B(i, 2) = matrix(i, 3);
        B(i, 3) = 1;

        W(i, 0) = -1*(nx_plane*matrix(i,1)+ ny_plane*matrix(i, 2) + nz_plane*matrix(i, 3) + d_plane);
        }


    Eigen::MatrixXd H(1, 4);
    H(0,0) = nx_plane / unorm;
    H(0,1) = ny_plane / unorm;
    H(0,2) = nz_plane / unorm;
    H(0,3) = 0;

    Eigen::MatrixXd Hc(1,1);

    Hc(0,0) = 1 - unorm;

    Eigen::MatrixXd N = B.transpose()*B;
    Eigen::MatrixXd U = B.transpose()*W;

    //Row-wise Concatenation
    Eigen::MatrixXd Uc(U.rows() + Hc.rows(), U.cols());
    Uc << U,
        Hc;

    Eigen::MatrixXd Htrans = H.transpose();
    Eigen::MatrixXd K(N.rows() + H.rows(), N.cols()+ Htrans.cols());
    K << N, H;

    Eigen::MatrixXd newdeltax = K.transpose()*Uc;

    nx_plane += newdeltax(0,0);
    ny_plane += newdeltax(1, 0);
    nz_plane += newdeltax(2, 0);
    d_plane += newdeltax(3, 0);

    }


}

vector<bool> Plane::RANSAC(MatrixXd matrix) { //argument is a vector of type point

    //intializing intial values of 0 and the length of points numPoints
    int t,c= 0;
    int numPoints = matrix.rows();

    //intializing the boolean vector of size numPoints from the inputted matrix
    vector<bool> I;
    I.resize(numPoints);

    do
    {
        t += 1;
        MatrixXd B(3,3);

        for(int i = 0; i < numPoints; i++)
        {
            I[t] = false;
        }


        //populating matrix B with random
        for(int i = 0; i < 3; i++)
        {
            double rand_row = rand()%B.rows();
            for(int j = 0; j < 3; j++)
            {
               B(i,j) = matrix(rand_row,j);
            }

        }

        //passing B into algorithm one
        //algorithm_1(B);

        c = 0;

        for(int j = 0; j < numPoints; j++)
        {
           //intializing point object with coordiantes x,y,z
           Point object;
           object.x = matrix(j,1);
           object.y = matrix(j,2);
           object.z = matrix(j,3);

           //computing distance of the object
           double distance_length = distance(object);

           if(distance_length < 0.01)
           {
            I[j] = true;
            c++;
           }
        }
    }
    while (c < (numPoints / 2) && t < 50);

    MatrixXd P(c,3);

    for(int i = 0; i < numPoints; i++)
    {
        if(I[i] == true)
        {
            P(i,0) = matrix(i,0);
            P(i,1) = matrix(i,1);
            P(i,2) = matrix(i,2);
        }
    }
    algorithm1(P);

    return I;

}










