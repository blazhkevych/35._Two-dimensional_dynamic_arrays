#include <iostream>
#include <iomanip>
using namespace std;

// функция инициализации массива
void Init(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*ptr = rand() % 100;
		ptr++;
	}
}

// функция печати массива
void Print(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << ptr[i];
	}
	cout << endl;
}

// функция создания динамического массива
int* Allocate(int size)
{
	return new int[size];
}

// функция удаления динамического массива
void Free(int* ptr)
{
	delete[] ptr;
}