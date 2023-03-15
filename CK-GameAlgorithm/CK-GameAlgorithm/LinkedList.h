#pragma once
template <class T>
struct node {
	T data;
	node* next;
	node(T item) : data(item), next(nullptr) {}
};
template <class T>
class LinkedList {
	node<T>* m_head;
	int m_count;
public:
	LinkedList() : m_head(nullptr), m_count(0) {}
	~LinkedList() {}
	void insert(int pos, T item);
	void remove(int pos);
	T retrieve(int pos);
	bool isEmpty() { return m_count == 0; }
	int getSize() { return m_count; }
	void draw();
};
