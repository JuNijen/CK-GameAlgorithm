#include "ArrayList.h"


template<class T>
void arrayList<T>::insert(int pos, T data)
{
	if (isFull() || pos < 0 || pos > m_count) 
	{
		return;
	}

	for (int i = m_count - 1; i >= pos; i--)
	{
		m_list[i + 1] = m_list[i];
	}
	m_list[pos] = data;
	m_count++;
}

template<class T>
void arrayList<T>::remove(int pos)
{
	if (isEmpty() || pos < 0 || pos >= m_count)
	{
		return;
	}

	for (int i = pos; i < m_count; i++)
	{
		m_list[i] = m_list[i + 1];
	}
	m_count--;
}

template<class T>
T arrayList<T>::retrieve(int pos)
{
	if (!isEmpty() && (pos >= 0 && Pos < m_count)) 
	{
		return m_list[pos];
	}
	return T();
}

int main() 
{
	arrayList<int>* list = new arrayList<int>(100);

	list->insert(0, 1);
	list->insert(1, 2);
	list->insert(2, 4);
	list->insert(1, 5);

	cout << list->retrieve(0);
	cout << list->retrieve(1);
	cout << list->retrieve(2);
	cout << list->retrieve(3) << "\n";
	list->remove(1);

	cout << list->retrieve(0);
	cout << list->retrieve(1);
	cout << list->retrieve(2);
}