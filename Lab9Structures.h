#ifndef LAB9STRUCTURES_H_INCLUDED
#define LAB9STRUCTURES_H_INCLUDED
#include <vector>
#include <string>

using namespace std;

struct Point
{

    double id; //Point ID
    double xi; // x-coord
    double yi; // y-coord
    double zi; // z-coord

};

class Plane
{

//Private data members
private:

    double  nx_plane;
    double  ny_plane;
    double  nz_plane;
    double  d_plane;

//Public Constructors
public:
//Default Constructor (accepts no arguments)
    Plane();

//Constructor to receive values for private data members
    Plane(double nx, double ny, double nz, double nd);

//Set function, set values for all private data members
    void Set(double nx, double ny, double nz, double nd);

//get function, retrieves values of private data members
    Plane get(Plane P) const;

//function to find distance between plane and the point
    double pointdistance(Point& P) const;

//mutator function that receives a matrix
    Plane object(const Point& P) const;

    //github test push

};
#endif // LAB9STRUCTURES_H_INCLUDED
