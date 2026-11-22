#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <Windows.h>
#include "ConsoleMenu.h"
#include "md5.h"

using namespace std;
using namespace ConsoleMenu;

typedef vector<string> StringList;

struct Question {
	string text;
	StringList options;
	int correctAnswer;
};

typedef vector<Question> QuestionList;

struct Test {
	string category;
	string title;
	QuestionList questions;
};

typedef vector<Test> TestList;

struct User {
	string loginHash;
	string passwordHash;
	string fullName;
	string address;
	string phone;
};

typedef vector<User> UserList;

struct Result {
	string userLoginHash;
	string userName;
	string category;
	string testTitle;
	int correctCount;
	int totalCount;
	int percent;
	int grade;
};

typedef vector<Result> ResultList;

struct PauseSession {
	string userLoginHash;
	string category;
	string testTitle;
	int questionIndex;
	int currentScore;
};

typedef vector<PauseSession> SessionList;
typedef vector<int> IntList;

class TestSystemApp {
private:
	string adminLoginHash;
	string adminPasswordHash;
	bool hasAdmin;

	UserList users;
	TestList tests;
	ResultList results;
	SessionList sessions;

	void loadAllData();
	void saveAdmin();
	void saveUsers();
	void saveTests(string filename);
	void loadTests(string filename);
	void saveResults();
	void saveSessions();
	void createDefaultTests();

	void drawHeader(string title);
	bool isLoginFree(string login);

	void loginScreen();
	void registerUser();
	void aboutScreen();

	void adminMenu();
	void changeAdminLoginPass();
	void adminManageUsers();
	void adminManageTests();
	void adminViewStats();

	void guestMenu(User currentUser);
	void startTest(User currentUser);
	void continueTest(User currentUser);
	void runTestProcess(User currentUser, Test selectedTest, int startQuestion, int startScore);
	void viewMyResults(User currentUser);

public:
	TestSystemApp();
	void menu();
};
