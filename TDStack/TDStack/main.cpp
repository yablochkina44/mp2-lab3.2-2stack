#include <string>
#include <iostream>
#include "TDStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	TDStack <int> st(10);
	for (int i = 0; i < 5; i++)
	{
		st.Push1(i * 2);
	}

	for (int i = 0; i < 5; i++)
	{
		st.Push2((i * 2) + 1);
	}

	cout << "Стек 1" << endl;
	while (!st.Empty1())
	{
		cout << st.Pop1() << endl;
	}

	cout << "Стек 2" << endl;
	while (!st.Empty2())
	{
		cout << st.Pop2() << endl;
	}

}