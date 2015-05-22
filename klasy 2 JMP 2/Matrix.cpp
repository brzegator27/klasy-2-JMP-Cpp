#pragma once
#include "Matrix.h"


void Matrix::createTab(int m, int n, Complex*** tab)
{
	//if (*tab != NULL) cout << "Blad";
	if (m != 0 && n != 0)
	{
		*tab = new Complex*[m];

		for (int i = 0; i < m; i++)
			(*tab)[i] = new Complex[n];

		
		Complex default(0, 0);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				(*tab)[i][j] = default;

		//((*tab)[0][0]).print();
		
	}
	else *tab = NULL;
}

Matrix::Matrix() {}

Matrix::Matrix(int m, int n) : m(m), n(n) 
{
	createTab(m, n, &this->tab);
}

//Ponizej parsujemy takie cus(cuœ): "[1i3 2i5 3; 3 4 5; 6 7 8]"
Matrix::Matrix(string data)
{
	this->m = 0; this->n = 0;
	this->tab = NULL;

	//Usuwamy nawiasy kwadratowe:
	data = data.substr(0, data.size() - 1);
	data = data.substr(1, data.size());

	std::size_t found;
	//Sprawdzamy ile jest spacji:
	found = data.find(" ");

	while (found != std::string::npos)
	{
		this->n++;
		found = data.find(" ", found + 1);
	}

	//Sprawdzamy ile jest srednikow:
	found = data.find(";");

	while (found != std::string::npos) 
	{
		this->m++;
		found = data.find(";", found + 1);
	}

	this->m++;
	this->n = (this->n + 1) / m;

	//cout << "m: " << this->m << " n: " << this->n << endl;

	createTab(this->m, this->n, &(this->tab));

	string number_R, number_I;
	int counter_n = 0, counter_m = 0;

	while (data.size())
	{
		//ASCII space -> 32 (dec)
		if (data[0] == 32)
		{
			data = data.substr(1, data.size());
			//przechodzimy do kolejnej kolumny:
			counter_n++;
		}
		//ASCII ; -> 59 (dec)
		else if (data[0] == 59 && data[1] == 32)
		{
			data = data.substr(2, data.size());
			//przechodzimy do kolejnego wiersza:
			counter_n = 0;
			counter_m++;
		}
		else
		{
			//Pobieramy czesc realis:
			//ASCII . -> 46 (dec)
			//ASCII - -> 45 (dec)
			while ((data[0] >= 48 && data[0] <= 57) || data[0] == 46 || data[0] == 45)
			{
				number_R += data[0];
				data = data.substr(1, data.size());
			}
		
			//Pobieramy czesc imaginaria:
			//ASCII i -> 105 (dec)
			//ASCII . -> 46 (dec)
			//ASCII - -> 45 (dec)
			if (data[0] == 105)
			{
				data = data.substr(1, data.size());
				while ((data[0] >= 48 && data[0] <= 57) || data[0] == 46 || data[0] == 45)
				{
					number_I += data[0];
					data = data.substr(1, data.size());
				}
			}
			
			//Gdy nie zostala poda czesc re, lub im, to wstawiamy za nie 0:
			if (number_R.size() == 0) 
				number_R = "0";
			if (number_I.size() == 0) 
				number_I = "0";

			//Tablice mamy wypelniona zerami, wiec mozemy skorzystac z dodawania:
			((this->tab)[counter_m][counter_n]).add(stod(number_R), stod(number_I));
		}

		number_R.clear();
		number_I.clear();
	}
}

Matrix::Matrix(Matrix &matrix)
{
	//cout << "Kopiujemy: "; matrix.print_wr();
	/*((matrix.tab)[0][0]).print();
	((matrix.tab)[0][1]).print();
	((matrix.tab)[1][0]).print();
	((matrix.tab)[1][1]).print();*/

	this->m = matrix.m;
	this->n = matrix.n;
	this->tab = NULL;

	this->createTab(this->m, this->n, &(this->tab));
	
	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
		{
			(this->tab)[i][j] = (matrix.tab)[i][j]; //Complex(matrix.tab[i][j].getR, matrix.tab[i][j].getI);
			//cout << (this->tab[i][j]).getR()<<"  ";
			//(this->tab)[i][j].print();
		}
	/*matrix.print_wr();
	((matrix.tab)[0][0]).print();
	((matrix.tab)[0][1]).print();
	((matrix.tab)[1][0]).print();
	((matrix.tab)[1][1]).print();
	this->print_wr();*/
}

