#pragma once
#pragma once
#include "search.h"

template <class T>
class LinearInterpolation : public Search<T>
{
public:
	LinearInterpolation(int Max = 100) :Search<T>(Max) {}

	int searching(T data) override;
	void binarySearch(T S[], T x, int low, int high);
	//void linearInterpolation(T S[], T x, int low, int high);
	int linearInterpolation(T S[], T key, int n);
};

template <class T>
int LinearInterpolation<T>::searching(T data)
{
	return linearInterpolation(this->getData(), data, this->getSize());
}

template <class T>
void LinearInterpolation<T>::binarySearch(T S[], T x, int low, int high)
{
	int mid;

	if (low > high) 
	{
		return T();
	}
	else 
	{
		mid = (low + high) / 2;

		if (x == S[mid]) 
		{
			return mid;
		}
		else if (x < S[mid]) 
		{
			return binarySearch(S, x, low, mid - 1);
		}
		else 
		{
			return binarySearch(S, x, mid + 1, high);
		}
	}	
}

//template <class T>
//void LinearInterpolation<T>::linearInterpolation(T S[], T x, int low, int high)
//{
//	int mid;
//	T denominator; //최대값과 최소값 차이 - 분모
//
//	if (low > high)
//	{
//		return -1;
//	}
//	else
//	{
//		mid = 1 + (high - low) *(x + S[low]) / (S[high] - S[low);
//
//		if (x == S[mid])
//		{
//			return mid;
//		}
//		else if (x < S[mid])
//		{
//			return linearInterpolation(S, x, low, mid - 1);
//		}
//		else
//		{
//			return linearInterpolation(S, x, mid + 1, high);
//		}
//	}
//}

template <class T>
int LinearInterpolation<T>::linearInterpolation(T S[], T key, int n)
{
	int low = 0;
	int high = n - 1;
	int mid;

	while (low < high) 
	{
		int denominator = S[high] - S[low];
		if (denominator == 0)
		{
			mid = low;
		}
		else 
		{
			mid = low + (key - S[low]) * (high - low) / denominator;

			if (key == S[mid]) 
			{
				return mid;
			}
			if (key < S[mid]) 
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	return -1;
}
