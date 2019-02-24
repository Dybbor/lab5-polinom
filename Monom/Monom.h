#pragma once
#include <iostream>

using namespace std;
struct TMonom 
{
	double coeff; //Коэффициент при мономе
	int PowX, PowY, PowZ; //Степени x,y,z
};

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
	if (m1.PowX > m2.PowX )
	{
		return true;
	}
}