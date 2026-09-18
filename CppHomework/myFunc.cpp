#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

template<class T>
void deleteArray(T*& arr)
{
	delete[] arr;
	arr = nullptr;
}

void splitArray(int* arr, int size,
	int*& plus, int& plusSize,
	int*& minus, int& minusSize,
	int*& zero, int& zeroSize)
{
	plus = new int[size];
	minus = new int[size];
	zero = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
			plus[plusSize++] = arr[i];
		else if (arr[i] < 0)
			minus[minusSize++] = arr[i];
		else
			zero[zeroSize++] = arr[i];
	}
}