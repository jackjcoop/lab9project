#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Eigen/Dense"
#include <cmath>
#include <math.h>
#include "Lab9Structures.h"

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
void Plane::set(double nx, double ny, double nz, double nd)
    {
        nx_plane = nx;
        ny_plane = ny;
        nz_plane = nz;
        d_plane = nd;

        return;
    }

//Get function. Retrieves values. Help Jackson! How do I make this???
Plane Plane::get(Plane P) const
    {
        Plane A = P;
        return A;
    }

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

// Mutator function!!
Plane Plane::object(const vector<Point>& pointsVec) const
{



}
