#include <iostream>

using namespace std;

#pragma once
class MyNode
{
	friend class MyList;

private:
	string value;
	MyNode* node;

public:
	MyNode();
	//http://pl.wikipedia.org/wiki/This_%28programowanie_obiektowe%29
	//MyNode() { this("");}
	MyNode(string value);
	//MyNode(const MyNode&);
	~MyNode();
};

