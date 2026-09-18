#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

template<class T>
void createArray(T**& arr, int row, int col)
{
	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new T[col];
	}
}

template<class T>
void setArray(T** arr, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

template<class T>
void printArray(T** arr, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void deleteArray(T**& arr, int row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}


int** multiplayMaxrix(int** a, int** b)
{
	int r1 = _msize(a) / sizeof(int*);
	int c1 = _msize(a[0]) / sizeof(int);

	int r2 = _msize(b) / sizeof(int*);
	int c2 = _msize(b[0]) / sizeof(int);

	if (c1 != r2)
	{
		return nullptr;
	}

	int** m = nullptr;
	createArray(m, r1, c2);

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			m[i][j] = 0;

			for (int k = 0; k < c1; k++)
			{
				m[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return m;
}я