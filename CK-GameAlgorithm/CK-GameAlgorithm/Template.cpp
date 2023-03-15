#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b) 
{
	return a > b ? a : b;
}

int Template1()
{
	int ch1_hp = 200;
	int ch2_hp = 500;
	int max_hp = Max(ch1_hp, ch2_hp);

	cout << "Max HP : " << max_hp << endl;

	float ch1_exp = 305.5f;
	float ch2_exp = 305.1f;
	float max_exp = Max(ch1_exp, ch2_exp);

	cout << "Max Exp : " << max_exp << endl;
	return 0;
}