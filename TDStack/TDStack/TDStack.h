#pragma once

template <class T>
class TDStack
{
private:
	int MaxSize; // ������
	int NumLast1; // ����� ���������� �������� 1 �����
	int NumLast2; // ����� ���������� �������� 2 �����
	T* mas;   // ������

public:
	TDStack(int _Size = 10)
	{
		if ((_Size <= 0) || (_Size > 1000))
		{
			throw "����������� ������ �����";
		}
		else
		{
			MaxSize = _Size;
			mas = new T[MaxSize];
			NumLast1 = -1;
			NumLast2 = MaxSize;
		}
	}
	TDStack(const TDStack& s)
	{
		MaxSize = s.MaxSize;
		NumLast1 = s.NumLast1;
		NumLast2 = s.NumLast2;
		mas = new T[MaxSize];
		for (int i = 0; i < NumLast1; i++)
		{
			mas[i] = s.mas[i];
		}
		for (int i = MaxSize; i > NumLast2; i--)
		{
			mas[i] = s.mas[i];
		}
	}
	~TDStack() { delete[] mas; }


	bool Empty1();              //�������� �� �������
	bool Empty2();
	bool Full1();               //�������� �� �������
	bool Full2();
	void Clear1();              //������� �����
	void Clear2();

	T Top1();                   //���������� ��������� �������
	T Top2();
	T Pop1();                   //����� ��������� �������
	T Pop2();
	void Push1(const T& n);     //�������� �������
	void Push2(const T& n);     //�������� ������� 
};




template <class T>
bool TDStack<T>::Empty1()
{
	if (NumLast1 == -1)
		return true;
	else
		return false;
}

template <class T>
bool TDStack<T>::Empty2()
{
	if (NumLast2 == MaxSize)
		return true;
	else
		return false;
}

template <class T>
bool TDStack<T>::Full1()
{
	if (NumLast1 < NumLast2 - 1)
		return false;
	else
		return true;
}
template <class T>
bool TDStack<T>::Full2()
{
	if (NumLast2 > NumLast1 + 1)
		return false;
	else
		return true;
}

template <class T>
void TDStack<T>::Clear1()
{
	NumLast1 = -1;
}
template <class T>
void TDStack<T>::Clear2()
{
	NumLast2 = MaxSize;
}

template <class T>
T TDStack<T>::Top1()
{
	//���������� ���� ������ ��������
	if (Empty1())
		throw "���� ����";
	else
		return mas[NumLast1];
}
template <class T>
T TDStack<T>::Top2()
{
	//���������� ���� ������ ��������
	if (Empty2())
		throw "���� ����";
	else
		return mas[NumLast2];
}


template <class T>
T TDStack<T>::Pop1()
{
	if (Empty1())
		throw NumLast1;
	else
		return mas[NumLast1--];

}
template <class T>
T TDStack<T>::Pop2()
{
	if (Empty2())
		throw NumLast2;
	else
		return mas[NumLast2++];

}

template <class T>
void TDStack<T>::Push1(const T& n)
{

	if (Full1())
		throw "���� ��������";
	else
		NumLast1++;
	mas[NumLast1] = n;
}
template <class T>
void TDStack<T>::Push2(const T& n)
{
	if (Full2())
		throw "���� ��������";
	else
		NumLast2--;
	mas[NumLast2] = n;
}
