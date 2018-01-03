// Listy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct dane *head;
struct dane *tail;

struct dane
{
	int number;
	struct dane * next;
};

void add_dane_head(int inf)
{
	struct dane *element;
	element = new struct dane;

		element->next = head;
		element->number = inf;
		head = element;
}

/*
void add_dane_tail(unsigned int licznik, int inf)
{
	struct dane *element;
	element = new struct dane;

	if (licznik > 0)
	{
		element->next = tail;
		element->number = inf;

		head = element;
		licznik++;
	}
}

void add_dane_middle(unsigned int licznik)
{
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
*/

int main()
{
	unsigned int licznik = 0;
	int choise = 0;
	int inf;

	cout << "Wybierz opcję" << endl;
	do
	{
		cout << "1 - Dodaj dane na poczatek" << endl;
		cout << "2 - Dodaj dane na koniec" << endl;
		cin >> choise;
		cout << "Wybierz wartosc" << endl;
		cin >> inf;

		if (licznik == 0)
		{
			struct dane *element;
			element = new struct dane;

			element->next = nullptr;
			element->number = inf;

			tail = element;
			head = tail;
			licznik++;
		}
		switch (choise)
		{
		case 1:
			add_dane_head(inf);
				licznik++;
			break;
		default:
			choise = 0;
			break;
		}
	} while (choise);

	struct dane *element;
	element = new struct dane;
	struct dane *help;
	help = head;
	for (int i = 0; i < licznik; i++)
	{
		cout << help->number << endl;
		help = help->next;
	}

	return 0;
}