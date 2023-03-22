#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class ArrayQueue 
{
private:
	T* m_queue;
	int m_front;
	int m_tail;
	int m_max;
	int m_size;

public:
	ArrayQueue(int Max = 100) : m_front(0), m_tail(0), m_max(Max), m_size(0) 
	{
		m_queue = new T[Max];
	}
	~ArrayQueue() 
	{
		if (m_queue) delete[] m_queue;
	}
	void push(T item);
	void pop();
	T front() { return empty() ? T() : m_queue[m_front]; }
	bool empty() { return m_size == 0; }
	bool full() { return m_size == m_max; }
	int size() { return m_size; }
};

template<class T>
void ArrayQueue<T>::push(T item)
{
	if (full())
	{
		throw invalid_argument("Queue is full");
	}
	m_queue[m_tail] = item;
	m_tail = (m_tail + 1) % m_max;
	m_size++;
}

template<class T>
void ArrayQueue<T>::pop()
{
	if (empty())
	{
		throw invalid_argument("Queue is empty");
	}
	m_front = (m_front+1) % m_max;
	m_size--;
}