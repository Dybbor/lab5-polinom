#pragma once

using namespace std;
struct TMonom 
{
	double coeff; //����������� ��� ������
	int PowX, PowY, PowZ; //������� x,y,z
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

istream &operator>>(istream &istr, TMonom &m);