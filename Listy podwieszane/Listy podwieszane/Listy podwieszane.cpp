// Listy podwieszane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct dane
{
	std::string nazwa;
	float number;
	struct dane * next;
	struct dane * previous;
	struct dane *down;
};

struct dane * add_dane(struct dane *head, int inf, std::string nazwa)
{
	struct dane *pomoc;
	pomoc = head;
	bool decision;

	if (head->number > inf)
	{
		struct dane *element;
		element = new struct dane;
		element->next = pomoc;
		element->previous = nullptr;
		pomoc->previous = element;
		element->down = nullptr;
	}

	while(pomoc->next != nullptr)
	{
		if (pomoc->number < inf)
		{
			if (pomoc->next != nullptr)
			{
				if (pomoc->next->number > inf)
				{
					struct dane *element;
					element = new struct dane;
					element->nazwa = nazwa;
					element->number = inf;

					element->next = pomoc->next;
					element->previous = pomoc->next->previous;
					pomoc->next->previous = element;
					pomoc->next = element;
					element->down = nullptr;
				}
			}
			else
			{
				struct dane *element;
				element = new struct dane;
				element->nazwa = nazwa;
				element->number = inf;

				element->next = nullptr;
				element->previous = pomoc;
				pomoc->next = element;
				element->down = nullptr;
			}	
		}
		if (pomoc->number == inf)
		{
			struct dane *element;
			element = new struct dane;
			element->nazwa = nazwa;
			element->number = inf;
			struct dane *new_pomoc;
			new_pomoc = pomoc;

			while (new_pomoc->down != nullptr)
			{
				new_pomoc = new_pomoc->down;
			}
			new_pomoc->down = element;
			element->down = nullptr;
			element->next = nullptr;
			element->previous = nullptr;
		}
		pomoc = pomoc->next;
	}
	return(head);
}

void wypisz(struct dane *head)
{
	while (head != nullptr)
	{
		if (head->down == nullptr)
		{
			cout << head->number << endl;
		}
		else
		{
			struct dane *pomoc;
			pomoc = head;
			while (pomoc->down != nullptr)
			{
				cout << pomoc->nazwa << "\t";
				pomoc = pomoc->next;
			}
			cout << endl;
		}
		head = head->next;
	}
}

int main()
{
	std::string nazwa;
	int inf;
	struct dane *head=nullptr;
	int choise;
	int licznik = 0;

	do
	{
		cout << "0-dodaj dane, inna liczba, zakończ";
		cin >> choise;
		if (choise != 0)
			break;
		cout << "nazwa" << endl;
		cin >> nazwa;
		cout << "liczba ";
		cin >> inf;
		head = add_dane(head, inf, nazwa);
		system("cls");
	} while (true);

	wypisz(head);

	return 0;
}

