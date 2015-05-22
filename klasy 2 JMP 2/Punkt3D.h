#include <iostream>
#include "Punkt.h"

using namespace std;

#pragma once
class Punkt3D : public Punkt
{
	double z;
public:
	Punkt3D();
	Punkt3D(double _x, double _y, double _z) : Punkt(_x, _y) { z = _z; }
	~Punkt3D();

	double distance(Punkt3D);
};

