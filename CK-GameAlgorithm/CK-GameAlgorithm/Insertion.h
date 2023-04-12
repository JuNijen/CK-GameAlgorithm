#pragma once
#include "sorting.h"

template <class T>
class Insertion : public Sort<T>
{
public:
	Insertion(int Max = 100) :Sort<T>(Max) {}
	void sorting() override;

};

template <class T>
void Insertion<T>::sorting() 
{
	int N = this->getSize();
	T* data = this->getData();
	
	for (int pick = 1; pick < N; ++pick) 
	{
		int cur = pick;

		T pickData = data[pick];

		for (; (cur > 0) && (data[cur-1] > pickData); --cur) 
		{
			data[cur] = data[cur - 1];
		}
		data[cur] = pickData;
	}
}