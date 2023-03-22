#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class ArrayStack
{
private:
	int m_top;
	T* m_stack;
	int m_max;

public:
	ArrayStack(int Max = 100) : m_top(0), m_max(Max)
	{
		m_stack = new T[Max];
	}
	~ArrayStack()
	{
		if (m_stack)
			delete[] m_stack;
	}
	void push(T data);
	void pop();
	bool isEmpty() { return m_top == 0; }
	bool isFull() { return m_top == m_max; }
	T getTop() { return isEmpty() ? T() : m_stack[m_top - 1]; }
};