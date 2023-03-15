#include "LinkedList.h"

template <class T>
void LinkedList<T>::insert(int pos, T item)
{
	if (pos < 0 || pos > m_count)
		return;
	node<T>* temp = m_head;
	node<T>* inNode = new node<T>(item);
	if (pos == 0) {
		inNode->next = m_head;
		m_head = inNode;
	}
	else {
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		inNode->next = temp->next;
		temp->next = inNode;
	}
	m_count++;
}

template <class T>
void LinkedList<T>::remove(int pos)
{
	if (isEmpty() || pos < 0 || pos > m_count - 1)
		return;
	node<T>* temp = m_head;
	node<T>* delNode;
	if (pos == 0) {
		delNode = m_head;
		m_head = m_head->next;
	}
	else {
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		delNode = temp->next;
		temp->next = delNode->next;
	}
	delete delNode;
	m_count--;
}

template <class T>
T LinkedList<T>::retrieve(int pos)
{
	if (isEmpty() || pos < 0 || pos > m_count - 1)
		return T();
	node<T>* temp = m_head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp->data;
}
