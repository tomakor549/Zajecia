// Egzamin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream plik;
	plik.open("nowy.txt");
	if (!plik.good())
	{
		return 0;
	}

	ofstream plik2;
	plik2.open("wynik.txt");

	string a;
	string b;
	unsigned int la;
	unsigned int lb;
	bool help;

	while (!plik.eof())
	{
		help = false;
		plik >> a >> b;
		if (a == "")
			break;
		la = a.length();
		lb = b.length();
		if (la <= lb)		//bo jesli 1 el. (a) jest dluzszy od drugiego, to na pewno nie bedzie zawarty w drugim 
		{
			int j = 0;
			for (int i = 0; i < lb; i++)
			{
				if (a[j] == b[i])
				{
					j++;
					if (j == la)
					{
						plik2 << "true" << endl;
						help = true;
						break;
					}
				}
				else
					j = 0;
			}
			if (help != true)
				plik2 << "false" << endl;

		}
		else
			plik2 << "false" << endl;
	}

	plik.close();
	plik2.close();
	return 0;
}

