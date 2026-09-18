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

template<class T>
void transposeMatrix(T**& arr, int& row, int& col)
{
	T** temp = nullptr;
	createArray(temp, col, row);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp[j][i] = arr[i][j];
		}
	}

	deleteArray(arr, row);

	arr = temp;

	int tempSize = row;
	row = col;
	col = tempSize;
}