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
		if (pM > qM)
			GoNext();
		else
			if (pM < qM)
			{
				InsCurrent(qM);
				q.GoNext();
			}
			else
				if (pM.PowZ == -1)
					break;
				else
				{
					double r = pM.coeff + qM.coeff;
					if (r == 0) 
					{
						DelCurrent();
						GoNext();
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