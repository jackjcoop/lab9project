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

Plane RANSAC(vector<bool> boolVec) { //argument is a vector of type point

    int t,c= 0;

    Plane result = Plane();
    int numPoints = boolVec.size();

    vector<bool> I;
    I.resize(numPoints);

    MatrixXd B(3,3);

    do
    {
        t += 1;
        I[t] = false;

        double rows = rand()%B.rows();

        fitPlane(B);
        int i, j = 0;


    while (c < (numPoints / 2) && t < 50);

    MatrixXd P(c,3);

    for(int i = 0; i < numPoints, i++)
    {
        if(I[k] == true)
        {
            P(k,1) = P(k,1);
            P(k,2) = P(k,2);
            P(k,3) = P(k,3);
        }
    }
    fitPlane(P);


  return result;
}
