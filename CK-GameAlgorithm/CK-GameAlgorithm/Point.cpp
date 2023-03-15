#include "Point.h"

void Point1()
{
    Point<int> pos1(100, 200);
    pos1.printPosition();

    Point<double> pos2(11.5, 25.3);
    pos2.printPosition();

    Point<char> pos3('A', 'B');
    pos3.printPosition();
    pos3.printPosition();
}

template <class T>
T Point<T>::getX()
{
    return m_x;
}

template <class T>
T Point<T>::getY()
{
    return m_y;
}

template <class T>
T Point<T>::setXY(T x, T y)
{
    m_x = x;
    m_y = y;
}

template <class T>
void Point<T>::printPosition() const
{
    cout << "(" << m_x << " , " << m_y << ")" << endl;
}