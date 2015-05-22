#include <iostream>

using namespace std;

#pragma once
class Marsjanin
{
	int number;

public:
	Marsjanin();
	Marsjanin(int number);
	~Marsjanin();

	void atakuj();

	static int quantity;
};

