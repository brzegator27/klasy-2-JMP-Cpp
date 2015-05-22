#include <iostream>

using namespace std;

#pragma once
class Dziecko
{
	friend class Rodzic;

	string imie;
	string nazwisko;
	int wiek;
	string szkola;

public:
	Dziecko();
	Dziecko(string imie, string nazwisko, int wiek, string szkola);
	~Dziecko();
};

