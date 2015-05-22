#pragma once
#include "complex.h"

#include <iostream>
#include <string>

using namespace std;

#pragma once
class Matrix
{
	Complex** tab;
	int m, n;

	//Complex** createTab(int m, int n);
	void createTab(int m, int n, Complex*** tab);
public:
	Matrix();
	Matrix(int m, int n);
	Matrix(string data);
	Matrix(Matrix&);
	~Matrix();

	Matrix &operator =(const Matrix&);

	//operator Complex() const;

	void print_wr();
	string print();

	Complex* set(int m, int n, Complex value);
	Complex* get(int m, int n);

	Matrix add(Matrix matrix);
	Matrix sub(Matrix matrix);
	Matrix mul(Matrix matrix);
	Matrix mul(Complex number);
	Matrix div(Matrix matrix);
	Matrix div(Complex number);
	Matrix pow(int exponent);
};

