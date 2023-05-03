#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class Search
{
private:
	T* m_data;
	int m_size;

public:
	Search(int Max = 100) : m_size(Max)
	{
		m_data = new T[Max];
	}
	~Search()
	{
		if (m_data) delete[] m_data;
	}

	void initData(T* data, int size)
	{
		m_size = size;

		if (m_data)
		{
			delete[] m_data;
		}

		m_data = new T[m_size];
		assert(m_data != nullptr);
		memcpy(m_data, data, sizeof(T) * m_size);
	}

	int getSize() { return m_size; }
	T* getData() { return m_data; }

	void printAll()
	{
		for (int i = 0; i < m_size; i++)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
	}

	virtual int searching(T data) = 0;
};
