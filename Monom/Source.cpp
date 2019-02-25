#define _CRT_SECURE_NO_WARNINGS
#include "Monom.h"

using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	TMonom a;
	while (1)
	{
		system("cls");
		cin >> a;
		wcout << "Monom: ";
		PrintMonom(a);
		system("pause");
	}
}
