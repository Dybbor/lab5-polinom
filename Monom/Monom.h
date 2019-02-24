#pragma once

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
bool operator>(const TMonom &m1, const TMonom &m2)
{
	return !(m1 > m2);
}

istream &operator>>(istream &istr, TMonom &m) 
{
	int coeff, x, y, z;
	istr >> coeff >> x >> y >> z;
	m.coeff = coeff;
	m.PowX = x;
	m.PowY = y;
	m.PowZ = z;
	return istr;
}

ostream& operator<<(ostream &ostr, const TMonom &m) 
{
	if (m.coeff != 0)
		if (m.coeff != 1);

	ostr << "Empty";
	if (m.PowX==0)

	return  ostr;
}