/*Данный заголовочный файл пока отбрасывается в мусорку 
из за проблем выведения степени и постоянных конфликтов потоков вывода
Может быть в будущем переделается и соберется в нормальный проект,  но это не точно*/
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <stdexcept>

using namespace std;
struct TMonom 
{
	double coeff; //Коэффициент при мономе
	int PowX, PowY, PowZ; //Степени x,y,z
};
int CountNumber(int number)  //Количество цифр в числе
{
	int count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return count;
}
int PowNumber(int count) 
{
	int a = 1;
	count--;
	while (count != 0) 
	{
		a *= 10;
		count--;
	}
	return a;
}

bool operator==(const TMonom &m1, const TMonom &m2) 
{
	return (m1.PowX == m2.PowX && m1.PowY == m2.PowY && m1.PowZ == m2.PowZ);
}

bool operator!=(const TMonom &m1, const TMonom &m2)
{
	return (m1.PowX != m2.PowX || m1.PowY != m2.PowY || m1.PowZ != m2.PowZ);
}

bool operator>(const TMonom &m1, const TMonom &m2)
{
	if (m1.PowX > m2.PowX)
		return true;
	else
		if (m1.PowX == m2.PowX && m1.PowY > m2.PowY)
			return true;
		else
			if (m1.PowY == m2.PowY && m1.PowZ > m2.PowZ)
				return true;
			else
				return false;
}

bool operator<(const TMonom &m1, const TMonom &m2)
{
	return !(m1 > m2);
}

wchar_t digitToSuperscript(unsigned int digit) //Нахождение кода степени в таблице Unicode
{
	//if (digit >= 10)
	//	throw std::out_of_range("digit");
	switch (digit)
	{
	case 1:
		return 0x00B9;
	case 2:
		return 0x00B2;
	case 3:
		return 0x00B3;
	default:
		return 0x2070 + digit;
	}
}
void PrintPow(int pow)  //Печать степени
{
	int intPart, count, del;
	intPart = pow;
	count = CountNumber(intPart);
	while (count != 0)
	{
		del = PowNumber(CountNumber(intPart));
		wcout << digitToSuperscript(intPart / del);
		while (CountNumber(intPart % del) != count - 1 && count != 0)
		{
			wcout << digitToSuperscript(0);
			count--;
		}
		intPart %= del;
		count--;
	}
}
void PrintMonom(TMonom &m) 
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	/*_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);*/
	if (m.coeff != 0)
	{
		if (m.PowX == 0 && m.PowY == 0 && m.PowZ == 0)
			wcout << m.coeff;
		else
		{
			if (m.coeff != 1)
				wcout << m.coeff;
			if (m.PowX != 0)
			{
				wcout << L"x";
				if (m.PowX != 1)
					PrintPow(m.PowX);
			}
			if (m.PowY != 0)
			{
				wcout << L"y";
				if (m.PowY != 1)
					PrintPow(m.PowY);
			}
			if (m.PowZ != 0)
			{
				wcout << L"z";
				if (m.PowZ != 1)
					PrintPow(m.PowZ);
			}
		}
	}
}
istream &operator>>(istream &istr, TMonom &m)
{
	int coeff, x, y, z;
	istr >> coeff >> x >> y >> z;
	if (x < 0 || y < 0 || z < 0 || coeff==0)
		throw - 1;
	m.PowX = x;
	m.PowY = y;
	m.PowZ = z;
	m.coeff = coeff;
	return istr;
}
ostream& operator<<(ostream &ostr, const TMonom &m) 
{
	if (m.coeff != 0)
	{
		if (m.PowX == 0 && m.PowY == 0 && m.PowZ == 0)
			ostr << m.coeff;
		else
		{
			if (m.coeff != 1)
				ostr << m.coeff << " ";
			if (m.PowX != 0)
			{
				ostr << "x";
				if (m.PowX != 1)
					ostr << "^" << m.PowX << " ";
			}
			if (m.PowY != 0)
			{
				ostr << "y";
				if (m.PowY != 1)
					ostr << "^" << m.PowY << " ";
			}
			if (m.PowZ != 0)
			{
				ostr << "z";
				if (m.PowZ != 1)
					ostr << "^" << m.PowZ << " ";
			}
		}
	}
		return  ostr;
}