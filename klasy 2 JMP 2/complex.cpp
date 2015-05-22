#pragma once
#include "complex.h"

#pragma once
#include "Matrix.h"

#include <iostream>
#include <sstream>

using namespace std;

Complex::Complex()
{
	this->rel = 0;
	this->im = 0;
}

Complex::Complex(double a, double b)
{
	this->rel = a;
	this->im = b;
}

Complex::operator Matrix() const
{
	return Matrix(print_str_tab());
}

Complex& Complex::operator=(const Complex &a)
{
	//cout << a.rel << "  " << a.im << endl;
	this->rel = a.rel;
	this->im = a.im;
	return *this;
}

Complex Complex::operator+(const Complex &a)
{
	return Complex(this->rel + a.getR(), this->im + a.getI());
}

Complex& Complex::operator+=(const Complex &a)
{
	this->rel += a.rel;
	this->im += a.im;
	return *this;
}

Complex Complex::operator-(const Complex &a)
{
	return Complex(this->rel - a.getR(), this->im - a.getI());
}

Complex Complex::operator*(const Complex &a)
{
	Complex toReturn(this->rel, this->im);
	toReturn.mul(a.rel, a.im);
	return toReturn;
}

Complex Complex::operator/(const Complex &a)
{
	Complex toReturn(this->rel, this->im);
	toReturn.div(a.rel, a.im);
	return toReturn;
}

void Complex::set(double c, double d)
{
	this->rel = c;
	this->im = d;
}

void Complex::set(Complex a)
{
	this->rel = a.rel;
	this->im = a.rel;
}

void Complex::add(double c, double d)
{
	this->rel += c;
	this->im += d;
}

void Complex::sub(double c, double d)
{
	this->rel -= c;
	this->im -= d;
}

void Complex::mul(double c, double d)
{
	double pomocnicza = this->rel;
	this->rel = this->rel * c - this->im * d;
	this->im = this->im * c + pomocnicza * d;

	/*
	a.r=(r*a2.r)-(i*a2.i);
	a.i=(r*a2.i)+(i*a2.r);
	*/
}

void Complex::div(double c, double d)
{
	double pomocnicza = this->rel;
	if (c == 0 && d == 0) this->rel = 0;
	else this->rel = ((this->rel * c) + (this->im * d)) / ((c * c) + (d * d));

	if (d == 0) this->im = 0;
	else this->im = ((this->im * c) + (pomocnicza * d)) / ((c * d) + (d * d));	

	/*
	a.r=((r*a2.r)+(i*a2.i))/((a2.r*a2.r)+(a2.i*a2.i));
	a.i=((i*a2.r)-(r*a2.i))/((a2.r*a2.r)+(a2.i*a2.i));
	*/
}

void Complex::pow(int c)
{
	mul(this->rel, this->im);
}

void Complex::print()
{
	if (this->rel != 0)
		cout << this->rel;
	if (this->im != 0) 
		cout << "i" << this->im;
	if (this->rel == 0 && this->im == 0)
		cout << "0";
}

string Complex::print_str()
{
	string number_s;
	number_s.clear();

	ostringstream doubleToStr;

	if (this->rel != 0)
	{
		doubleToStr << this->rel;
		number_s += doubleToStr.str();
	}

	doubleToStr.clear();

	if (this->im != 0)
	{
		doubleToStr << this->im;
		number_s += doubleToStr.str();
	}

	if (this->rel == 0 && this->im == 0)
		number_s += "0";

	return number_s;
}

string Complex::print_str_tab() const
{
	string number_s;
	number_s.clear();

	ostringstream doubleToStr;

	number_s += '[';

	if (this->rel != 0)
	{
		doubleToStr << this->rel;
		number_s += doubleToStr.str();
	}

	doubleToStr.clear();

	if (this->im != 0)
	{
		doubleToStr << this->im;
		number_s += doubleToStr.str();
	}

	if (this->rel == 0 && this->im == 0)
		number_s += "0";

	number_s += ']';

	return number_s;
}
