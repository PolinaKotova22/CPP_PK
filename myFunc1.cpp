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

//type name(param)
//{
//	body;
//}


inline void starLine(int size = 10, char symbol = '*')
{
	for (size_t i = 0; i < size; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

template<class T>
double avg3(T a, T b, T c)
{
	return (a + b + c) / 3.;
}


template<class T>
void printArray(T arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void setArray(T* arr, int size, T minValue = 0, T maxValue = 9)
{
	//cout << "template setArray" << endl;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = T();
	}
}



void setArray(int arr[], int size, int minValue = 0, int maxValue = 9)
{
	//cout << "int setArray" << endl;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
	}
}
template<class T>
bool asc(const T& a, const T& b)
{
	return a > b;
}

template<class T>
bool desc(const T& a, const T& b)
{
	return a < b;
}

template<class T>
bool equals(const T& a, const T& b)
{
	return a == b;
}

template<class T>
void bubbleSort(T* arr, int size, bool(*method)(const T&, const T&) = asc)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (method(arr[j], arr[j + 1]))
				swap(arr[j], arr[j + 1]);
		}
	}
}

template<class T>
int findArray(T* arr, int size, const T& key, bool(*comparer)(const T&, const T&) = equals)
{
	for (size_t i = 0; i < size; i++)
	{
		if (comparer(arr[i], key))
		{
			return i;
		}
	}

	return -1;
}

template<class T>
T maxValueArray(T* arr, int size)
{
	T maxValue = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}
	}
	return maxValue;
}

template<class T>
int countValueArray(T* arr, int size, const T& key)
{
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			count++;
		}
	}
	return count;
}

template<class T1, class T2, class T3>
auto Sum(T1 a, T2 b, T3 c) -> decltype(a + b)
{
	return a + b + c;
}


void rec()
{
	static int a = 0;
	a++;
	rec();
}

void inc(int& a)
{
	++a;
}

template<class T>
void addValueArray(T*& arr, int& size, T value)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

int* SumProdArray(int* arr, int size)
{
	int* res = new int[2] {0, 1};

	for (size_t i = 0; i < size; i++)
	{
		res[0] += arr[i];
		res[1] *= arr[i];
	}

	return res;
}

template<class T>
void printArray(T* arr)
{
	int block = _msize(arr);
	int size = block / sizeof(T);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void forEach(T* arr, int size, void(*func)(T&))
{
	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}


void kopatel1()
{
	//
	cout << "Копає один робітник з лопатою" << endl;
}


void kopatel3()
{
	cout << "Копають три робітника з лопатами і кірками" << endl;
}

void exkavator()
{
	cout << "Копає екскаватор, робітники курять в сторонці.. ))" << endl;
}

void(*prorab(int len))()
{
	if (len <= 100)
	{
		return kopatel1;
	}
	else if (len <= 500)
	{
		return kopatel3;
	}
	else
	{
		return exkavator;
	}
}


void pistol(int* bullets)
{
	cout << "->" << endl;
	bullets[0]--;
}

void gun(int* bullets)
{
	cout << "-> -> -> -> -> " << endl;
	bullets[1] -= 5;
}

void arrow(int* bullets)
{
	cout << ">>----->" << endl;
	bullets[2] -= 1;
}


void(*selectWeapon(int* bullets))(int*)
{
	void(*weapons[])(int*) = { pistol, gun, arrow };

	return weapons[findArray(bullets, 3, maxValueArray(bullets, 3))];
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
void addRowArray(T**& arr, int& row, int col, T* newRow = nullptr)
{
	T** temp = new T * [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		temp[i] = arr[i];
	}

	temp[row] = new T[col];
	for (size_t i = 0; i < col; i++)
	{
		temp[row][i] = (newRow != nullptr) ? newRow[i] : 0;
	}

	delete[] arr;
	row++;
	arr = temp;
}


template<class T>
void addColsArray(T**& arr, int row, int& col, T* newCol = nullptr)
{
	for (size_t i = 0; i < row; i++)
	{
		addValueArray(arr[i], col, newCol[i]);
		col--;
	}
	col++;
}


int*** createMatrix(int* arr)
{
	int size = _msize(arr) / sizeof(int);
	int count = 0;
	for (size_t i = 2; i < size; i++)
	{
		if (size % i == 0)
		{
			count++;
		}
	}

	int*** m = new int** [count];
	int k = 0;
	for (size_t i = 2; i < size; i++)
	{
		if (size % i == 0)
		{
			int row = i;
			int col = size / i;
			createArray(m[k], row, col);
			for (size_t j = 0; j < size; j++)
			{
				m[k][j / col][j % col] = arr[j];
			}
			k++;
		}
	}
	return m;
}

void print(int*** arr)
{
	int count = _msize(arr) / sizeof(int**);
	for (size_t k = 0; k < count; k++)
	{
		int row = _msize(arr[k]) / sizeof(int*);
		int col = _msize(arr[k][0]) / sizeof(int);
		printArray(arr[k], row, col);
		cout << endl;
	}
}

int** multiplayMaxrix(int** a, int** b)
{
	int r1 = _msize(a) / sizeof(int*);
	int c1 = _msize(a[0]) / sizeof(int);

	int r2 = _msize(b) / sizeof(int*);
	int c2 = _msize(b[0]) / sizeof(int);

	int** m = nullptr;
	createArray(m, r1, c2);

	return nullptr;

}

int lenStr(const char* str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}


char* removeSymbol(char* str, char symb)
{
	int size = strlen(str);
	int len = countValueArray(str, size, symb);
	char* temp = new char[size - len + 1];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != symb)
		{
			temp[k++] = str[i];
		}
	}
	temp[size - len] = '\0';

	return temp;
}


