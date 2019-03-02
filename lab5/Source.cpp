#include "..\Header\Polinom.h"


int main() 
{	
	//Тестовый мейн для полинома
	setlocale(LC_ALL, "Russian");
	TMonom monom1, monom2;
	TPolinom p,q;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = -2;
	monom2.PowX = 2;
	monom2.PowY = 3;
	monom2.PowZ = 6;
	p.InsMonom(monom1);
	q.InsMonom(monom2);
	p += q;
	cout << p;
	system("pause");

}
