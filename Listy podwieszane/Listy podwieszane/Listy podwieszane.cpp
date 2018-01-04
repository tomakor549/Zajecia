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
	int number;
	struct dane * next;
	struct dane * previous;
};

struct dane * add_dane_head(int inf, struct dane *head, std::string nazwa)
{
	struct dane *element;
	element = new struct dane;

	element->next = head;
	element->previous = nullptr;
	element->number = inf;
	element->nazwa = nazwa;
	head = element;

	return head;
}


struct dane * add_dane_tail(int inf, struct dane *tail, std::string nazwa)
{
	struct dane *element;
	element = new struct dane;

	tail->next = element;
	element->previous = tail;
	element->number = inf;
	element->nazwa = nazwa;
	tail = element;
	return tail;
}


void add_dane_middle(int inf, int zamiana, struct dane *head, std::string nazwa)
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
	element->nazwa = nazwa;
	help->next = element;
	element->next->previous = element;
	delete help;
}


void dodaj_do_istniejącej(struct dane *head, std::string nazwa, int inf)
{

	struct dane *help;
	help = head;
	while (help!=nullptr)
	{
		if (help->nazwa == help->next->nazwa)
		{
			struct dane *element;
			element = new struct dane;

		}
		help = help->next;
	}
	cout << endl;
	delete help;
}

void wypisz(struct dane *head)
{
	struct dane *help;
	help = head;
	while (help != nullptr)
	{
		cout << help->nazwa << " " << help->number << endl;
		help = help->next;
	}
	cout << endl;
	delete help;
}

int main()
{
	int inf;
	std::string nazwa;
	struct dane *head;
	struct dane *tail;
	int choise;
	int licznik = 0;

	do
	{
		cout << "nazwa ";
		getline(cin, nazwa);
		cout << "numer ";
		cin >> inf;
		add_dane_head(inf, head, nazwa);
	} while (choise == 0);

	cout << "nazwa ";
	getline(cin, nazwa);
	cout << "numer ";
	cin >> inf;
	dodaj_do_istniejącej(head, nazwa, inf);
}

