#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Eigen/Dense"
#include <cmath>
#include <math.h>
#include "Lab9Structures.h"
#include "MatrixIOFunctions.h"


using namespace std;
using namespace Eigen;


int main()
{

//Reading data from txt file.
MatrixXd PointCloud = ReadDataToMatrix("PointCloudData.txt");
int r = PointCloud.rows();
int c = PointCloud.cols();


// Empty vector of Plane objects
vector <Plane> planeobjects;

// Matrix I with n x 1
MatrixXd I;
I.resize(r, 1);

//Setting to Zero
I.setZero();

//Part d. of the lab

//d.a
//Reading all Seeds files and putting into a matrix.
MatrixXd Seeds1 = ReadDataToMatrix("Seeds1.txt");
MatrixXd Seeds2 = ReadDataToMatrix("Seeds2.txt");
MatrixXd Seeds3 = ReadDataToMatrix("Seeds3.txt");
MatrixXd Seeds4 = ReadDataToMatrix("Seeds4.txt");
MatrixXd Seeds5 = ReadDataToMatrix("Seeds5.txt");
MatrixXd Seeds6 = ReadDataToMatrix("Seeds6.txt");

// Matching Seeds1.txt to points in Point Cloud
MatrixXd Match1(Seeds1.rows(), 4);

for (int i = 0; i < Seeds1.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds1(i, 0) == PointCloud(a, 0))
        {
            Match1(i,0) = PointCloud(a, 0);
            Match1(i,1) = PointCloud(a, 1);
            Match1(i,2) = PointCloud(a, 2);
            Match1(i,3) = PointCloud(a, 3);
        }

    }
}

// Matching Seeds2.txt to points in Point Cloud
MatrixXd Match2(Seeds2.rows(), 4);
for (int i = 0; i < Seeds2.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds2(i, 0) == PointCloud(a, 0))
        {
            Match2(i,0) = PointCloud(a, 0);
            Match2(i,1) = PointCloud(a, 1);
            Match2(i,2) = PointCloud(a, 2);
            Match2(i,3) = PointCloud(a, 3);
        }

    }
}

// Matching Seeds3.txt to points in Point Cloud
MatrixXd Match3(Seeds3.rows(), 4);
for (int i = 0; i < Seeds3.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds3(i, 0) == PointCloud(a, 0))
        {
            Match3(i,0) = PointCloud(a, 0);
            Match3(i,1) = PointCloud(a, 1);
            Match3(i,2) = PointCloud(a, 2);
            Match3(i,3) = PointCloud(a, 3);
        }

    }
}

// Matching Seeds4.txt to points in Point Cloud
MatrixXd Match4(Seeds4.rows(), 4);
for (int i = 0; i < Seeds4.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds4(i, 0) == PointCloud(a, 0))
        {
            Match4(i,0) = PointCloud(a, 0);
            Match4(i,1) = PointCloud(a, 1);
            Match4(i,2) = PointCloud(a, 2);
            Match4(i,3) = PointCloud(a, 3);
        }

    }
}

// Matching Seeds5.txt to points in Point Cloud
MatrixXd Match5(Seeds5.rows(), 4);
for (int i = 0; i < Seeds5.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds5(i, 0) == PointCloud(a, 0))
        {
            Match5(i,0) = PointCloud(a, 0);
            Match5(i,1) = PointCloud(a, 1);
            Match5(i,2) = PointCloud(a, 2);
            Match5(i,3) = PointCloud(a, 3);
        }

    }
}

// Matching Seeds5.txt to points in Point Cloud
MatrixXd Match5(Seeds5.rows(), 4);
for (int i = 0; i < Seeds5.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds5(i, 0) == PointCloud(a, 0))
        {
            Match5(i,0) = PointCloud(a, 0);
            Match5(i,1) = PointCloud(a, 1);
            Match5(i,2) = PointCloud(a, 2);
            Match5(i,3) = PointCloud(a, 3);
        }

    }
}

// Matching Seeds6.txt to points in Point Cloud
MatrixXd Match6(Seeds6.rows(), 4);
for (int i = 0; i < Seeds6.rows(); i++)
{
    for (int a = 0; a < r; a++)
    {
        if (Seeds6(i, 0) == PointCloud(a, 0))
        {
            Match6(i,0) = PointCloud(a, 0);
            Match6(i,1) = PointCloud(a, 1);
            Match6(i,2) = PointCloud(a, 2);
            Match6(i,3) = PointCloud(a, 3);
        }

    }
}

//d.b Using Function from Task 4 to calculate the correct plane parameter
//Match[i] where i <= 6, are all the Matrices that hold the correlating points.

//d.c Insert plane object into the vector of Plane

//d.d calculate and stuff

//part e, creating a new matrix and concatenate with the others.

//part f, output file
WriteMatrixToFile(/*MatrixName*/, "OutputPointCloud.txt", 15);

//part g, convert Plane vector to Eigen Matrix


}
