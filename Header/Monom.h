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
	//return (m1.PowX != m2.PowX || m1.PowY != m2.PowY || m1.PowZ != m2.PowZ);
	return !(m1==m2);
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
	if (m1.PowX < m2.PowX)
		return true;
	else
		if (m1.PowX == m2.PowX && m1.PowY < m2.PowY)
			return true;
		else
			if (m1.PowY == m2.PowY && m1.PowZ < m2.PowZ)
				return true;
			else
				return false;
}
istream &operator>>(istream &istr, TMonom &m)
{
	int coeff, x, y, z;
	cout << "Coeff: ";
	istr >> coeff;
	if (coeff == 0)
		throw - 1;
	cout << "Power X: ";
	istr >> x;
	if (x<-1)
		throw - 1;
	cout << "Power Y: ";
	istr >> y;
	if (y<-1)
		throw - 1;
	cout << "Power Z: ";
	istr >> z;
	if (z<-1)
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
			if (abs(m.coeff)==1)
				{
				if (m.coeff == -1)
					cout << "-";
				}
			else
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
TMonom InsValueInMonom(double coeff, int x,int y,int z) //Вставить значения в моном
{
	TMonom m;
	m.coeff = coeff;
	m.PowX = x;
	m.PowY = y;
	m.PowZ = z;
	return m;
}