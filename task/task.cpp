#include <iostream>
#include "TwoDimensionalArray.h"
#include "OneDimensionalArray.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	char answer{ 0 }; // Do you want to continue?
	int choice{ 0 }; // Выбор задания
	do
	{
		cout << "Enter task number:: "
			<< "\nTask 1."
			<< "\nTask 2."
			<< "\nTask 3."
			<< "\nTask 4."
			<< endl << endl;
		cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1:
		{
			/*
			1. Написать функцию, добавляющую строку (одномерный массив) в
			начало двумерного динамического массива.
			*/
			//2:46:15
			srand(time(0));
			int** ptr, rows, cols;
			cout << "Enter quantity of rows and cols: ";
			cin >> rows >> cols;

			ptr = Allocate(rows, cols);
			Init(ptr, rows, cols);
			Print(ptr, rows, cols);

			int* mas = Allocate(cols);
			Init(mas, cols);
			Print(mas, cols);

			ptr = AddStringBegin(ptr, &rows, cols, mas);
			Print(ptr, rows, cols);

			Free(mas);
			Free(ptr, rows);
		}
		break;

		case 2:
		{
			/*
			2. Написать функцию, удаляющую строку (одномерный массив) в
			двумерном динамическом массиве по указанному индексу.
			*/
			//1:13:40 удаление двумерного массива
			srand(time(0));
			int** ptr, rows, cols, index;
			cout << "Enter quantity of rows and cols: ";
			cin >> rows >> cols;

			ptr = Allocate(rows, cols);
			Init(ptr, rows, cols);
			Print(ptr, rows, cols);

			cout << "Enter an index to delete: ";
			cin >> index;

			ptr = DeleteString(ptr, &rows, cols, index);
			Print(ptr, rows, cols);

			Free(ptr, rows);
		}
		break;

		case 3:
		{
			/*
			3. Написать функцию, добавляющую столбец в начало двумерного
			динамического массива.
			*/
			//2:47:28
			srand(time(0));
			int** ptr, rows, cols;
			cout << "Enter quantity of rows and cols: ";
			cin >> rows >> cols;

			ptr = Allocate(rows, cols);
			Init(ptr, rows, cols);
			Print(ptr, rows, cols);

			int* mas = Allocate(rows);
			Init(mas, rows);
			Print(mas, rows);

			ptr = AddColumnBegin(ptr, rows, &cols, mas);
			Print(ptr, rows, cols);

			Free(ptr, rows);
			Free(mas);
		}
		break;

		case 4:
		{
			/*
			4. Написать функцию, удаляющую столбец в двумерном динамическом
			массиве по указанному индексу.
			*/
			//2:48:07
			srand(time(0));
			int** ptr, rows, cols, index;
			cout << "Enter quantity of rows and cols: ";
			cin >> rows >> cols;

			ptr = Allocate(rows, cols);
			Init(ptr, rows, cols);
			Print(ptr, rows, cols);

			cout << "Enter an index to delete: ";
			cin >> index;

			ptr = DeleteColumn(ptr, rows, &cols, index);
			Print(ptr, rows, cols);

			Free(ptr, rows);
		}
		break;
		case 5:
		{
			/*
			5. Написать функцию, копирующую двумерный динамический массив в
			одномерный динамический массив.
			*/
			//2:48:35
			srand(time(0));
			int** ptr, rows, cols;
			cout << "Enter quantity of rows and cols: ";
			cin >> rows >> cols;

			ptr = Allocate(rows, cols);
			Init(ptr, rows, cols);
			Print(ptr, rows, cols);

			int* mas = Copies2DimDynArrTo1DimDynArr(ptr, rows, cols);

			Free(ptr, rows);

			for (int i = 0; i < rows * cols; i++)
			{
				cout << mas[i] << ' ';
			}

			Free(mas);
		}
		break;
		}

		cout << endl;
		cout << "Do you want to continue? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	return 0;
}