#include "Dziecko.h"



Dziecko::Dziecko()
{
	Dziecko("", "", 0, "");
}

Dziecko::Dziecko(string imie, string nazwisko, int wiek, string szkola) : imie(imie), nazwisko(nazwisko), wiek(wiek), szkola(szkola) {}

Dziecko::~Dziecko()
{
}
