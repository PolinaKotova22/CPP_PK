#define _CRT_SECURE_NO_WARNINGS
#include "TestSystemApp.h"

#include<iostream>
#include<Windows.h>
#include<vector>
#include<array>



int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	SetConsoleTitleA("Система тестування");

	TestSystemApp app;
	app.menu();

	return 0;
}
