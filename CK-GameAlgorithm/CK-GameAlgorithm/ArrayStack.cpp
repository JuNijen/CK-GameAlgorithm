#include "ArrayStack.h"

template <class T>
void ArrayStack<T>::push(T data) 
{
	if (isFull()) 
	{
		throw invalid_argument("Stack is full");
	}
	m_stack[m_top++] = data;
}

template <class T>
void ArrayStack<T>::pop()
{
	if (isEmpty())
	{
		throw invalid_argument("Stack is empty");
	}
	m_top--;
}