#include <iostream>
#include <iomanip>
#include <math.h>
#include "point.h"
#include "circle.h"

using namespace std;

#define PI 3.14159265358979323846


Circle::Circle():Point()
{
}

Circle::Circle(double x, double y,  double radius, double r, double g, double b):Point(x,y)
{
	SetColour(r,g,b);
	Radius = radius;
}

Circle::Circle(Point c, double radius, double r, double g, double b)
{
	X = c.GetX();
	Y = c.GetY();
	Radius = radius;
	R = r;
	G = g;
	B = b;
}

Circle::~Circle()
{
}

double Circle::GetRadius()
{
	return Radius;
}
void Circle::SetRadius(double radius)
{
	Radius = radius;
}
void Circle::Draw()
{
	std::cout << "Drawing a circle" <<std::endl;
}


// This function is redundant however provides better readability
void Circle::Move(double x, double y) 
{
	Point::Move(x,y);
}

ostream& operator<<(ostream& os, const Circle& c)
{
	os << setw(10) << setprecision(3) << c.X << ' ';
	os << setw(10) << c.Y << ' ';
	os << setw(10) << c.Radius << ' ';
	os << setw(10) << c.R << ' ';
	os << setw(10) << c.G << ' ';
	os << setw(10) << c.B;

	return os;
}
