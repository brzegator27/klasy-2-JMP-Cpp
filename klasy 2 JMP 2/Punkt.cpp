#include "Punkt.h"

#include <iomanip>
#include <iostream>

using namespace std;

//Specjalna inicjalizacja zmiennych. Zmienne s¹ inicjowane
//nim zostanie wywo³ane cia³o konstruktora
Punkt::Punkt() :x(0), y(0){
	//cout << "Konstruktor bezparametrowy" << endl;
	cout << "Konstruktor Punkt" << endl;
}

Punkt::Punkt(double _x, double _y){
	//cout << "Konstruktor parametrowy" << endl;
	x = _x;
	y = _y;
}

Punkt::Punkt(const Punkt &punkt){
	this->x = punkt.x;
	this->y = punkt.y;
	cout << "Konstruktor kopiuj¹cy!" << endl;
}

Punkt::~Punkt(){
	//cout << "Destruktor! Nic nie robie, bo nie musze zwalniaæ pamiêci!";
	cout << "Destruktor Punkt" << endl;
	//cout << endl;
}

istream& operator>>(istream & input, Punkt& p){
	input.ignore();    // Ignoruj nawias
	input >> p.x;
	input.ignore();    // Ignoruj przecinek
	input >> p.y;
	input.ignore();    // Ignowruj nawias
	return input;      // Umo¿liwia cin >> a >> b >> c;
}

ostream& operator<<(ostream & output, const Punkt& p)
{
	return output << "(" << p.x << ", " << p.y << ")";
}

double Punkt::distance(Punkt inny){
	cout << "distance Punkt" << endl;
	cout << "inny x: " << inny.getX() << " y: " << inny.getY() << endl;
	return sqrt(pow(x - inny.x, 2) + pow(y - inny.y, 2));
}

void Punkt::wyswietl(){
	cout << "(" << x << ";" << y << ")";
}
