#pragma once
//#include "stdafx.h"
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

istream &operator>>(istream &istr, TMonom &m)
{
	int coeff, x, y, z;
	istr >> coeff >> x >> y >> z;
	if (x < 0 || y < 0 || z < 0)
		throw - 1;
	if (coeff != 0)
	{	
		m.PowX = x;
		m.PowY = y;
		m.PowZ = z;
		if (coeff != 1) 
			m.coeff = coeff;
	}
	return istr;
}

wchar_t digitToSuperscript(unsigned int digit) //Нахождение кода степени в таблице Unicode
{
	if (digit >= 10)
		throw std::out_of_range("digit");
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
		if (CountNumber(intPart % del) != count - 1 && count != 0)
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
/*	if (CheckPow(m.PowX) == 0)
		if (CheckPow(m.PowY) == 0)
			if (CheckPow(m.PowZ) == 0)
				wcout << 1;
			else
				if (m.PowZ == 1)
					wcout << "z";
				else
				{
					wcout << L"z";
					PrintPow(m.PowZ);
				}
		else
			if (m.PowY == 0)
				wcout << "y";
			else
			{
				wcout << L"y";
				PrintPow(m.PowY);
				if (m.PowZ == 1)
					wcout << "z";
				else
				{
					wcout << L"z";
					PrintPow(m.PowZ);
				}
			}
	else
		if (m.PowX == 1)
			wcout << "x";
		else 
		{
		wcout<<
		}


	if (CheckPow(m.PowX) == 0)
		if (CheckPow(m.PowY) == 0)
			if (CheckPow(m.PowZ) == 0)
				wcout << 1;
			else
			{
				wcout << "z";
				if (m.PowZ != 1)
					PrintPow(m.PowZ);
			}
		else
		{
			wcout << "y";
			if (m.PowY != 1)
				PrintPow(m.PowY);
			wcout << "z";
			if (m.PowZ != 1)
				PrintPow(m.PowZ);
		}
	else
	{
		wcout << "x";
		if (m.PowX != 1)
			PrintPow(m.PowX);
	}*/
	if (m.PowX == 0 && m.PowY == 0 && m.PowZ == 0)
		wcout << "1";
	if (m.PowX != 0) 
	{
		wcout << "x";
		if (m.PowX != 1)
			PrintPow(m.PowX);
	}
	if (m.PowY != 0)
	{
		wcout << "x";
		if (m.PowY != 1)
			PrintPow(m.PowY);
	}
	if (m.PowZ!= 0)
	{
		wcout << "x";
		if (m.PowZ != 1)
			PrintPow(m.PowZ);
	}
	



}
ostream& operator<<(ostream &ostr, const TMonom &m) 
{

	if (m.coeff != 0)
		if (m.coeff == 1)
		{	
			if (m.PowX)
				ostr <<123 ;
		
		}
		return  ostr;
}