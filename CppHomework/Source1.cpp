#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<conio.h>

#include"myFunc.h"
#include"myStruct.h"

using namespace std;


int main()
{
	// завдання 3

	const int size = 10;

	int arr[size];

	setArray(arr, size, -20, 20);

	cout << " ";
	printArray(arr, size);

	int plusSize = 0;
	int minusSize = 0;
	int zeroSize = 0;

	int* plus = nullptr;
	int* minus = nullptr;
	int* zero = nullptr;

	splitArray(arr, size, plus, plusSize, minus, minusSize, zero, zeroSize);

	cout << "plus: ";
	printArray(plus, plusSize);

	cout << "minus: ";
	printArray(minus, minusSize);

	cout << "zero: ";
	printArray(zero, zeroSize);

	deleteArray(plus);
	deleteArray(minus);
	deleteArray(zero);

	return 0;
}