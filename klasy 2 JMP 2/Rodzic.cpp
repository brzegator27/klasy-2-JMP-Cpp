#include "Rodzic.h"


Rodzic::Rodzic()
{
	Dziecko* dziecko = new Dziecko;
	Rodzic("", "", 0, dziecko);
}

Rodzic::Rodzic(string imie, string nazwisko, int wiek, Dziecko* dziecko) : imie(imie), nazwisko(nazwisko), wiek(wiek), dziecko(dziecko) {}

Rodzic::~Rodzic() {}

void Rodzic::przepiszDoInnejSzkoly(string szkola)
{
	this->dziecko->szkola = szkola;
}