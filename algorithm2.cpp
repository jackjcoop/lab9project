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

Plane RANSAC(vector<Point> pointsVec) { //argument is a vector of type point

    int t,c= 0;

    Plane result = Plane();
    int numPoints = pointsVec.size();

    MatrixXd B = MatrixXd(3, 3);

    vector<bool> I;
    I.resize(numPoints);


    do
    {
        t += 1;
        I[t] = false;

        double rows = rand()%B.rows();

        fitPlane(B);
        int i, j = 0;


        do
        {
            B(i,0) = 0;
            B(i,j) = pointsVec(numPoints - 1, j);
            j++;
        }
        while(i< 3 && j < 3)

        i++
        c = 0;

        for(int k = 0; k < numPoints; k++)
        {

        if()
        }

    }
    while (c < (numPoints / 2) && t < 50);

    MatrixXd P(c,3);

    for(int i = 0; i < numPoints, i++)
    {
        if(I[k] == true)
        {
            P(k,1) = matrix(k,1);
            P(k,2) = matrix(k,2);
            P(k,3) = matrix(k,3);
        }
    }
    fitPlane(P);


  return result;
}
