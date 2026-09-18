#include<iostream>
#include<Windows.h>
#include<iomanip>

#include"Func.h"

using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	SetColor(Black, White);
	system("cls");
	srand(time(0));


	//  1 завдання

	int row = 3, col = 4;
	int** arr = nullptr;

	createArray(arr, row, col);
	setArray(arr); 
	printArray(arr);

	transposeMatrix(arr, row, col);

	printArray(arr);

	deleteArray(arr, row);

}