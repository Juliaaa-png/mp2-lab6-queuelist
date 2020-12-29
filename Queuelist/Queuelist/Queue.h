#pragma once
#include<iostream>

template<class T>
struct TLink {
	T val;
	TLink* pNext;
};

template <class T>
class TQueue
{
private:
	TLink<T>* pHead, * pTail;
public:
	TQueue();
	TQueue(const TQueue<T>& m);
	~TQueue();
	TQueue<T>& operator = (const TQueue<T>& m);
	bool operator == (const TQueue<T>& m) const;
	bool operator != (const TQueue<T>& m) const;
	bool Empty() const;
	void Push(const T elem);
	T SeeHead() const;
	T GetHead();
};
template<class T>
TQueue<T>::TQueue()
{
	pHead = NULL;
	pTail = NULL;
}
template <class T>
TQueue<T>::TQueue(const TQueue<T>& m)
{
	if (m.pHead != NULL)
	{
		TLink<T>* tmp, * prev;
		prev = new TLink<T>;
		prev->val = m.pHead->val;
		pHead = prev;
		tmp = m.pHead->pNext;
		while (tmp != NULL)
		{
			TLink<T>* new_link = new TLink<T>;
			new_link->val = tmp->val;
			prev->pNext = new_link;
			prev = new_link;
			tmp = tmp->pNext;
		}
		pTail = prev;
		prev->pNext = NULL;
	}
	else
	{
		pHead = NULL;
		pTail = NULL;
	}
}
template <class T>
TQueue<T>::~TQueue()
{
	while (pHead != NULL)
	{
		TLink<T>* tmp = pHead->pNext;
		delete pHead;
		pHead = tmp;
	}
}
template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& m)
{
	if (this != &m)
	{
		while (pHead != NULL)
		{
			TLink<T>* tmp = pHead->pNext;
			delete pHead;
			pHead = tmp;
		}
		pTail = NULL;
		if (m.pHead != NULL)
		{
			TLink<T>* prev, * tmp;
			prev = new TLink<T>;
			prev->val = m.pHead->val;
			pHead = prev;
			tmp = m.pHead->pNext;
			while (tmp != NULL)
			{
				TLink<T>* new_link = new TLink<T>;
				new_link->val = tmp->val;
				prev->pNext = new_link;
				prev = new_link;
				tmp = tmp->pNext;
			}
			pTail = prev;
			prev->pNext = NULL;
		}
	}
	return (*this);
}
template<class T>
bool TQueue<T>::operator==(const TQueue<T>& m) const
{
	if (this != &m)
	{
		TLink<T>* tmp_th, * tmp_par;
		tmp_th = pHead;
		tmp_par = m.pHead;
		while (true)
		{
			if (tmp_par == NULL && tmp_th == NULL)
			{
				return true;
			}
			if (tmp_par == NULL || tmp_th == NULL)
			{
				return false;
			}
			if (tmp_th->val != tmp_par->val)
			{
				return false;
			}
			tmp_th = tmp_th->pNext;
			tmp_par = tmp_par->pNext;
		}
	}
	return true;
}
template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& m) const
{
	return (!(*this == m));
}
template<class T>
bool TQueue<T>::Empty() const
{
	if (pHead == NULL)
		return true;
	return false;
}


template <class T>
void TQueue<T>::Push(const T elem)
{
	TLink<T>* tmp = new TLink<T>;
	tmp->val = elem;
	tmp->pNext = NULL;
	if (Empty())
	{
		pHead = tmp;
		pTail = tmp;
	}
	else
	{
		pTail->pNext = tmp;
		pTail = tmp;
	}
}
template<class T>
T TQueue<T>::SeeHead() const
{
	if (Empty())
		throw 0;
	return pHead->val;
}
template<class T>
T TQueue<T>::GetHead()
{
	if (Empty())
		throw 0;
	TLink<T>* tmp = pHead->pNext;
	T elem = pHead->val;
	delete pHead;
	pHead = tmp;
	return elem;
}