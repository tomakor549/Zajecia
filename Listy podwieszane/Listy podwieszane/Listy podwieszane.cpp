// Listy podwieszane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct element
{
	std::string nazwa;
	int number;
	struct element * next;
	struct element * previous;
	struct podelement *down;
};

struct podelement
{
	std::string nazwa;
	int number;
	struct podelement * next;
};

struct element * add_dane(struct element *head, int inf, std::string nazwa)
{
	struct element *glowne;
	glowne = head;
	bool decision;

	while(glowne->next == nullptr)
	{
		if (glowne->nazwa == nazwa)
		{
			struct podelement *element;
			element = new struct podelement;
			struct podelement *poboczne;
			poboczne;

			poboczne = glowne->down;
			while (poboczne->next == nullptr)
			{
				poboczne = poboczne->next;
			}
			poboczne->next = element;
			element->next = nullptr;
			element->nazwa = nazwa;
			element->number = inf;
			decision = false;
			break;
		}
		else
			decision = true;

		glowne = glowne->next;
	}
	if (decision)
	{
		add_list();
	}
}


int main()
{
	int inf;
	std::string nazwa;
	struct element *head;
	struct element *tail;
	int choise;
	int licznik = 0;

	do
	{
		cout << "nazwa ";
		getline(cin, nazwa);
		cout << "liczba ";
		cin >> inf;
		add_dane(head, inf, nazwa);
		system("cls");
	} while (choise == 0);

	cout << "nazwa ";
	getline(cin, nazwa);
	cout << "numer ";
	cin >> inf;
	dodaj_do_istniejącej(head, nazwa, inf);
}

