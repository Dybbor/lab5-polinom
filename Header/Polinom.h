#pragma once
#include "HeadList.h"
#include "Monom.h"

class TPolinom : public THeadList <TMonom> 
{
public:
	TPolinom();		//�����������
	TPolinom(TPolinom &p);	//����������� �����������
	void InsMonom(const TMonom &m); //�������� ����� �� ��� �����
	void operator+=(TPolinom q);	//�������� ���������
	void operator-=(TPolinom q);	//��������� ���������
	void operator*=(const int &n);	//��������� �������� �� ���������
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
	if (size == 0) 
		InsFirst(m);
	else
		for (Reset(); !IsEnd(); GoNext()) 
		{
			if (pCurr->val == m)
			{
				pCurr->val.coeff += m.coeff;
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
	if (pCurr == pHead)
	{
		InsCurrent(m);
		pos = size;
	}
}

void TPolinom::operator+=(TPolinom q) 
{
	TMonom pM, qM;
	Reset();
	q.Reset();
	while (true) 
	{
		pM = pCurr->val;
		qM = q.pCurr->val;
		if (pM.PowZ == -1)
			break; 
		else
			if (pM > qM)
				GoNext();
			else
				if (pM < qM)
				{
					InsCurrent(qM);
					q.GoNext();
				}
				else
				{
					double r = pM.coeff + qM.coeff;
					if (r == 0) 
					{
						DelCurrent();
						if(size!=0)	//���� ������ �� ��������� ������
							GoNext();
						else
						{
							q.GoNext();
							while (!q.IsEnd())
							{
								InsMonom(pCurr->val);
								q.GoNext();
							}
						}
					}
					else
					{
						pCurr->val.coeff = r;
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
					ostr << p.pCurr;
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
