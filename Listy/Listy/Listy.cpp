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
	//yo
	std::string nazwa;
	int number;
	struct dane * next;
	struct dane * previous;
};

void add_dane_head(int inf)
{
	struct dane *element;
	element = new struct dane;

	element->next = head;
	element->previous = nullptr;
	element->number = inf;
	head = element;
}


void add_dane_tail(int inf)
{
	struct dane *element;
	element = new struct dane;

	tail->next = element;
	element->previous = tail;
	element->number = inf;
	tail = element;
}


void add_dane_middle(int inf, int zamiana)
{
	struct dane *element;
	element = new struct dane;
	struct dane *help;
	help = head;
	for (int i = 1; i < zamiana; i++)
	{
		help = help->next;
	}
	element->next = help->next;
	element->previous = help;
	element->number = inf;
	help->next = element;
	element->next->previous = element;
}

void wypisz(unsigned int licznik)
{

	struct dane *help;
	help = new struct dane;
	help = head;
	for (int i = 0; i < licznik; i++)
	{
		cout << help->number << "\t";
		help = help->next;
	}
	cout << endl;
	delete help;
}

int main()
{
	unsigned int licznik = 0;
	int choise;
	int inf;
	std::string nazwa;

	cout << "Wybierz opcje (niepoprawna liczba koczy petle)" << endl;
	do
	{
		if (licznik == 0)
		{
			cout << "Listy nie ma, stworz pierwszy element." << endl;
			cout << "Nazwa elementu: ";
			getline(cin, nazwa);
			struct dane *element;
			element = new struct dane;

			element->next = nullptr;
			element->previous = nullptr;
			element->number = inf;

			tail = element;
			head = tail;
			licznik++;
		}
		else
		{

			cout << "1 - Dodaj dane na poczatek" << endl;
			cout << "2 - Dodaj dane na koniec" << endl;
			cout << "3 - Dodaj dane do środka listy" << endl;
			cout << "4 - wypisz liste" << endl;
			cin >> choise;

			switch (choise)
			{
			case 1:
				cout << "Wybierz wartosc" << endl;
				cin >> inf;
				add_dane_head(inf);
				licznik++;
				break;
			case 2:
				cout << "Wybierz wartosc" << endl;
				cin >> inf;
				add_dane_tail(inf);
				licznik++;
				break;
			case 3:
				int ktory_element;
				cout << "Po jakim elemencie listy chcesz wstawic: ";
				cin >> ktory_element;
				cout << "Wybierz wartosc" << endl;
				cin >> inf;
				if (ktory_element > 0)
				{
					if (ktory_element < licznik)
					{
						add_dane_middle(inf, ktory_element);
						licznik++;
					}
					else
						cout << "Blad";
				}
				else
					cout << "Blad";
				break;
			case 4:
				wypisz(licznik);
				break;
			default:
				choise = 0;
				break;
			}
		}
		cout << endl;
	} while (choise);

	delete head;
	delete tail;

	return 0;
}