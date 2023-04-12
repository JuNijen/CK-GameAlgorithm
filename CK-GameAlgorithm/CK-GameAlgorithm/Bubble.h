#pragma once
#include "sorting.h"

template <class T>
class Bubble : public Sort<T> 
{
public:
	Bubble(int Max = 100) :Sort<T>(Max) {}
	void sorting() override;
};

template <class T>
void Bubble<T>::sorting() 
{
	int N = this->getSize();
	T* data = this->getData();

	bool sorted = false;

	for (int pass = 1; (pass < N) && (!sorted); ++pass) 
	{
		sorted = true;
		for (int cur = 0; cur < N - pass; ++cur) 
		{
			if (data[cur] > data[cur + 1]) 
			{
				swap(data[cur], data[cur + 1]);
				sorted = false;
			}
		}
	}
}