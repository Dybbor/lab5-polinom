#pragma once
#include "HeadList.h"
#include "Monom.h"

class TPolinom : public THeadList <TMonom> 
{
public:
	TPolinom();		//Конструктор
	TPolinom(TPolinom &p);	//Конструктор копирования
	void InsMonom(const TMonom &m); //Вставить моном на своё место
	void operator+=(TPolinom q);	//Сложение полиномов
	void operator-=(TPolinom q);	//Вычитание полиномов
	void operator*=(const int &n);	//Умножение полинома на константу
	void operator*=(const TMonom &m);
	friend istream &operator>>(istream &istr, TPolinom &p);
	friend ostream& operator<<(ostream &ostr,  TPolinom &p);
};

TPolinom::TPolinom() 
{
	TMonom m;
	m.coeff = 0;
	m.PowX = 0;
	m.PowY = 0;
	m.PowZ = -1;
	pHead->val = m;
}
TPolinom::TPolinom(TPolinom & p) 
{
	pHead->val = p.pHead->val;
	for (p.Reset(); !p.IsEnd(); p.GoNext()) 
	{
		InsLast(p.pCurr->val);
	}
}
void TPolinom::InsMonom(const TMonom &m) 
{
	bool flag = 0;
	if (size == 0)
		InsFirst(m);
	else
		for (Reset(); !IsEnd(); GoNext())
		{
			if (pCurr->val == m)
			{
				pCurr->val.coeff += m.coeff;
				flag = 1;
				if (pCurr->val.coeff == 0)
				{
					DelCurrent();
					break;
				}
			}
			if (m > pCurr->val)
			{
				InsCurrent(m);
				break;
			}
		}
	if (pCurr == pHead && flag == 0)
	{
		InsCurrent(m);
		pos = size;
	}
}

void TPolinom::operator+=(TPolinom q) {
	Reset();
	q.Reset();
	while (1)
	{
		if (pCurr->val > q.pCurr->val)
			GoNext();
		else
			if (pCurr->val < q.pCurr->val)
			{
			InsCurrent(q.pCurr->val);
			q.GoNext();
		}
		else
		{
			if (pCurr->val.PowZ == -1 || q.pCurr->val.PowZ == -1)
				break;
			if ((q.pCurr->val.coeff + pCurr->val.coeff) == 0)
			{
				DelCurrent();
				q.GoNext();
			}
			else {
				pCurr->val.coeff = q.pCurr->val.coeff + pCurr->val.coeff;
				q.GoNext();
				GoNext();
			}
		}
	}
}
void TPolinom::operator-=(TPolinom q) 
{
	q *= -1;
	this->operator+=(q);
}
void TPolinom::operator*=(const int &n) 
{
	for (Reset(); !IsEnd(); GoNext()) 
	{
		this->pCurr->val.coeff *= n;
	}
}
void TPolinom ::operator*=(const TMonom &m) 
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= m.coeff;
		pCurr->val.PowX += m.PowX;
		pCurr->val.PowY += m.PowY;
		pCurr->val.PowZ += m.PowZ;
	}
}

istream &operator>>(istream &istr, TPolinom &p) 
{
	int n = 1;
	TMonom m;
	do
	{
		cout << n << "th  monom :" << endl;;
		try
		{
			cin >> m;
		}
		catch (...) 
		{
			return istr;
		}
		p.InsMonom(m);
		n++;
	} 
	while (p.pCurr->val.PowX > -1 && p.pCurr->val.PowY > -1 && p.pCurr->val.PowZ >= -1);
	return istr;
}
ostream& operator<<(ostream &ostr,  TPolinom &p) 
{
	if (p.size == 0)
		cout << 0;
	else
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			if (p.pos != 1)
				if (p.pCurr->val.coeff > 0)
					ostr << "+" << p.pCurr->val;
				else
					ostr << p.pCurr->val;
			else
				ostr << p.pCurr->val;
		}
	}
	return ostr;
	/*if (p.size == 0)
		throw "Error";
	else
	{
		p.Reset();
		ostr<<p.pCurr->val;
		p.GoNext();
		for (p.pCurr; !p.IsEnd(); p.GoNext())
		{
			if (p.pCurr->val.coeff > 0)
				ostr<<"+";
			ostr<<p.pCurr->val;
		}
	}
	return ostr;*/
}