Matrix::~Matrix()
{
	//cout << "Usuwamy: "; this->print_wr();
	//cout << endl; this->print_wr();
	//cout << "Destruktor dla: " << this->tab[0][0].print_str() << endl;
	
	for (int i = 0; i < m; i++)
	{
		//for (int j = 0; j < n; j++)
		{
			//cout << (this->tab[i][0]).print_str() << " el \n";
			delete[] (this->tab[i]);
		}
	}

	delete[] tab;
	
}


Matrix& Matrix::operator=(const Matrix &a)
{
	//cout << a.rel << "  " << a.im << endl;
	this->m = a.m;
	this->n = a.n;
	this->tab = NULL;

	this->createTab(a.m, a.n, &(this->tab));

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
		{
			(this->tab)[i][j] = a.tab[i][j];
		}

	return *this;
}


//Ponizej wypisujemy takie cus(cuœ): "[1i3 2i5 3; 3 4 5; 6 7 8]"
void Matrix::print_wr()
{
	cout << "[";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->tab[i][j].print();
			if (j != n - 1) cout << " ";
		}
		if (i != m - 1) cout << "; ";
	}
	cout << "]" << endl;
}

string Matrix::print()
{
	//cout << this->tab[0][0].print_str();
	string data;
	data = "[";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			data += this->tab[i][j].print_str();
			if (j != n - 1) data += " ";
		}
		if (i != m - 1) data += "; ";
	}
	data += "]";

	return data;
}

Complex* Matrix::set(int m, int n, Complex value)
{
	this->tab[m][n].set(value);

	return &(this->tab[m][n]);
}

Complex* Matrix::get(int m, int n)
{
	return &(this->tab[m][n]);
}

Matrix Matrix::add(Matrix matrix)
{
	if (this->m == matrix.m && this->n == matrix.n)
	{
		Matrix newOne(matrix.m, matrix.n);

		//matrix.print_wr();
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				newOne.tab[i][j] = this->tab[i][j] + matrix.tab[i][j];

		//matrix.set(1, 1, Complex(999, 999));
		//matrix.print_wr();
		//newOne.print_wr();
		//this->print_wr();
		return newOne;
	}
	else
	{
		Matrix newOne(0, 0);
		return newOne;
	}
}

Matrix Matrix::sub(Matrix matrix)
{
	if (this->m == matrix.m && this->n == matrix.n)
	{
		Matrix newOne(matrix.m, matrix.m);

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				newOne.tab[i][j] = this->tab[i][j] - matrix.tab[i][j];

		return newOne;
	}
	else
	{
		Matrix newOne(0, 0);
		return newOne;
	}
}

Matrix Matrix::mul(Matrix matrix)
{
	if (this->n == matrix.m)
	{
		Matrix newOne(this->m, matrix.n);

		for (int i = 0; i < this->m; i++)
			for (int j = 0; j < this->n; j++)
				for (int k = 0; k < matrix.n; k++)
					newOne.tab[i][j] += this->tab[i][k] * matrix.tab[k][j];

		return newOne;
	}
	else
	{
		Matrix newOne(0, 0);
		return newOne;
	}
}
Matrix Matrix::mul(Complex number)
{
	Matrix newOne(this->m, this->n);

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			newOne.tab[i][j] = this->tab[i][j] * number;

	return newOne;
}
Matrix Matrix::div(Matrix matrix)
{
	if (this->n == matrix.m)
	{
		Matrix newOne(this->m, matrix.n);

		for (int i = 0; i < this->m; i++)
			for (int j = 0; j < this->n; j++)
				for (int k = 0; k < matrix.n; k++)
				{
					/*
					newOne.print_wr();
					cout << "1:"; newOne.tab[i][j].print(); cout << endl;
					cout << "2:"; this->tab[i][k].print(); cout << endl;
					cout << "3:"; matrix.tab[k][j].print(); cout << endl;
					cout << endl;
					*/
					newOne.tab[i][j] += this->tab[i][k] / matrix.tab[k][j];
				}

		return newOne;
	}
	else
	{
		Matrix newOne(0, 0);
		return newOne;
	}
}

Matrix Matrix::div(Complex number)
{
	Matrix newOne(this->m, this->n);

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			newOne.tab[i][j] = this->tab[i][j] / number;

	return newOne;
}

Matrix Matrix::pow(int exponent)
{
	Matrix newOne(this->m, this->n);

	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
			newOne.tab[i][j] = this->tab[i][j];

	for (int i = 0; i < exponent - 1; i++)
		newOne = newOne.mul(newOne);

	return newOne;
}
