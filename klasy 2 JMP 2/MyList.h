#include "MyNode.h"

#pragma once
class MyList
{
	MyNode* node;
	int length;

public:
	MyList();
	MyList(const MyList&);
	~MyList();

	bool add(string value);
	bool del(int index);
	MyNode* find(int index);
	void print();
};

