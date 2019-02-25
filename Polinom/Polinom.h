#pragma once
#include "..\HeadList\HeadList.h"
#include "..\Monom\Monom.h"

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
				pCurr->val.coeff += m.coeff;
			if (pCurr->val.coeff == 0)
			{
				DelCurrent();
				break;
			}
			if (m > pCurr->val) 
			{
				InsCurrent(m);
				break;
			}
		}
	if (pCurr == pHead)
		InsCurrent(m);
}

