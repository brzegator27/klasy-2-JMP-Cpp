#include "DTab.h"

#include <iostream>

using namespace std;


void DTab::resize(int newSize)
{
	//Tworzymy nowa tablice:
	double* nowa = new double[newSize];

	if (this->tab != NULL)
	{
		//Przepisujemy stara tablice do nowej
		for (int i = 0; i < this->length; i++)
		{
			nowa[i] = this->tab[i];
		}

		delete[](this->tab);
	}
	else
	{
		for (int i = 0; i < newSize; i++)
		{
			nowa[i] = NULL;
		}

		this->last = 0;
	}

	this->tab = nowa;
	this->length = newSize;
	length = newSize;
}

DTab::DTab() :length(10), last(0)
{
	this->tab = NULL;
	resize(10);
}

DTab::DTab(int initLength) : last(0)
{
	this->tab = NULL;
	resize(initLength);
}

DTab::DTab(const DTab &tab)
{
	this->tab = NULL;
	this->resize(tab.length);

	for (int i = 0; i < tab.last; i++)
		this->tab[i] = tab.tab[i];

	this->last = tab.last;

	cout << "Konstruktor kopiujacy!" << endl;
}

DTab::~DTab()
{
	delete[](this->tab);
}

DTab& DTab::operator=(const DTab &a)
{
	//Zmieniamy rozmiar tablicy
	this->resize(a.length);

	//Przepisujemy tablice:
	for (int i = 0; i < a.length; i++)
		this->tab[i] = a.tab[i];

	this->last = a.last;

	return *this;
}

istream& operator>>(istream & input, DTab& tab)
{
	double pomocnicza = 0;
	int zm = 1;

	//Ignorujemy nawias kwadratowy
	input.ignore();
	
	int i = 0;
	//ASCII ] -> 93
	while (input.peek() != 93){
 		input >> tab[i++];
		//tab.add(pomocnicza);
		//ignorujemy przecinek, lub pod koniec bêdzie to ostatni nawias kwadratowy
		if (input.peek() != 93) input.ignore();
	}

	return input;
}

ostream& operator<<(ostream & output, const DTab& tab)
{
	output << "[";
	for (int i = 0; i < tab.last; i++)
	{
		output << tab.tab[i];
		if (i < tab.last - 1) output << ",";
	}
	output << "]";

	return output;
}

void DTab::add(double liczba)
{
	if (last == length)
	{
		//Za malo miejsca wiêc dodajemy:
		resize(length + 1);
	}

	this->tab[(this->last)++] = liczba;
}

double DTab::get(int index)
{
	if (index < this->length)
	{
		return this->tab[index - 1];
	}
	else return 0;
}

void DTab::set(double element, int index)
{
	if (index < this->length)
	{
		this->tab[index - 1] = element;
	}
}

void DTab::print()
{
	for (int i = 0; i < this->last; i++)
	{
		cout << this->tab[i] << " ";
	}

	cout << endl;
}

