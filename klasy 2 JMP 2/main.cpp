#include "complex.h"
#include "Punkt.h"
#include "DTab.h"
#include "MyList.h"
#include "Dziecko.h"
#include "Rodzic.h"
#include "Marsjanin.h"
#include "Matrix.h"
#include "Punkt3D.h"

#include <iostream>
#include <list>

using namespace std;

int Marsjanin::quantity = 0;

DTab wypelniona(int wypelnienie)
{
	DTab tab(10);

	for (int i = 0; i < 10; i++)
		tab.add(wypelnienie);

	tab.print();

	return tab;
}

int main()
{
	//Zadanie 2:
	Punkt3D* punkt3D_1 = new Punkt3D();
	delete punkt3D_1;

	//Zadanie 3:
	Punkt3D punkt3D_2(0, 0, 0);
	Punkt punkt2D_2(1, 1);

	//punkt2d.distance(punkt3d)
	cout << punkt2D_2.distance(punkt3D_2) << endl;
	//punkt3D_2 zosta³ zrzutowany na obiekt klasy Punkt

	//Zadanie 4:
	Punkt3D p3d(1, 2, 3);
	cout << p3d << endl;
	//p3d zosta³ zrzutowany na obiekt klasy Punkt



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	
	/*
	Punkt punkt1(1.12, 2.1231);

	cin >> punkt1;
	cout << punkt1;
	*/

	/*
	DTab tablica21(10);
	tablica21.add(1);
	tablica21.add(2);
	tablica21.add(3);
	tablica21.add(4);
	tablica21.add(5);

	tablica21[2] = 100;

	cout << endl << tablica21[2];

	DTab tablica22(2);
	tablica22 = tablica21;

	cout << endl << tablica22[1];
	cout << endl << tablica22[2];
	cin >> tablica22;
	cout << endl << tablica22;

	cin >> tablica22;
	cout << endl << tablica22;
	*/

	/*
	DTab tablica23(10);
	cin >> tablica23;
	cout << tablica23;
	*/

	/*
	Complex c(5, 3);//c("5i3");
	Matrix nowa = (Matrix)c;
	//nowa = c;

	nowa.print();
	*/


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	//Zadanie 1:
	/*
	Punkt p1(1, 2);
	Punkt p2 = p1;

	p1 = p2;
	*/

	//Zadanie 2:
	/*
	DTab tab = wypelniona(1);
	tab.print();				//nie wypisuje wartosci, ktorymi zostala wypelniona, gdy nie ma konstruktora kopiuj¹cego
	tab.add(12);
	tab.add(11);
	tab.print();
	*/
	
	//Zadanie 3:
	/*
	MyList lista;

	lista.add("1");
	lista.print();
	lista.add("2");
	lista.print();
	lista.add("3");
	lista.print();
	lista.add("4");
	lista.add("5");
	lista.add("6");
	lista.print();
	lista.del(5);
	lista.print();

	//Testujemy konstruktor kopiujacy dla listy:
	MyList lista2 = lista;
	lista2.print();
	*/

	//Zadanie 4:
	/*
	Dziecko dziecko("Kuba", "B.", 15, "Szkola 1");
	Rodzic rodzic("M.", "B.", 55, &dziecko);
	*/


	//Zadanie 5:
	/*
	int choice;
	int number = 0;
	list<Marsjanin*> listaM;
	list<Marsjanin*> listaM_temp;
	Marsjanin* element;
	while (true)
	{
		std::cout << "Dodaj/odejmij -> 1/0:  ";
		cin >> choice;

		if (choice)
		{
			listaM.push_back((new Marsjanin(number)));
		}
		else
		{
			if (Marsjanin::quantity > 0)
			{
				listaM.pop_back();
				Marsjanin::quantity--;
			}
		}

		if (Marsjanin::quantity > 5)
		{
			listaM_temp = listaM;

			while (listaM_temp.size() > 0)
			{
				element = listaM_temp.back();
				element->atakuj();
				listaM_temp.pop_back();
			}
		}

		number++;
		std::cout << endl;
	}
	*/


	//Zadanie 6:
	/*
	Matrix tablica_C("[1.2i3 2i5.423 3; 3 4 5; 6 7 8]");
	tablica_C.print_wr();
	
	
	Matrix m1("[1 2; 1 1]");
	Matrix m2("[6 7; 3 5]");
	//m1.print_wr();
	//m2.print_wr();

	//cout << "tutaj";

	//cout << "Macierz pierwsza: " << m1.print() << endl;
	//cout << "Macierz druga: " << m2.print() << endl;

	cout << "Dodawanie: \t" << (m1.add(m2)).print() << endl;
	cout << "Odejmowanie: \t" << (m1.sub(m2)).print() << endl;
	cout << "Mnozenie: \t" << (m1.mul(m2)).print() << endl;
	cout << "Dzielenie: \t" << (m1.div(m2)).print() << endl;
	cout << "Potegowanie: \t" << (m1.pow(2)).print() << endl;
	cout << "Potegowanie: \t" << (m2.pow(1)).print() << endl;
	*/
	
	/*
	DTab tablica(2);
	tablica.add(22);
	tablica.add(23);
	tablica.add(24);
	tablica.add(22);
	tablica.add(23);
	tablica.add(24);
	tablica.set(12, 2);
	tablica.print();

	std::cout << endl << endl;

	Complex zespolona(1, 1);
	zespolona.print();
	zespolona.add(1, 2);
	zespolona.print();
	zespolona.sub(0, 1);
	zespolona.print();
	zespolona.mul(1, 1);
	zespolona.print();
	zespolona.div(1, 1);
	zespolona.print();
	*/

	getchar();
	getchar();
	return 0;
}