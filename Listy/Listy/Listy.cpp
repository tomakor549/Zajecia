// Listy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct dane * head;
struct dane * tail;

struct dane
{
	int number;
	struct dane * next;
};

void add_dane(unsigned int licznik)
{
	if (licznik == 0)
	{

	}
		struct dane *element;
		element = new struct dane;

		element->next = nullptr;
		element->number = 2;

		head = element;
		tail = head;
		licznik++;

		if (licznik == 1)
		{

			//na początek
			struct dane *element;
			element = new struct dane;
			element->next = head;
			element->number = 1;

			head = element;
			licznik++;

		}
		if (licznik == 2)
		{
			//na koniec
			struct dane *element;
			element = new struct dane;
			element->next = nullptr;
			element->number = 4;

			tail->next = element;
			tail = element;
			licznik++;
		}

		if (licznik == 3)
		{
			//po środku
			struct dane *element;
			element = new struct dane;
			struct dane *help;
			help = head;
			for (unsigned int i = 0; i < licznik; i++)
			{
				if (help->number == 2)
				{
					element->next = help->next;
					element->number = 3;
					help->next = element;
					break;
				}
				help = help->next;
			}

		}

}



int main()
{
	unsigned int licznik = 0;
	 add_dane(licznik);

	return 0;
}




/*
void add_end()
{

struct dane *element;
element = new struct dane;

element->data = 5;

tail->next = element;
tail = element;
element->next = nullptr;
}

void add_start()
{
struct dane *element;
element = new struct dane;

element->data = 3;

head->next = element;
head = element;
}

void add()
{

}
*/