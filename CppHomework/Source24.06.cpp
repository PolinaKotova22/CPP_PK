#include<iostream>
#include<Windows.h>
#include<iomanip>

#include"Func.h"

using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	SetColor(White, Black);
	system("cls");
	srand(time(0));


	//Завдання 1. 
	///Написати функцію, що додає стовпчик двовимірному масиву в зазначену позицію.

	int row = 3;
	int col = 4;

	int** arr = nullptr;

	createArray(arr, row, col);
	setArray(arr, row, col);

	cout << "початк. масив:" << endl;
	printArray(arr, row, col);

	int* newCol = new int[row];
	setArray(newCol, row, 1, 9);

	int position = 2;

	addColArray(arr, row, col, position, newCol);

	cout << "масив після додав. стовпчика:" << endl;
	printArray(arr, row, col);

	delete[] newCol;


	///завдання 2
	/// Написати функцію, що видаляє стовпчик двовимірного масиву за вказаним номером.
	///

	int deletePosition = 3;

	deleteColArray(arr, row, col, deletePosition);

	cout << "Масив після видалення стовпчика:" << endl;
	printArray(arr, row, col);

	deleteArray(arr, row);

	return 0;
} 