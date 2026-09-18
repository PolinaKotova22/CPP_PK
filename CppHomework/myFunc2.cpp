#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7,
	DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12,
	LightMagenta = 13, Yellow = 14, White = 15
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

void setArray(int* arr, int size, int minValue = 0, int maxValue = 9)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
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

	cout << endl;
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
void addColArray(T**& arr, int row, int& col, int position, T* newCol = nullptr)
{
	T** temp = nullptr;

	createArray(temp, row, col + 1);

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < position; j++)
		{
			temp[i][j] = arr[i][j];
		}

		if (newCol != nullptr)
		{
			temp[i][position] = newCol[i];
		}
		else
		{
			temp[i][position] = 0;
		}

		for (size_t j = position; j < col; j++)
		{
			temp[i][j + 1] = arr[i][j];
		}
	}

	deleteArray(arr, row);

	arr = temp;
	col++;
}

template<class T>
void deleteColArray(T**& arr, int row, int& col, int position)
{
	T** temp = nullptr;

	createArray(temp, row, col - 1);

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < position; j++)
		{
			temp[i][j] = arr[i][j];
		}

		for (size_t j = position; j < col - 1; j++)
		{
			temp[i][j] = arr[i][j + 1];
		}
	}

	deleteArray(arr, row);

	arr = temp;
	col--;
}