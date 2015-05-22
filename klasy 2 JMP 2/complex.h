#include <iostream>
#include <string>

using namespace std;

//#pragma once
//#include "Matrix.h"

class Matrix;

#pragma once
class Complex{
private:
	double rel, im;
public:
	//Konstruktor bezparametrowy
	Complex();
	//Konstruktor parametrowy
	Complex(double a, double b);

	Complex &operator =(const Complex&);
	Complex operator +(const Complex&);
	Complex &operator +=(const Complex&);
	Complex operator -(const Complex&);
	Complex operator *(const Complex&);
	Complex operator /(const Complex&);

	operator Matrix() const;
	//operator Matrix();
	//operator Matrix*();

	void nothing(Matrix a);

	double getR() const { return this->rel; };
	double getI() const { return this->im; };
	void set(double c, double d);
	void set(Complex a);
	void add(double c, double d);
	void sub(double c, double d);
	void mul(double c, double d);
	void div(double c, double d);
	void pow(int c);
	void print();
	string print_str();
	string print_str_tab() const;
};

