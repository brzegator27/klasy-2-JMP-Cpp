#include "Marsjanin.h"


Marsjanin::Marsjanin() { this->quantity++; }

Marsjanin::Marsjanin(int number) : number(number) { this->quantity++; }


Marsjanin::~Marsjanin() { this->quantity--; }

void Marsjanin::atakuj()
{
	cout << "Marsjanin o nr " << this->number << " atakuje!" << endl;
}
