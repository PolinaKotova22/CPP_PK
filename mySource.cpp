#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<conio.h>

#include<fstream>

#include"myFunc.h"
#include"myStruct.h"

using namespace std;

#define SIZE 100

#define PRINT cout
#define END_LINE endl

#define FOR for (size_t i = 0; i < 10; i++)

#define SQR(n) (n)*(n)

#define DEBUG

#define PI 3.141592

#define NoFound  "Value not found"


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout.setf(ios::boolalpha);
	SetColor(White, Black);
	system("cls");

	srand(time(0));


	/// 07.09.2026

	//int arr[SIZE];


	FOR
		PRINT << PI << END_LINE;

	cout << SQR(5 + 1) << endl;


#ifdef DEBUG
	int arr[SIZE];
#else
	int* arr = new int[SIZE];
#endif

	//#undef PI

	PRINT << PI << END_LINE;


	//int arr[] = { 132452345, 23452345, 546767, 5467567, 4575675 };
	//ofstream out("file.bin", ios::binary);
	//for (size_t i = 0; i < 5; i++)
	//{
	//	out.write((char*)&arr[i], sizeof(int));
	//}

	//int a = 4654654;
	//ofstream out("file2.bin", ios::binary);
	//out.write((char*)&a, 4);
	//out.write("Hello C++", 10);



	//ofstream out("points.bin");

	//Point p[5];
	//for (size_t i = 0; i < 5; i++)
	//{
	//	p[i].x = rand() % 10;
	//	p[i].y = rand() % 10;
	//	p[i].name = 'A' + i;

	//	p[i].print();

	//	//out << p[i].name << " " << p[i].x << " " << p[i].y << endl;
	//	out.write((char*)&p[i], sizeof(p[i]));
	//}
	//out.close();


	//Point* p = nullptr;
	//int size = 0;
	//ifstream in("points.bin", ios::binary);
	//Point a;
	//while (in.read((char*)&a, sizeof(Point)))
	//{
	//	addValueArray(p, size, a);
	//	a.print();
	//}


	//Human h = { new char[] {"Vasya"}, 16 };
	//ofstream out("h.bin", ios::binary);
	//out.write((char*)&h, sizeof(Human));
	//int len = strlen(h.name) + 1;
	//out.write((char*)&len, sizeof(int));
	//out.write(h.name, len);


	//Human h1;
	//ifstream in("h.bin", ios::binary);
	//in.read((char*)&h1, sizeof(Human));
	//int len;
	//in.read((char*)&len, sizeof(int));
	//h1.name = new char[len];
	//in.read(h1.name, len);

	//cout << h1.name << endl;
	//cout << h1.age << endl;


	//ifstream in("points.bin", ios::binary);
	//int n;
	//cin >> n;
	//in.seekg((n - 1) * sizeof(Point));
	//Point a;
	//in.read((char*)&a, sizeof(Point));
	//a.print();


	/// 04.09.2026


	//ofstream fout;
	//fout.open("file1.txt");
	//fout << "Hello C++" << endl;
	//fout.close();


	//ifstream fin;
	//fin.open("file11.txt");
	//char buffer[80];
	//if (fin.is_open())
	//{
	//	//fin >> buffer;
	//	fin.getline(buffer, 80);
	//	cout << buffer << endl;
	//}
	//else
	//{
	//	cout << "File not found!" << endl;
	//}
	//fin.close();


	//int arr[] = { 1,12,2,34,5,56,67,7,8, 1 };
	//ofstream out("file.txt");
	//for (size_t i = 0; i < 10; i++)
	//{
	//	out << arr[i] << " ";
	//}


	//int* arr = nullptr;
	//int size = 0;
	//ifstream in("file.txt");

	//int a;
	//while(in >> a)
	//{
	//	addValueArray(arr, size, a);
	//}

	//printArray(arr, size);


	//fstream out("points.txt");
	//Point p[5];
	//out << 5 << endl;
	//for (size_t i = 0; i < 5; i++)
	//{
	//	p[i].x = rand() % 10;
	//	p[i].y = rand() % 10;
	//	p[i].name = 'A' + i;

	//	p[i].print();

	//	out << p[i].name << " " << p[i].x << " " << p[i].y << endl;
	//}

	//Point* arr = nullptr;
	//int size = 0;
	//ifstream in("points.txt");

	//Point a;
	//while(in >> a.name >> a.x >> a.y)
	//{
	//	addValueArray(arr, size, a);
	//}


	//int size;
	//ifstream in("points.txt");
	//in >> size;

	//Point* p = new Point[size];
	//for (size_t i = 0; i < size; i++)
	//{
	//	in >> p[i].name;
	//	in >> p[i].x;
	//	in >> p[i].y;
	//}


	//for (size_t i = 0; i < size; i++)
	//{
	//	p[i].print();
	//}


	/// 03.07.2026

	//Point p;
	//p.print();


	//Car car;
	//car.beep();
	//car.move();


	//PhoneBook book;
	//book.menu();


	//cout << sizeof(Foo) << endl;



	//int a;
	//cin >> a;
	////cin.get();
	//cin.ignore();
	//char name[50];
	//cin.getline(name, 50);

	//cout << a << endl;
	//cout << name << endl;


	/// 01.07.2026

	//Point p;
	//p.name = 'A';
	//p.x = 10;
	//p.y = 12;

	//Point p1 = { 'B', 13, 5 };

	//Point p2[4];

	//printPoint(p);
	//printPoint(p1);
	//
	//Human h = { new char[] {"Vasya"}, {10, 2, 2000} };
	//h.bd.day = 10;

	//Point* p3 = new Point;
	//p3->x = 55;




	// "C++ C# SQL C++"
	// "C++"
	// " C# SQL "


	//cout << replaceWord("C++ C# SQL C++ Python", "C++", "") << endl;
	//cout << replaceWord("C++ C# SQL C++ Python", "C++", "*********") << endl;

	//int size = 5;
	//char** names = new char* [size];
	//char buffer[1024];
	//for (size_t i = 0; i < size; i++)
	//{
	//	cin.getline(buffer, 1024);
	//	int len = strlen(buffer);
	//	names[i] = new char[len + 1];
	//	strcpy_s(names[i], len + 1, buffer);
	//}
	//cout << endl;
	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << names[i] << endl;
	//}

	//bubbleSort(names, size, compareString);

	//cout << endl;
	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << names[i] << endl;
	//}

	/// 29.06.2026

	//char st[] = "Hello";//{ 'H', 'e', 'l', 'l', 'o', '\0'};
	//int a[5];
	//cout << a << endl;
	//cout << (void*)st << endl;
	//cout << lenStr(st) << endl;
	//cout << lenStr("mama") << endl;
	//cout << strlen("mama") << endl;


	//char buffer[1024];
	//cin.getline(buffer, 1024);
	//int len = strlen(buffer);
	//char* str = new char[len + 1];
	////strcpy_s(str, len + 1, buffer);
	//strcpy(str, buffer);
	//cout << str << endl;


	//cout << removeSymbol(str, 'a') << endl;



	//char st1[80], st2[80];
	//cout << "1: "; cin.getline(st1, 80);
	//cout << "2: "; cin.getline(st2, 80);

	//strcpy(st1, st2);
	//strncpy_s(st1, 80, st2, 3);

	//strcat(st1, st2);
	//strncat(st1, st2, 2);

	//cout << strcmp(st1, st2) << endl;
	//cout << strncmp(st1, st2, 3) << endl;
	//cout << _stricmp(st1, st2) << endl;
	//cout << _strnicmp(st1, st2, 3) << endl;

	//char* t = strchr(st1, 'a');
	//char* t = strrchr(st1, 'a');
	//char* t = strstr(st1, "ma");
	//if(t != nullptr)
	//	cout << t << endl;

	//_strset(st1, '*');

	//int a = atoi(st1);
	//long a = atol(st1);
	//double d = atof(st1);
	//cout << d << endl;

	//_itoa(765765, st1, 36);

	//cout << _strupr(st1) << endl;
	//cout << _strlwr(st1) << endl;

	//cout << isalnum('!') << endl;
	//cout << isdigit('!') << endl;
	//cout << isalpha('!') << endl;
	//cout << isspace('!') << endl;
	//cout << ispunct('!') << endl;
	//cout << isprint('!') << endl;
	//cout << isupper('!') << endl;
	//cout << islower('a') << endl;


	//cout << "1 : " << st1 << endl;
	//cout << "2 : " << st2 << endl;


	//cout << countWords("  jhkjh    kjh kjh kjh") << endl;
	//cout << isPalindrome("12343321") << endl;


	/// 26.06.2026


	//double** a;
	//a = new double*;
	//*a = new double(5);
	//cout << **a << endl; // 5


	//int size;
	//cin >> size;
	//int* arr = new int[size];
	//setArray(arr, size);
	//printArray(arr);
	//int*** a = createMatrix(arr);

	//print(a);


	/// 24.06.2026
	//int row, col;
	//cin >> row >> col;

	//int** p = nullptr;

	//createArray(p, row, col);
	//setArray(p, row, col);
	//printArray(p, row, col);

	//int* t = new int[row];
	//setArray(t, row);

	////addRowArray(p, row, col);
	//addColsArray(p, row, col, t);

	//delete[] t;

	//cout << endl;
	//printArray(p, row, col);

	//deleteArray(p, row);



	// *(*(p+i) + j) = p[i][j]


	//int a = 5;
	//int* p1 = &a;
	//int** p2 = &p1;

	//cout << *p1 << endl;
	//cout << p1 << endl;
	//cout << p2 << endl;
	//cout << *p2 << endl;
	//cout << **p2 << endl;

	/// 22.06.2026

	//int a, b, op;
	//int(*operation[])(int, int) = {sum};
	//cin >> a >> b;
	//cout << "1 +, 2 -, 3 *, 4 /" << endl;
	//cin >> op;
	//cout << operation[op - 1](a, b) << endl;





	//int len = 3400;
	//void(*director)() = prorab(len);
	//director();



	//int bullets[] = { 50, 50, 50 };
	//void(*shoot)(int*);
	//while (true)
	//{
	//	if (_kbhit())
	//	{
	//		int c = _getch();
	//		switch (c)
	//		{
	//		case ' ':
	//			shoot = selectWeapon(bullets);
	//			shoot(bullets);
	//			break;
	//		case 'a':
	//			arrow(bullets);
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//}



	//int size = 10;
	////cin >> size;
	//int* p = new int[size];
	//setArray(p, size);
	//printArray(p);
	//bublleSort(p, size, desc);
	//
	//forEach(p, size, print);
	//
	//printArray(p);



	// type (*name) (param)

	//void(*message)() = hello;

	//message();

	//message = goodbye;

	//message();

	//void(*func)(int, char) = starLine;

	//void(*message[])() = { hello, goodbye };
	//for (size_t i = 0; i < 2; i++)
	//{
	//	message[i]();
	//}


	/// 19.06.2026

	//int a = 5;
	//const int* pa = &a;
	//*pa = 99; non
	//int b = 77;
	//pa = &b;

	//int* const pa = &a;
	//*pa = 555;
	//pa = &b; non

	//const int* const pa = &a;

	//const int& rb = b;
	//rb = 99;


	//int a = 5;     int b = 8;
	//int* pa = &a;  int& rb = b;
	//*pa = 99;      rb = 88;

	//pa = &b;       rb = a;

	//inc(a);

	//char a = 8;
	//char* pa = &a;
	//cout << sizeof(pa) << endl;


	//int size;
	//cin >> size;
	//int* p = new int[size];
	//setArray(p, size);
	//printArray(p);


	//double d = 5.5;
	//double* pd = &d;

	//void* pv = p;
	//pv = pd;
	//*((double*)pv) = 5.6;



	//int* res = SumProdArray(p, size);

	//cout << res[0] << endl;




	//int M_1, N_1;

	//cout << "M: ";
	//cin >> M_1;
	//int* A = new int[M_1];
	//setArray(A, M_1);
	//SetColor(Blue, Black);
	//cout << "A: ";
	//printArray(A, M_1);
	//SetColor(White, Black);

	//cout << "N: ";
	//cin >> N_1;
	//int* B = new int[N_1];
	//setArray(B, N_1);
	//SetColor(Red, Black);
	//cout << "B: ";
	//printArray(B, N_1);

	//int* C = nullptr;
	//int C_1 = 0;

	//for (size_t i = 0; i < M_1; i++)
	//{
	//	if (findArray(B, N_1, A[i]) == -1 && findArray(C, C_1, A[i]) == -1)
	//	{
	//		addValueArray(C, C_1, A[i]);
	//		findArray(B, M_1, A[i]);
	//	}
	//}

	//SetColor(Green, Black);
	//printArray(C, C_1);

	/// 15.06.2026

	//int a = 5;
	//cout << a << endl;
	//cout << typeid(a).name() << endl;
	//cout << &a << endl;
	//cout << sizeof(a) << endl;

	//int* p = &a;
	//cout << p << endl;
	//cout << *p << endl;
	//*p = 999;
	//cout << a << endl;

	//float f = 5.35;
	//float* p1 = &f;


	// + - ++ --

	//p += 1; // p + n = p + n * type;
	//cout << p << endl;
	//cout << *p << endl;

	//int arr[4] = { 1,2,32,4 };
	//for (size_t i = 0; i < 4; i++)
	//{
	//	cout << *(arr + i) << endl; // *(arr + i) = arr[i]
	//}

	//cout << *(arr + 0)<< endl;
	//cout << *(arr + 1) << endl;
	//cout << *(arr + 2) << endl;
	//cout << *(arr + 3) << endl;

	// > < >= <= == != 

	//int b = -5;
	//int* pb = &b;
	//cout << pb << endl;
	//cout << (p == pb) << endl;

	//int c = 0;
	//int* pc = nullptr;
	//cout << c << endl;
	//cout << pc << endl;
	//if (pc == &b)
	//{
	//	pc = &c;
	//}


	//int arr[] = { 1,2,32,4 };

	//for (int* i = arr; i  != arr+4; i++)
	//{
	//	cout << *i << " ";
	//}

	//int size;
	//cin >> size;
	//int* p = new int[size];
	//setArray(p, size);
	//printArray(p, size);

	//p = addValueArray(p, &size, 999.f);

	//printArray(p, size);

	//p = delValueArray(p, &size);

	//printArray(p, size);

	//
	//int* temp = new int[size + 1];
	//for (size_t i = 0; i < size; i++)
	//{
	//	temp[i] = p[i];
	//}
	//temp[size] = 999;
	//delete[] p;
	//p = temp;
	//size++;

	//printArray(p, size);

	//delete[] p;



	//int a = 5;
	//inc(&a);
	//cout << a << endl;


	/// 08.06.2026


	//rec();


	//const int size = 10;
	//float arr[size];
	//setArray<float>(arr, size);
	//printArray(arr, size);
	////cout << maxValueArray(arr, size) << endl;

	//fff<int>();

	//cout << Sum(3, 5.5) << endl;
	//cout << Sum(3.5, 5) << endl;
	//cout << Sum(3.5, 5.5) << endl;
	//cout << Sum(3, 'a', 2.5) << endl;

	//auto a = 10 + 3.5;

	//int c = 9;

	//a = 3.5;

	//decltype(a + c) b;

	//auto m = 'c';



	/// 05.06.2026

	// arr[..][..][metagalaxy][galaxy][system][planet][continent][country][city][street][house][number]

	//starLine();
	//starLine(30);
	//starLine(20, '#');


	////cout << avg3(3, 4, 6) << endl;

	////size array
	//const int size = 20;
	//int arr[size];
	//setArray(arr, size);
	//printArray(arr, size);
	////bublleSort(arr, size);
	////printArray(arr, size);
	//cout << findArray(arr, size, 110) << endl;

	//int ind;

	//cout << ind << endl;
	//cout << arr[ind] << endl;

	//int max;


	//f(1010101);
	//ff(87) // 100011101

	/// 01.06.2026

	//int min = 1, max = 100;
	//const int row = 5, col = 5;
	//int a[row][col];

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		a[i][j] = rand() % (max - min + 1) + min;
	//	}
	//}

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		bool flag = false;
	//		while (!flag)
	//		{
	//			int r = rand() % (max - min + 1) + min;
	//			for (size_t k = 0; k < row; k++)
	//			{
	//				for (size_t m = 0; m < col; m++)
	//				{
	//					if (a[k][m] == r)
	//					{
	//						flag = true;
	//					}
	//				}
	//			}
	//			if (!flag)
	//			{
	//				a[i][j] = r;
	//				break;
	//			}
	//			flag = false;
	//		}
	//	}
	//}



	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << setw(4) << a[i][j];
	//	}
	//	cout << endl;
	//}


	//int maxV = a[0][0];
	//int minV = a[0][0];
	//int iMin = 0, iMax = 0, jMin = 0, jMax = 0;
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		if (a[i][j] > maxV)
	//		{
	//			maxV = a[i][j];
	//			iMax = i;
	//			jMax = j;
	//		}
	//		if (a[i][j] < minV)
	//		{
	//			minV = a[i][j];
	//			iMin = i;
	//			jMin = j;
	//		}
	//	}
	//}


	//int s = 0;
	//for (size_t i = iMin; i <= iMax; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		if (i == iMin && j > jMin || i == iMax && j < jMax || i > iMin && i < iMax)
	//		{
	//			s += a[i][j];
	//		}
	//	}
	//}

	//cout << s << endl;


	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		//if (a[i][j] == maxV)
	//		//{
	//		//	SetColor(Red, Black);
	//		//}
	//		//else if (a[i][j] == minV)
	//		//{
	//		//	SetColor(Green, Black);
	//		//}
	//		//else
	//		//{
	//		//	SetColor(White, Black);
	//		//}

	//		SetColor((a[i][j] == maxV) ? Red : (a[i][j] == minV) ? Green : White, Black);

	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	/// 29.05.2026

	//const int size = 10;

	//int a[size]; // = {}; // = { 1,2,3,4,5 };

	////int count = 0;
	//int min = 0, max = 10;
	//for (size_t i = 0; i < size; i++)
	//{
	//	a[i] = rand() % (max - min + 1) + min;
	//	//cin >> a[i];
	//}

	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;


	//for (size_t i = 0; i < size - 1; i++)
	//{
	//	for (size_t j = 0; j < size - 1 - i; j++)
	//	{
	//		if (a[j] > a[j + 1])
	//		{
	//			swap(a[i], a[i + 1]);
	//		}
	//	}
	//}

	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;

	//for (size_t i = 0; i < size / 2; i++)
	//{
	//	int t = a[i];
	//	a[i] = a[size - 1 - i];
	//	a[size - 1 - i] = t;
	//}
	//cout << endl;

	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;


	//for (int i = size - 1; i >= 0; i--)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;

	//int t = a[0];
	//a[0] = a[size - 1];
	//a[size - 1] = t;

	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;

	//int maxValue = a[0];
	//int index = 0;
	//for (size_t i = 1; i < size; i++)
	//{
	//	if (a[i] >= maxValue) 
	//	{
	//		maxValue = a[i];
	//		index = i;
	//	}
	//}
	//cout << maxValue << endl;
	//cout << index << endl;


	//int b[size];
	//int j = 0;
	//for (size_t i = 0; i < size; i++)
	//{
	//	if (a[i] % 2 == 0) 
	//	{
	//		b[j++] = a[i];
	//	}
	//}

	//for (size_t i = 0; i < j; i++)
	//{
	//	cout << b[i] << " ";
	//}
	//cout << endl;







	//for (size_t i = 0; i < size; i++)
	//{
	//	if (a[i] % 2 == 0)
	//	{
	//		count++;
	//	}
	//}
	//cout << count << endl;


	/// 25.05.2026

	//int a, sum = 0;
	//do
	//{
	//	cin >> a; 
	//	sum += a;
	//} while (a != 0);
	//cout << sum << endl;

	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << rand() % 10 + 10 << endl;
	//}




	//typedef unsigned char Pupsik;
	//Pupsik t;


	/// 22.05.2026

	//Дано  — цена 1 кг конфет.Вывести стоимость 0.1,
	//	0.2, ..., 1 кг конфет.



	//Дано вещественное число A и целое число N(> 0).Используя один
	//	цикл, вывести все целые степени числа A от 1 до N.


	//float a, res;
	//cin >> a;
	//res = a;

	//int n = 10;
	//for (size_t i = 0; i < n; i++)
	//{
	//	cout << res << endl;
	//	res *= a;
	//}
	//cout << "---- 1 ----" << endl;
	//SetColor(White, Black);
	//cout << " Mo Tu We TH Fr";
	//SetColor(White, LightRed);
	//cout << " Sa Su" << endl;
	//SetColor(Black, White);
	//int k = 3;
	//for (int d = 1 - k; d <= 31; d++)
	//{
	//	if (d <= 0)
	//		cout << "   ";
	//	else
	//	{
	//		SetColor(((d + k) % 7 == 6 || (d + k) % 7 == 0) ? LightRed : Black, White);
	//		cout << setw(3) << d;
	//		if ((d + k) % 7 == 0)
	//			cout << endl;
	//	}
	//}



	//while (5)
	//{

	//}

	//for (size_t i = 1; i <= 10; i++)
	//	cout << i << endl;
	//

	//int i = 1;
	//while (i <= 10)
	//	cout << i++ << endl;
	//

	//do
	//{

	//} while (true);


	/// 18.05.2026

	//(condition) ? oper1 : oper2;

	//int a = 5, b = 4,c = 3, max;
	//if (a > b)
	//{
	//	max = a;
	//}
	//else
	//{
	//	max = b;
	//}

	//(a > b) ? max = a : max = b;

	//max = (a > b) ? a : b;

	//max = (a > b && a > c) ? a : (b > c) ? b : c;



	//int a, b, c;
	//cin >> a >> b >> c;

	//if (a % 2 == 0)
	//{
	//	cout << "a is even" << endl;
	//}
	//else
	//{
	//	cout << "a is odd" << endl;
	//}

	// 3 1 2
	//if (a > b && a > c)
	//{
	//	cout << a << endl;
	//}
	//else if (b > c)
	//{
	//	cout << b << endl;
	//}
	//else
	//{
	//	cout << c << endl;
	//}

	// 2+3

	//float a, b;
	//char op;
	//cin >> a >> op >> b;

	//switch (op)
	//{
	//case '+': cout << a + b << endl; break;
	//case '-': cout << a - b << endl; break;
	//case '*': cout << a * b << endl; break;
	//case '/': cout << a / b << endl; break;
	//default: 
	//	cout << "Error. Use correct symbol (+, -, *, /)" << endl;
	//	break;	
	//}

	//if (op == '+')
	//{
	//	cout << a + b << endl;
	//}
	//else if (op == '-')
	//{
	//	cout << a - b << endl;
	//}
	//else if (op == '*')
	//{
	//	cout << a * b << endl;
	//}
	//else if (op == '/')
	//{
	//	cout << a / b << endl;
	//}
	//else
	//{
	//	cout << "Error. Use correct symbol (+, -, *, /)" << endl;
	//}


	//int m;
	//cin >> m;
	//switch (m) {
	//case 1: case 2: case 12: cout << "Winter"; break;
	//case 3: case 4:	case 5:  cout << "Spring"; break;

	//case 6: cout << "Summer"; break;
	//case 7: cout << "Summer"; break;
	//case 8: cout << "Summer"; break;

	//case 9: cout << "Autumn"; break;
	//case 10: cout << "Autumn"; break;
	//case 11: cout << "Autumn"; break;
	//default: cout << "Error" << endl;
	//}
	//return 0;





	//cout << "Hello \\World\\!\n" << endl;
	//cout << "Мене звати Сергій" << endl;
	//cout << 125 << endl;
	//cout << 125.354 << endl;
	//cout << true << endl;


	// type name;

	// bool  - 1b

	// char  - 1b

	// short - 2b
	// int   - 4b
	// long  - 4b
	// long long - 8b

	// float  - 4b (7 digits)
	// double - 8b (15 digits)
	// long double - 16b (19 digits)

	//const int a = 5;
	//cout << a << endl;

	//int x = 5.99;
	//cout << x << endl;

	//char t = 'a';
	//cout << (char)(t + 3.5) << endl;

	//cout << 5 / 3 << endl;


	//unsigned int b = 3000000000;
	//cout << b << endl;

	// _

	// - + ++ --
	// + - * / % += -= *= /= %= 
	// !
	// < > <= >= == != && ||
	// () [] {} :: ~ ?: -> . ,

	//int a = 5, b = 4, c;
	//c = a++ * (--b + a-- / ++b);
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;

	//cout << 10 % 5 << endl;

	//a = a + b;
	//a += b; 

	//cout << (int)(15.2 / 4) << endl;

	//c = !a;
	//cout << c << endl;

	//int a, b;
	//cin >> a;
	//cin >> b;
	//float c = (a + b) / 2.f;
	//cout << "Середнє арифметичне: " << c << endl;

	//cout << pow(2.2, 3.258) << endl;;

	//printf("Hello %d World!\n", 5);

	return 0;
}