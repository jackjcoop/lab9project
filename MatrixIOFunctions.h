#ifndef MATRIXIOFUNTIONS_H_INCLUDED
#define MATRIXIOFUNTIONS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "..\eigen-3.3.8\Eigen\Eigen"

using namespace std;
using namespace Eigen;

MatrixXd ReadDataToMatrix(const string& filename);

void WriteMatrixToFile(const MatrixXd &Mat, const string& filename,	unsigned int precision);

#endif // MATRIXIOFUNTIONS_H_INCLUDED
