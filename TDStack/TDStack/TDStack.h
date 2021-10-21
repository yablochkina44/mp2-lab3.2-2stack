#pragma once

template <class T>
class TDStack
{
private:
	int MaxSize; // размер
	int NumLast1; // номер последнего элемента 1 стека
	int NumLast2; // номер последнего элемента 2 стека
	T* mas;   // массив

public:
	TDStack(int _Size = 10)
	{
		if ((_Size <= 0) || (_Size > 1000))
		{
			throw "Некоректный размер стека";
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


	bool Empty1();              //проверка на пустоту
	bool Empty2();
	bool Full1();               //проверка на полноту
	bool Full2();
	void Clear1();              //очистка стека
	void Clear2();

	T Top1();                   //посмотреть последний элемент
	T Top2();
	T Pop1();                   //взять последний элемент
	T Pop2();
	void Push1(const T& n);     //положить элемент
	void Push2(const T& n);     //положить элемент 
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
	//исключение если нечего смотреть
	if (Empty1())
		throw "Стек пуст";
	else
		return mas[NumLast1];
}
template <class T>
T TDStack<T>::Top2()
{
	//исключение если нечего смотреть
	if (Empty2())
		throw "Стек пуст";
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
		throw "Стек заполнен";
	else
		NumLast1++;
	mas[NumLast1] = n;
}
template <class T>
void TDStack<T>::Push2(const T& n)
{
	if (Full2())
		throw "Стек заполнен";
	else
		NumLast2--;
	mas[NumLast2] = n;
}
