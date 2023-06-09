#pragma once
#include "sorting.h"

template <class T>
class Merge : public Sort<T>
{
public:
	Merge(int Max = 100) :Sort<T>(Max) {}

	void sorting() override;
	void mergesort(T* sorted, T* data, int first, int last);
	void merge(T* sorted, T* data, int first, int middle, int last);
};

template <class T>
void Merge<T>::mergesort(T* sorted, T *data, int first, int last) 
{
	if (first < last) 
	{
		int N = this->getSize();
		int middle = (first + last) / 2;

		mergesort(sorted, data, first, middle);
		mergesort(sorted, data, middle + 1, last);
		merge(sorted, data, first, middle, last);
	}
}

template <class T>
void Merge<T>::sorting()
{
	int N = this->getSize();
	T* data = this->getData();
	T* sorted = new T[N];

	mergesort(sorted, data, 0, N-1);

	delete[] sorted;
}

template <class T>
void Merge<T>::merge(T* sorted, T* data, int f, int m, int l)
{
	int N = this->getSize();
	
	int first1 = f;
	int last1 = m;

	int first2 = m + 1;
	int last2 = l;

	int index = first1;


	while (first1 <= last1 && first2 <= last2) 
	{
		if (data[first1] < data[first2]) 
		{
			sorted[index++] = data[first1++];
		}
		else 
		{
			sorted[index++] = data[first2++];
		}
	}

	for (; first1 <= last1; first1++, index++) 
	{
		sorted[index] = data[first1];
	}

	for (; first2 <= last2; first2++, index++) 
	{
		sorted[index] = data[first2];
	}

	for (index = f; index <= l; index++) 
	{
		data[index] = sorted[index];
	}
}