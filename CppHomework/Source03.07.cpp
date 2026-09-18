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

	const int size = 10;

	Book books[size] =
	{
		{"KaidashevaSimia", "NechuiLevytskyi", "Osnovy", "Comedy"},
		{"ZaharBerkut", "Franko", "Vivat", "Historical"},
		{"LisovaPisnia", "Ukrainka", "Smoloskyp", "Fantasy"},
		{"Tigrolovy", "Bahrianyi", "Chas", "Adventure"},
		{"Misto", "Pidmohylnyi", "Knyholev", "Urban"},
		{"ChornaRada", "Kulish", "Folio", "Historical"},
		{"Eneida", "Kotliarevskyi", "AbaBaHaLaMaHa", "Satire"},
		{"MarusiaChurai", "Kostenko", "Lybid", "Drama"},
		{"ShadowsOfForgottenAncestors", "Kotsiubynskyi", "Folio", "Drama"},
		{"Kateryna", "Shevchenko", "Osnovy", "Poem"}
	};

	cout << "Всі книги:" << endl;
	printBooks(books, size);


	cout << endl;
	cout << "Пошук за автором:" << endl;
	findByAuthor(books, size);


	cout << endl;
	cout << "Пошук за назвою:" << endl;
	findByName(books, size);


	return 0;
}