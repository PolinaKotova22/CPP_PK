#pragma once
#include<iostream>
#include<iomanip>
#include"myFunc.h"

using namespace std;


struct Point
{
	double x;
	char name;
	int y;


	void print()
	{
		cout << name << "(" << x << ", " << y << ")" << endl;
	}
};

struct Foo
{

};


struct Date
{
	int day;
	int month;
	int year;
};

void printDate(Date d) {
	if (d.day < 10)
		cout << "0";
	cout << d.day << ".";

	if (d.month < 10)
		cout << "0";
	cout << d.month << ".";

	cout << d.year << endl;
}


struct Human
{
	char* name;
	int age;
};



struct Engine
{
	int cilinder = 4;

	void start()
	{
		cout << "Engine started" << endl;
	}

	void stop()
	{
		cout << "Engine stoped" << endl;
	}
};

struct Car
{
	Engine engine;



	void move()
	{
		engine.start();
		cout << "Car moved" << endl;
		engine.stop();
	}

	void beep()
	{
		cout << "Beep beep" << endl;
	}
};




struct Abonent
{
	char* name;
	char* phoneNumber;

	void input()
	{
		cout << "Enter name   : ";
		char buffer[80];
		cin.getline(buffer, 80);
		name = new char[strlen(buffer) + 1];
		strcpy(name, buffer);
		cout << "Enter number : ";
		cin.getline(buffer, 80);
		phoneNumber = new char[strlen(buffer) + 1];
		strcpy(phoneNumber, buffer);
	}

	void print()
	{
		cout << setw(15) << left << name << setw(15) << left << phoneNumber << endl;
	}
};


struct PhoneBook
{
	Abonent* abonents = nullptr;
	int size = 0;

	void init()
	{
		size = 3;
		abonents = new Abonent[3];
		abonents[0].name = new char[] {"Brian"};
		abonents[0].phoneNumber = new char[] {"+442010315082"};// { "+44 (20) 1031-5082" };
		abonents[1].name = new char[] {"Gerard"};
		abonents[1].phoneNumber = new char[] {"+19730326783"};
		abonents[2].name = new char[] {"Billie"};
		abonents[2].phoneNumber = new char[] {"+13110327009"};
	}

	void menu()
	{
		init();
		while (true)
		{
			system("cls");
			cout << "PHONEBOOK" << endl;
			cout << "----------------------" << endl;
			cout << "1. Add contact\n2. Remove contact\n3. Print all contacts\n4. Find contact\n5. Exit" << endl;
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1:
				addContact();
				break;
			case 2:
				removeContact();
				break;
			case 3:
				printAll();
				break;
			case 4:
				findContact();
				break;
			case 5:
				exit(0);
			default:
				break;
			}
		}
	}

	void addContact()
	{
		system("cls");
		cout << "Add Contact" << endl;
		cout << "---------------------" << endl;
		Abonent ab;
		ab.input();
		addValueArray(abonents, size, ab);
		cout << "Abonent added" << endl;
		system("pause");
	}

	void removeContact()
	{

	}

	void printAll()
	{
		system("cls");
		cout << "PhoneBook List" << endl;
		cout << "---------------------" << endl << endl;
		cout << "   №  Name           Phone Number" << endl;
		cout << "--------------------------------------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << setw(4) << right << i + 1 << ". ";
			abonents[i].print();
		}
		system("pause");
	}

	void findContact()
	{

	}

}; 