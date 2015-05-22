#include "MyList.h"
#include "MyNode.h"

#include <iostream>
#include <string>

using namespace std;

MyList::MyList()
{
	this->length = 0;
	this->node = NULL;
}


MyList::~MyList()
{
	MyNode* temp = this->node;
	MyNode* temp_2;

	while (temp != NULL)
	{
		temp_2 = temp;
		temp = temp->node;
		delete temp_2;
	}
}

MyList::MyList(const MyList &list)
{
	this->length = 0;
	this->node = NULL;

	MyNode* temp = list.node;

	while (temp != NULL)
	{
		this->add(temp->value);
		temp = temp->node;
	}

	this->length = list.length;

	cout << "Konstruktor kopiujacy!" << endl;
}


bool MyList::add(string value)
{
	MyNode* temp = this->node;
	
	if (temp != NULL)
	{
		while (temp->node != NULL) 
			temp = temp->node;

		//Mamy juz ostatni element, wiec dodajemy kolejny:
		temp->node = new MyNode;
		temp->node->value = value;
		temp->node->node = NULL;
	}
	else
	{
		this->node = new MyNode;
		this->node->value = value;
		this->node->node = NULL;
	}

	this->length++;

	return true;
}

bool MyList::del(int index)
{
	if (index < length)
	{
		MyNode* temp;
		MyNode* preceding = this->node;

		//Zaczynamy od 1, bo u gory mamy juz element o indeksie 0
		//i dodatkowo szukamy elementu poprzedzajacego ten do usuniecia
		for (int i = 1; i < index; i++)
			preceding = preceding->node;

		temp = preceding->node;

		preceding->node = temp->node;
		delete temp;

		return true;
	}

	return false;
}


MyNode* MyList::find(int index)
{
	MyNode* temp = this->node;
	
	if (index < length)
	{
		for (int i = 0; i < index; i++)
			temp = temp->node;
	}
	else return NULL;

	return temp;
}

void MyList::print()
{
	MyNode* temp = this->node;

	if (temp != NULL)
	{
		while (temp != NULL)
		{
			cout << temp->value << "  ";
			temp = temp->node;
		}

		cout << endl;
	}
}
