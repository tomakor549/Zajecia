// Testy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	using namespace std;
	int tab7[3][2] = { { 33, 93 },{ -103, 903 } };
	int tab8[3][2] = { 3, 5, 7, 13 };
	tab7[0][0] = 1000;
	tab8[1][1] = tab7[1][0];
	cout << tab7[1][0] << '\t' << tab8[1][1] << endl;
	return 0;
}

