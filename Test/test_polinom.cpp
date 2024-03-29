#include "pch.h"
#include "..\Header\Polinom.h"

TEST(TPolinom, can_create_polinom) 
{
	TPolinom p;
	EXPECT_EQ(0, p.pHead->val.coeff);
	EXPECT_EQ(0, p.pHead->val.PowX);
	EXPECT_EQ(0, p.pHead->val.PowY);
	EXPECT_EQ(-1, p.pHead->val.PowZ);
}
TEST(TPolinom, insert_monom_on_empty_list) 
{
	TPolinom p;
	TMonom monom;
	monom.coeff = 1;
	monom.PowX = 0;
	monom.PowY = 2;
	monom.PowZ = 5;
	p.InsMonom(monom);
	EXPECT_EQ(1, p.pos);
}
TEST(TPolinom, insert_monom_on_first_place)
{
	TPolinom p;
	TMonom monom1,monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	p.InsMonom(monom1);
	monom2.coeff = 1;
	monom2.PowX = 5;
	monom2.PowY = 2;
	monom2.PowZ = 5;
	p.InsMonom(monom2);
	EXPECT_EQ(1, p.pos);
	EXPECT_EQ(1, p.pFirst->val.coeff);
	EXPECT_EQ(5, p.pFirst->val.PowX);
	EXPECT_EQ(2, p.pFirst->val.PowY);
	EXPECT_EQ(5, p.pFirst->val.PowZ);
}

TEST(TPolinom, insert_monom_on_last_place)
{
	TPolinom p;
	TMonom monom1, monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = 1;
	monom2.PowX = 5;
	monom2.PowY = 2;
	monom2.PowZ = 5;
	p.InsMonom(monom2);
	p.InsMonom(monom1);
	EXPECT_EQ(2, p.pos);
	EXPECT_EQ(2, p.pLast->val.coeff);
	EXPECT_EQ(2, p.pLast->val.PowX);
	EXPECT_EQ(3, p.pLast->val.PowY);
	EXPECT_EQ(6, p.pLast->val.PowZ);
}

TEST(TPolinom, insert_monom_on_middle_list)
{
	TPolinom p;
	TMonom monom1, monom2,monom3;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = 1;
	monom2.PowX = 5;
	monom2.PowY = 2;
	monom2.PowZ = 5;
	monom3.coeff = 3;
	monom3.PowX = 3;
	monom3.PowY = 0;
	monom3.PowZ = 8;
	p.InsMonom(monom1);
	p.InsMonom(monom2);
	p.InsMonom(monom3);
	EXPECT_EQ(3, p.size);
	EXPECT_EQ(2, p.pos);
	EXPECT_EQ(3, p.pCurr->val.coeff);
	EXPECT_EQ(3, p.pCurr->val.PowX);
	EXPECT_EQ(0, p.pCurr->val.PowY);
	EXPECT_EQ(8, p.pCurr->val.PowZ);
}

TEST(TPolinom, insert_polinom_and_it_delete) 
{
	TPolinom p;
	TMonom monom1, monom2, monom3;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = -2;
	monom2.PowX = 2;
	monom2.PowY = 3;
	monom2.PowZ = 6;
	monom3.coeff = 3;
	monom3.PowX = 3;
	monom3.PowY = 0;
	monom3.PowZ = 8;
	p.InsMonom(monom1);
	cout << p << endl;
	p.InsMonom(monom2);
	cout << p << endl;
	p.InsMonom(monom3);
	cout << p << endl;
	EXPECT_EQ(1, p.size);
}

TEST(TPolinom, can_add_polinom) 
{
	TPolinom p,q;
	TMonom monom1, monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = 1;
	monom2.PowX = 5;
	monom2.PowY = 2;
	monom2.PowZ = 5;
	p.InsMonom(monom1);
	q.InsMonom(monom2);
	p += q;
	EXPECT_EQ(2, p.size);
}
TEST(TPolinom, can_add_polinom_with_negative_coeff_and_it_delete) 
{
	TPolinom p, q;
	TMonom monom1, monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = -2;
	monom2.PowX = 2;
	monom2.PowY = 3;
	monom2.PowZ = 6;
	p.InsMonom(monom1);
	q.InsMonom(monom2);
	p += q;
	EXPECT_EQ(0, p.size);
}
TEST(TPolinom, can_add_polinom_with_negative_coeff_and_size1_1)
{
	TPolinom p, q;
	TMonom monom1, monom2,monom3;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = -2;
	monom2.PowX = 2;
	monom2.PowY = 3;
	monom2.PowZ = 6;
	monom3.coeff = 1;
	monom3.PowX = 2;
	monom3.PowY = 0;
	monom3.PowZ = 5;
	p.InsMonom(monom1);
	p.InsMonom(monom3);
	q.InsMonom(monom2);
	p += q;
	cout << p << endl;
	EXPECT_EQ(1, p.size);
}

TEST(TPolinom, can_add_polinom_with_negative_coeff_and_size1_2)
{
	TPolinom p, q;
	TMonom monom1, monom2, monom3;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = -2;
	monom2.PowX = 2;
	monom2.PowY = 3;
	monom2.PowZ = 6;
	monom3.coeff = 1;
	monom3.PowX = 2;
	monom3.PowY = 0;
	monom3.PowZ = 5;
	p.InsMonom(monom1);
	q.InsMonom(monom3);
	q.InsMonom(monom2);
	p += q;
	EXPECT_EQ(1, p.size);
}
TEST(TPolinom, can_subtraction) 
{
	TPolinom p, q;
	TMonom monom1, monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = 1;
	monom2.PowX = 5;
	monom2.PowY = 2;
	monom2.PowZ = 5;
	p.InsMonom(monom1);
	q.InsMonom(monom2);
	p -= q;
	EXPECT_EQ(2, p.size);
}
TEST(TPolinom, can_subtraction_and_res_equal_0)
{
	TPolinom p, q;
	TMonom monom1, monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = 2;
	monom2.PowX = 2;
	monom2.PowY = 3;
	monom2.PowZ = 6;
	p.InsMonom(monom1);
	q.InsMonom(monom2);
	p -= q;
	EXPECT_EQ(0, p.size);
}

TEST(TPolinom, can_multiply_on_const) 
{
	TPolinom p;
	TMonom monom1, monom2;
	monom1.coeff = 2;
	monom1.PowX = 2;
	monom1.PowY = 3;
	monom1.PowZ = 6;
	monom2.coeff = 1;
	monom2.PowX = 5;
	monom2.PowY = 2;
	monom2.PowZ = 5;
	p.InsMonom(monom1);
	p.InsMonom(monom2);
	p *= 5;
	p.Reset();
	EXPECT_EQ(5, p.pCurr->val.coeff);
	p.GoNext();
	EXPECT_EQ(10, p.pCurr->val.coeff);
}
