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

	int** a = nullptr;
	int row_a = 4, col_a = 2;

	createArray(a, row_a, col_a);
	setArray(a, row_a, col_a);

	cout << "A:" << endl;
	printArray(a, row_a, col_a);

	int** b = nullptr;
	int row_b = 2, col_b = 3;

	createArray(b, row_b, col_b);
	setArray(b, row_b, col_b);

	cout << "B:" << endl;
	printArray(b, row_b, col_b);

	int** c = multiplayMaxrix(a, b);

	cout << "C:" << endl;
	printArray(c, row_a, col_b);

	deleteArray(a, row_a);
	deleteArray(b, row_b);
	deleteArray(c, row_a);

	return 0;
}