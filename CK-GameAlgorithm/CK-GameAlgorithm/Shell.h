#pragma once
#include "sorting.h"

template <class T>
class Shell : public Sort<T>
{
public:
	Shell(int Max = 100) :Sort<T>(Max) {}

	void sorting() override;
	void shellsort(int data[], int N);
};

template <class T>
void Shell<T>::sorting()
{
	int N = this->getSize();

	shellsort(this->getData(), N);
}

template <class T>
void Shell<T>::shellsort(int data[], int N)
{
	int i, j, h;
	int v;

	for (int h = N / 2; h > 0; h /= 2)
	{
		for (i = h; i < N; i++)
		{
			v = data[i];
			j = i;

			while (j >= h && data[j - h] > v)
			{
				data[j] = data[j - h];
				j -= h;
			}

			data[j] = v;
		}
	}
}