﻿#include <iostream>
#include <iomanip>
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
