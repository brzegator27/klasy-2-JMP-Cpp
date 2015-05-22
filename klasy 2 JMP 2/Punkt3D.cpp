#include "Punkt3D.h"
#include <math.h> 


Punkt3D::Punkt3D()
{
	cout << "Konstruktor Punkt3D" << endl;
}


Punkt3D::~Punkt3D()
{
	cout << "Destrunktor Punkt3D" << endl;
}

double Punkt3D::distance(Punkt3D inny)
{
	cout << "distance Punkt3D" << endl;
	//return sqrt(pow(x - inny.x, 2) + pow(y - inny.y, 2));
	return cbrt(pow(this->getX() - inny.getX(), 2) + pow(this->getY() - inny.getY(), 2) + pow(z - inny.z, 2));
}
