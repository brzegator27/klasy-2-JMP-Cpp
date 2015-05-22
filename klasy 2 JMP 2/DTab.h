#include <iostream>
#include <iomanip>

using namespace std;

#pragma once
class DTab{
private:
	double * tab;
	int length;
	int last;

	// Metoda rozszerzajaca rozmiar tablicy do rozmiaru podanego jako parametr
	void resize(int newSize);
public:
	// Konstruktor bezparametrowy. Powinien tworzyæ tablicê o rozmiarze 10. (wykorzystaj metode resize)
	DTab();
	// Tworzy tablice o rozmiarze podanym jako parametr. (wykorzystaj metode resize)  
	DTab(int initLength);
	//Konstruktor kopiujacy:
	DTab(const DTab&);
	// Destruktor. Uwaga! Tablicê tworzymy dynamicznie, czyli tutaj jest wymagany!
	~DTab();

	//double operator [](int i)const{ return tab[i]; };
	double &operator[](int i){ return tab[i]; };
	DTab &operator=(const DTab&);

	friend istream& operator>>(istream &, DTab&);
	friend ostream& operator<<(ostream &, const DTab&);

	// Dodaje element do na koniec tablicy. Jeœli tablica jest za ma³a
	// rozszerza j¹. (wykorzystaj metode resize)
	void add(double element);
	// Pobiera element z tablicy z podanego indexu
	double get(int index);
	// Ustawia element o danym indeksie na dan¹ wartoœæ
	void set(double element, int index);
	// wyœwietla tablice.
	void print();
};
