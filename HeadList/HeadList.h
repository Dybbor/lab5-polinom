#pragma once
template <class T>
struct TLink 
{
	T val;
	TLink *pNext;
};
template <class T>
class THeadList 
{
public:
	THeadList();		//Конструктор по умолчанию
	~THeadList();		//Деструктор
protected :
	TLink <T> *pHead,	//Указатель на голову
		*pFirst,		//Указатель на первый элемент в списке
		*pLast,			//Указатель на последний элемент в списке
		*pPrev,			//Указатель на предыдущее звено
		*pCurr;			//Указатель на текущее звено
	int pos;			//Позиция звена в списке
	int size;			//Размер списка
	void InsCurrent(const T & elem);	//Добавить звено между предыдущем и текущем
	void InsFirst(const T &elem);	//Вставить зваено в начало  списка
	void InsLast(const T &elem);	//Вставить звено в конец списка
	void DelCurrent();	//Удалить текущее звено
	void Reset();		//Обнулить все счетчики
	void GoNext();		//Нужные указатели передвигает вправо на 1 звено
	bool IsEnd();		// Проверка на конец списка
};  

template <class T>
THeadList <T>::THeadList() 
{
	phead = new TLink <T>;
	phead->pnext = pHead;
	pFirst = pCurr = pLast = pHead;
	size = 0;
}
template <class T>
THeadList <T >::~THeadList() 
{
	pCurr = pFirst;
	while (pCurr != pHead) 
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		delete pPrev;
	}
	delete pHead;
}

template <class T>
void THeadList <T> ::InsCurrent(const T &elem) 
{
	TLink <T> *tmp = new TLink <T>;
	tmp->val = elem;
	pPrev->pNext = tmp;
	tmp->pNext = pCurr;
	pCurr = tmp;
	size++;
}
template <class T>
void THeadList <T> ::InsFirst(const T &elem) 
{
	TLink <T> * tmp = new TLink <T>;
	tmp->val = elem;
	if (size > 0) 
	{
		pHead->pNext = tmp;
		tmp->pNext = pFirst;
		pFirst = tmp;
		size++;
		pos++;
	}
	else 
	{
		pHead->pNext = tmp;
		tmp->pNext = pHead;
		pFirst = tmp;
		pLast = tmp;
		size++;
		pos = 0;
		pCurr = pFirst;
	}
}
template <class T>
void THeadList <T> ::InsLast(const T & elem) 
{
	TLink <T> *tmp = new TLink <T>;
	pLast = tmp;
	pLast->pNext = pHead;
	pCurr = pLast;
	size++;
	pos++;
}
template <class T>
void THeadList <T>::DelCurrent() 
{
	if (pCurr != pHead && size > 0)
	{
		TLink <T> *tmp = pCurr;
		pPrev->pNext = tmp->pNext;
		delete tmp;
		PCurr = pPrev->pNext;
		size--;
	}
	else
		throw "Error";
}
template <class T> 
void THeadList <T> ::Reset() 
{
	pCurr = pFirst;
	pPrev = pHead;
	pos = 0;
}
template <class T>
void THeadList <T>::GoNext() 
{
	if (IsEnd())
		throw "Error";
	pPrev = pCurr;
	pCurr = pCurr->pNext;
	pos++;
}
template <class T>
bool THeadList<T>::IsEnd() 
{
	return (pCurr == pHead);
}