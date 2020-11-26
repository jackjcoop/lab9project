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


// Empty vector of Plane objects
vector <Plane> planeobjects;

// Matrix I with n x 1
MatrixXd I;
I.resize(r, 1);

//Setting to Zero
I.setZero();

//Part d. of the lab, needs to loop 1-6 of Algorithm 2.



}
