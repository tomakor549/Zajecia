// Listy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void add_start();

struct element * head;
struct element * tail;

struct point
{
	double X, Y;
};

struct rect
{
	struct point P1, P2;
};

struct element
{
	struct rect reetangle;
	struct element * next;
};

void add_end()
{
	struct element element;
	element.reetangle.P1.X = 1;
	element.reetangle.P1.Y = 1;
	element.reetangle.P2.X = 1;
	element.reetangle.P2.Y = 1;
	
	

}
int main()
{
	head = new struct element;
	tail = head;
	head->next = nullptr;
	struct element element;
	element.reetangle.P1.X = 1;
	element.reetangle.P1.Y = 1;
	element.reetangle.P2.X = 1;
	element.reetangle.P2.Y = 1;

	add_start();
	return 0;
}

void add_start()
{

}

