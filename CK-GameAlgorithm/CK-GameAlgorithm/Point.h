#pragma once
#include <iostream>
using namespace std;

template <class T>
class Point
{
	T m_x;
	T m_y;
public:
	Point(T x = 0, T y = 0) :m_x(x), m_y(y) { }

	T getX();
	T getY();
	T setXY(T x, T y);
	void printPosition() const;
};
