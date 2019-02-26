#include "pch.h"
#include "..\Header\HeadList.h"


TEST(THeadList, InsFirst_in_empty_list) 
{
	THeadList <int> a;
	a.InsFirst(5);
	EXPECT_EQ(1, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(5, a.pLast->val);
	EXPECT_EQ(5, a.pCurr->val);
	EXPECT_EQ(1, a.pPrev == a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}

TEST(THeadList, InsFirst_in_no_empty_list)
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsFirst(4);
	a.InsFirst(3);
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(3, a.pFirst->val);
	EXPECT_EQ(3, a.pCurr->val);
	EXPECT_EQ(5, a.pLast->val);
	EXPECT_EQ(1, a.pPrev==a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, InsCurr_in_empty_list)
{
	THeadList <int> a;
	a.InsCurrent(3);
	EXPECT_EQ(1, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(3, a.pFirst->val);
	EXPECT_EQ(3, a.pCurr->val);
	EXPECT_EQ(3, a.pLast->val);
	EXPECT_EQ(1, a.pPrev == a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, InsCurr_in_list)
{
	THeadList <int> a;
	a.InsCurrent(5);
	a.InsCurrent(4);
	a.InsCurrent(3);
	a.InsCurrent(1);
	EXPECT_EQ(4, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(1, a.pFirst->val);
	EXPECT_EQ(1, a.pCurr->val);
	EXPECT_EQ(5, a.pLast->val);
	EXPECT_EQ(1, a.pPrev == a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}

TEST(THeadList, InsLast_in_empty_list) 
{
	THeadList <int> a;
	a.InsLast(5);
	EXPECT_EQ(1, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(5, a.pCurr->val);
	EXPECT_EQ(5, a.pLast->val);
	EXPECT_EQ(1, a.pPrev == a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}

TEST(THeadList, InsLast_in_list)
{
	THeadList <int> a;
	a.InsLast(5);
	a.InsLast(4);
	a.InsLast(3);
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(3, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(3, a.pCurr->val);
	EXPECT_EQ(3, a.pLast->val);
	EXPECT_EQ(4, a.pPrev->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, check_all_Ins_random_1) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsCurrent(4);
	a.InsLast(3);
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(3, a.pos);
	EXPECT_EQ(4, a.pFirst->val);
	EXPECT_EQ(3, a.pCurr->val);
	EXPECT_EQ(3, a.pLast->val);
	EXPECT_EQ(5, a.pPrev ->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}

TEST(THeadList, check_all_Ins_random_2)
{
	THeadList <int> a;
	a.InsCurrent(5);
	a.InsFirst(4);
	a.InsLast(3);
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(3, a.pos);
	EXPECT_EQ(4, a.pFirst->val);
	EXPECT_EQ(3, a.pCurr->val);
	EXPECT_EQ(3, a.pLast->val);
	EXPECT_EQ(5, a.pPrev ->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}

TEST(THeadList, check_all_Ins_random_3)
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsFirst(4);
	a.InsLast(3);
	a.InsLast(2);
	a.InsCurrent(1);
	EXPECT_EQ(5, a.size);
	EXPECT_EQ(4, a.pos);
	EXPECT_EQ(4, a.pFirst->val);
	EXPECT_EQ(1, a.pCurr->val);
	EXPECT_EQ(2, a.pLast->val);
	EXPECT_EQ(3, a.pPrev->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, cant_DelCurr_throw_something) 
{
	THeadList <int> a;
	EXPECT_ANY_THROW(a.DelCurrent());
}

TEST(THeadList, can_DelCurr_and_make_empty_list) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.DelCurrent();
	EXPECT_EQ(0, a.size);
	EXPECT_EQ(0, a.pos);
	EXPECT_EQ(1, a.pFirst == a.pHead);
	EXPECT_EQ(1, a.pCurr == a.pHead);
	EXPECT_EQ(1, a.pLast == a.pHead);
	EXPECT_EQ(1, a.pPrev == a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, can_DelCurr_first_link) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.InsCurrent(3);
	a.InsFirst(2);
	a.DelCurrent();
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(5, a.pCurr->val);
	EXPECT_EQ(4, a.pLast->val);
	EXPECT_EQ(1, a.pPrev == a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, can_DelCurr_in_middle) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.InsCurrent(3);
	a.InsCurrent(2);
	a.DelCurrent();
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(2, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(3, a.pCurr->val);
	EXPECT_EQ(4, a.pLast->val);
	EXPECT_EQ(5, a.pPrev ->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}

TEST(THeadList, can_DelCurr_last_link) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.InsCurrent(3);
	a.InsLast(1);
	a.DelCurrent();
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(3, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(4, a.pCurr->val);
	EXPECT_EQ(4, a.pLast->val);
	EXPECT_EQ(3, a.pPrev->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, can_reset_list) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.InsCurrent(3);
	a.InsLast(1);
	a.Reset();
	EXPECT_EQ(4, a.size);
	EXPECT_EQ(1, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(5, a.pCurr->val);
	EXPECT_EQ(1, a.pLast->val);
	EXPECT_EQ(1, a.pPrev==a.pHead);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, throw_when_reset_empty_list) 
{
	THeadList <int> a;
	EXPECT_ANY_THROW(a.Reset());
}
TEST(THeadList, can_GoNext)
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.InsCurrent(3);
	a.GoNext();
	EXPECT_EQ(3, a.size);
	EXPECT_EQ(3, a.pos);
	EXPECT_EQ(5, a.pFirst->val);
	EXPECT_EQ(4, a.pCurr->val);
	EXPECT_EQ(4, a.pLast->val);
	EXPECT_EQ(3, a.pPrev->val);
	EXPECT_EQ(1, a.pLast->pNext == a.pHead);
}
TEST(THeadList, throw_when_GoNext_last_link) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.GoNext();
	EXPECT_ANY_THROW(a.GoNext());
}
TEST(THeadList, IsEnd_return_true) 
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	a.GoNext();
	EXPECT_EQ(true, a.IsEnd());
}
TEST(THeadList, IsEnd_return_false)
{
	THeadList <int> a;
	a.InsFirst(5);
	a.InsLast(4);
	EXPECT_EQ(false, a.IsEnd());
}