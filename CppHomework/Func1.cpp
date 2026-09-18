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


struct Book
{
	char name[100];
	char author[100];
	char publisher[100];
	char genre[100];
};


void printBook(Book& book)
{
	cout << "Назва: " << book.name << endl;
	cout << "Автор: " << book.author << endl;
	cout << "Видавництво: " << book.publisher << endl;
	cout << "Жанр: " << book.genre << endl;
}


void printBooks(Book books[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Книга №" << i + 1 << endl;

		printBook(books[i]);
	}
}


void findByAuthor(Book books[], int size)
{
	char author[100];

	cout << "Введіть автора: ";
	cin >> author;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].author, author) == 0)
		{
			printBook(books[i]);
		}
	}
}


void findByName(Book books[], int size)
{
	char name[100];

	cout << "Введіть назву книги: ";
	cin >> name;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].name, name) == 0)
		{
			printBook(books[i]);
		}
	}
}