int countWords(const char* str) {
	int count = 0;
	bool inWord = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isspace(str[i])) {
			inWord = false;
		}
		else {
			if (!inWord) {
				count++;
				inWord = true;
			}
		}
	}

	return count;
}

bool isPalindrome(const char* st)
{
	int size = strlen(st);
	for (size_t i = 0; i < size / 2; i++)
	{
		if (st[i] != st[size - 1 - i])
			return false;
	}
	return true;
}

char* deleteWord(const char* st, const char* word)
{
	const char* p;
	int lenWord = strlen(word);
	char* newStr = new char[strlen(st) + 1];
	newStr[0] = '\0';
	while ((p = strstr(st, word)) != nullptr)
	{
		strncat(newStr, st, p - st);
		st = p + lenWord;
	}
	strcat(newStr, st);
	return newStr;
}


char* replaceWord(const char* st, const char* _old, const char* _new)
{
	const char* p;
	int lenWord = strlen(_old);
	char* newStr = new char[8000];
	newStr[0] = '\0';
	while ((p = strstr(st, _old)) != nullptr)
	{
		strncat(newStr, st, p - st);
		strcat(newStr, _new);
		st = p + lenWord;
	}
	strcat(newStr, st);

	char* temp = new char[strlen(newStr) + 1];
	strcpy(temp, newStr);
	delete newStr;

	return temp;
}

void hello()
{
	cout << "Hello" << endl;
}

void goodbye()
{
	cout << "Goodbye" << endl;
}

void mult10(int& a)
{
	a *= 10;
}

void print(int& a)
{
	cout << a << " ";
}

int sum(int a, int b)
{
	return a + b;
}


bool compareString(char* const& s1, char* const& s2)
{
	return strcmp(s1, s2) > 0;
}

class Area
{
private:
	static int count;

public:
	static double triangle(double a, double h)
	{
		count++;
		return a * h / 2;
	}

	static double rectangle(double a, double b)
	{
		count++;
		return a * b;
	}

	static double square(double a)
	{
		count++;
		return a * a;
	}

	static double rhombus(double d1, double d2)
	{
		count++;
		return d1 * d2 / 2;
	}

	static int getCount()
	{
		return count;
	}
};

int Area::count = 0;
