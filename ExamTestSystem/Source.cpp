#define _CRT_SECURE_NO_WARNINGS
#include "TestSystemApp.h"

#include<iostream>
#include<Windows.h>
#include<vector>
#include<array>



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitleA("Система тестування");

	TestSystemApp app;
	app.menu();

	return 0;
}