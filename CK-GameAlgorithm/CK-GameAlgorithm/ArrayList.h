#pragma once
#include <iostream>
using namespace std;

template <class T>
class arrayList
{
	T* m_list;
	int m_count;
	int m_max;
public:
	arrayList(int Max = 100) : m_count(0), m_max(Max) 
	{
		m_list = new T[Max];
	}
	~arrayList() {
		if (m_list)
			delete[] m_list;
	}
	int getSize() { return m_count; }
	void insert(int pos, T data);
	void remove(int pos);
	T retrieve(int pos);
	bool isEmpty() { return m_count == 0; }
	bool isFull() { return m_count == m_max; }
};