#include "Dziecko.h"

#include <iostream>

using namespace std;

#pragma once
class Rodzic
{
	string imie;
	string nazwisko;
	int wiek;
	Dziecko* dziecko;

public:
	Rodzic();
	Rodzic(string imie, string nazwisko, int wiek, Dziecko* dziecko);
	~Rodzic();

	void przepiszDoInnejSzkoly(string szkola);
};

