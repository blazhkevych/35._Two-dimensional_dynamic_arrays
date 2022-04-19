#include <iostream>
#include "lib.h"
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

		}
		break;

		case 2:
		{
			/*
			2. Написать функцию, удаляющую строку (одномерный массив) в
			двумерном динамическом массиве по указанному индексу.
			*/

		}
		break;

		case 3:
		{
			/*
			3. Написать функцию, добавляющую столбец в начало двумерного
			динамического массива.
			*/

		}
		break;

		case 4:
		{
			/*
			4. Написать функцию, удаляющую столбец в двумерном динамическом
			массиве по указанному индексу.
			*/

		}
		break;
		case 5:
		{
			/*
			5. Написать функцию, копирующую двумерный динамический массив в
			одномерный динамический массив.
			*/

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