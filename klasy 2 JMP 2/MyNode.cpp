#include "MyNode.h"

#include <iostream>

using namespace std;


MyNode::MyNode(string value)
{
	this->node = NULL;
	this->value = value;
}

MyNode::MyNode()
{
	MyNode(""); 
}

/*
MyNode::MyNode(const MyNode &node);
{

}
*/

MyNode::~MyNode()
{
}


