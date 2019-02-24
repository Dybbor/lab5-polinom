#include "Monom.h"
using namespace std;
void main() 
{
	setlocale(LC_ALL, "rus");
	TMonom a;
	while (1)
	{
		system("cls");
		cin >> a;
		cout << "Вы ввели моном :";
		PrintMonom(a);
		system("pause");
	}
	
	/*TMonom m1;
	m1.coeff = 2;
	m1.PowX = 2;
	m1.PowY = 1;
	m1.PowZ = 5;
	TMonom m2;
	m2.coeff = 2;
	m2.PowX = 2;
	m2.PowY = 1;
	m2.PowZ = 5;
	cout << (m1 == m2) << endl;
	cout << "Hello, world!" << endl;
	m2.PowZ = 4;
	cout << (m1 != m2) << endl;*/

	//THeadList <int> a;
	//for (int i = 2; i >= 0; i--)
	//	a.InsFirst(i);
	//a.PrintList();
	system("pause");
}