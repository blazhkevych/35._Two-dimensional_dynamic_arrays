#include <iostream>
#include <iomanip>
#include "OneDimensionalArray.h"

using namespace std;

//  функция создания двумерного динамического массива
int** Allocate(int rows, int cols)
{
	int** ptr = new int* [rows];
	for (int i = 0; i < rows; i++)
		ptr[i] = new int[cols];
	return ptr;
}

// функция удаления двумерного динамического массива
void Free(int** p, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] p[i];
	delete[] p;
}

// функция инициализации массива
void Init(int** p, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			p[i][j] = rand() % 41 - 20;
	}
}

// функция печати массива
void Print(int** p, int rows, int cols)
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << setw(5) << p[i][j];
		cout << endl;
	}
	cout << endl;
}

// функция добавления строки (одномерного массива) в конец двухмерного массива
int** AddStringEnd(int** p, int* rows, int cols, const int* mas)
{
	int** ptr = new int* [++ * rows];
	for (int i = 0; i < *rows - 1; i++)
		ptr[i] = p[i];
	ptr[*rows - 1] = new int[cols];
	for (int i = 0; i < cols; i++)
		ptr[*rows - 1][i] = mas[i];
	delete[] p;
	return ptr;
}

// функция добавления строки (одномерного массива) в начало двухмерного массива
int** AddStringBegin(int** p, int* rows, int cols, const int* mas)
{
	int** ptr = new int* [++ * rows];
	int j{ 1 };
	for (int i = 0; i < *rows - 1; i++)
	{
		ptr[j] = p[i];
		j++;
	}
	ptr[0] = new int[cols];
	for (int i = 0; i < cols; i++)
		ptr[0][i] = mas[i];
	delete[] p;
	p = nullptr;
	return ptr;
}

// функция вставки строки (одномерного массива) в указанную позицию двухмерного массива
int** InsertString(int** p, int* rows, int cols, int index, const int* mas)
{
	if (index >= *rows || index < 0)
		return p;
	int** ptr = new int* [++ * rows];
	ptr[index] = new int[cols];
	int k = 0;
	for (int i = 0; i < cols; i++)
		ptr[index][i] = mas[i];
	for (int i = 0; i < *rows; i++)
	{
		if (i == index)
			k = 1;
		else
			ptr[i] = p[i - k];
	}
	delete[] p;
	return ptr;
}

// Функция, удаляющая строку (одномерный массив) в двумерном динамическом массиве по указанному индексу.
int** DeleteString(int** p, int* rows, int cols, int index)
{
	if (index >= *rows || index < 0)
		return p;
	int** ptr = new int* [-- * rows];
	int j = 0;
	for (int i = 0; i < *rows; i++)
	{
		if (i == index)
		{
			j++;
			ptr[i] = p[j];
		}
		else if (j < index)
		{
			ptr[i] = p[j];
			j++;
		}
		else if (j > index)
		{
			j++;
			ptr[i] = p[j];
		}
	}
	Free(p[index]);
	delete[] p;
	p = nullptr;
	return ptr;
}

//  функция добавления столбца (одномерного массива) в конец двухмерного массива
int** AddColumnEnd(int** p, int rows, int* cols, const int* mas)
{
	++* cols;
	int** ptr = Allocate(rows, *cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < *cols - 1; j++)
			ptr[i][j] = p[i][j];
		ptr[i][*cols - 1] = mas[i];
	}
	Free(p, rows);
	return ptr;
}

//  функция добавления столбца (одномерного массива) в начало двухмерного массива
int** AddColumnBegin(int** p, int rows, int* cols, const int* mas)
{
	++* cols;
	int** ptr = Allocate(rows, *cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < *cols - 1; j++)
			ptr[i][j + 1] = p[i][j];
		ptr[i][0] = mas[i];
	}
	Free(p, rows);
	return ptr;
}

// функция вставки столбца (одномерного массива) в указанную позицию двухмерного массива
int** InsertColumn(int** p, int rows, int* cols, int index, const int* mas)
{
	if (index < 0 || index >= *cols)
		return p;
	int k;
	++* cols;
	int** ptr = Allocate(rows, *cols);
	for (int i = 0; i < rows; i++)
		ptr[i][index] = mas[i];
	for (int i = 0; i < rows; i++)
	{
		k = 0;
		for (int j = 0; j < *cols; j++)
		{
			if (j == index)
				k = 1;
			else
				ptr[i][j] = p[i][j - k];
		}
	}
	Free(p, rows);
	return ptr;
}

// функция удаления столбца (одномерного массива) по указанному индексу двухмерного массива
int** DeleteColumn(int** p, int rows, int* cols, int index)
{
	if (index < 0 || index >= *cols)
		return p;
	--* cols;
	int** ptr = Allocate(rows, *cols);
	int k{ 0 };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			if (j == index)
			{
				k++;
				ptr[i][j] = p[i][k];
			}
			else if (j < index)
			{
				ptr[i][j] = p[i][k];
				k++;
			}
			else if (j > index)
			{
				k++;
				ptr[i][j] = p[i][k];
			}
		}
		k = 0;
	}

	Free(p, rows);

	return ptr;
}