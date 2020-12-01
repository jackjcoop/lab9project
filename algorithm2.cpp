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
#include "MatrixIOFunctions.h"


using namespace std;
using namespace Eigen;

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






