// Listy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct element * head;
struct element * tail;


struct element
{
	int data;
	struct element * next;
};

void add_end()
{

	struct element *element;
	element = new struct element;

	element->data = 5;
	
	tail->next = element;
	tail = element;
	element->next = nullptr;
}

void add_start()
{
	struct element *element;
	element = new struct element;

	element->data = 3;

	head->next = element;
	head = element;
}

void add()
{

}

int main()
{


	struct element *element;
	element = new struct element;

	element->data = 5;
	element->next = nullptr;

	head = element;
	tail = head;

	add_end();
	add_start();

	return 0;
}

