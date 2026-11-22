#include "TestSystemApp.h"

TestSystemApp::TestSystemApp() {
	hasAdmin = false;
	loadAllData();

	if (tests.empty()) {
		createDefaultTests();
		saveTests("tests.txt");
	}
}

void TestSystemApp::drawHeader(string title) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setColor(White, Cyan);
	system("cls");
	setColor(White, Magenta);
	frame(50, 3, 30, 2);
	setCursorPosition(30 + (50 - (int)title.length()) / 2, 3);
	cout << title;
	setColor(White, Cyan);
	setCursorPosition(0, 6);
}

bool TestSystemApp::isLoginFree(string login) {
	string hash = md5(login);
	for (int i = 0; i < (int)users.size(); i++) {
		if (users[i].loginHash == hash) {
			return false;
		}
	}
	return true;
}

void TestSystemApp::loadAllData() {
	ifstream fAdmin("admin.txt");
	if (fAdmin.is_open()) {
		getline(fAdmin, adminLoginHash);
		getline(fAdmin, adminPasswordHash);
		if (!adminLoginHash.empty()) {
			hasAdmin = true;
		}
		fAdmin.close();
	}

	ifstream fUsers("users.txt");
	if (fUsers.is_open()) {
		User u;
		while (getline(fUsers, u.loginHash)) {
			getline(fUsers, u.passwordHash);
			getline(fUsers, u.fullName);
			getline(fUsers, u.address);
			getline(fUsers, u.phone);
			users.push_back(u);
		}
		fUsers.close();
	}

	loadTests("tests.txt");

	ifstream fRes("results.txt");
	if (fRes.is_open()) {
		Result r;
		while (getline(fRes, r.userLoginHash)) {
			getline(fRes, r.userName);
			getline(fRes, r.category);
			getline(fRes, r.testTitle);
			fRes >> r.correctCount >> r.totalCount >> r.percent >> r.grade;
			fRes.ignore();
			results.push_back(r);
		}
		fRes.close();
	}

	ifstream fSes("sessions.txt");
	if (fSes.is_open()) {
		PauseSession s;
		while (getline(fSes, s.userLoginHash)) {
			getline(fSes, s.category);
			getline(fSes, s.testTitle);
			fSes >> s.questionIndex >> s.currentScore;
			fSes.ignore();
			sessions.push_back(s);
		}
		fSes.close();
	}
}

void TestSystemApp::saveAdmin() {
	ofstream f("admin.txt");
	f << adminLoginHash << endl;
	f << adminPasswordHash << endl;
	f.close();
}

void TestSystemApp::saveUsers() {
	ofstream f("users.txt");
	for (int i = 0; i < (int)users.size(); i++) {
		f << users[i].loginHash << endl;
		f << users[i].passwordHash << endl;
		f << users[i].fullName << endl;
		f << users[i].address << endl;
		f << users[i].phone << endl;
	}
	f.close();
}

void TestSystemApp::saveTests(string filename) {
	ofstream f(filename);
	f << tests.size() << endl;
	for (int i = 0; i < (int)tests.size(); i++) {
		f << tests[i].category << endl;
		f << tests[i].title << endl;
		f << tests[i].questions.size() << endl;

		for (int j = 0; j < (int)tests[i].questions.size(); j++) {
			f << tests[i].questions[j].text << endl;
			f << tests[i].questions[j].options.size() << endl;

			for (int k = 0; k < (int)tests[i].questions[j].options.size(); k++) {
				f << tests[i].questions[j].options[k] << endl;
			}
			f << tests[i].questions[j].correctAnswer << endl;
		}
	}
	f.close();
}

void TestSystemApp::loadTests(string filename) {
	ifstream f(filename);
	if (!f.is_open()) return;

	int testCount = 0;
	if (!(f >> testCount)) return;
	f.ignore();

	tests.clear();
	for (int i = 0; i < testCount; i++) {
		Test t;
		getline(f, t.category);
		getline(f, t.title);

		int qCount = 0;
		f >> qCount;
		f.ignore();

		for (int j = 0; j < qCount; j++) {
			Question q;
			getline(f, q.text);

			int optCount = 0;
			f >> optCount;
			f.ignore();

			for (int k = 0; k < optCount; k++) {
				string opt;
				getline(f, opt);
				q.options.push_back(opt);
			}
			f >> q.correctAnswer;
			f.ignore();
			t.questions.push_back(q);
		}
		tests.push_back(t);
	}
	f.close();
}

void TestSystemApp::saveResults() {
	ofstream f("results.txt");
	for (int i = 0; i < (int)results.size(); i++) {
		f << results[i].userLoginHash << endl;
		f << results[i].userName << endl;
		f << results[i].category << endl;
		f << results[i].testTitle << endl;
		f << results[i].correctCount << " " << results[i].totalCount << " "
			<< results[i].percent << " " << results[i].grade << endl;
	}
	f.close();
}

void TestSystemApp::saveSessions() {
	ofstream f("sessions.txt");
	for (int i = 0; i < (int)sessions.size(); i++) {
		f << sessions[i].userLoginHash << endl;
		f << sessions[i].category << endl;
		f << sessions[i].testTitle << endl;
		f << sessions[i].questionIndex << " " << sessions[i].currentScore << endl;
	}
	f.close();
}

void TestSystemApp::createDefaultTests() {
	Test t1;
	t1.category = "Математика";
	t1.title = "Додавання і віднімання";
	Question q1;
	q1.text = "Скільки буде 2 + 2?";
	q1.options.push_back("3");
	q1.options.push_back("4");
	q1.options.push_back("5");
	q1.correctAnswer = 2;
	t1.questions.push_back(q1);

	Question q2;
	q2.text = "Яке число йде після 9?";
	q2.options.push_back("10");
	q2.options.push_back("8");
	q2.options.push_back("11");
	q2.correctAnswer = 1;
	t1.questions.push_back(q2);
	tests.push_back(t1);

	Test t2;
	t2.category = "Математика";
	t2.title = "Геометрія";
	Question q3;
	q3.text = "Скільки кутів у трикутника?";
	q3.options.push_back("3");
	q3.options.push_back("4");
	q3.options.push_back("5");
	q3.correctAnswer = 1;
	t2.questions.push_back(q3);

	Question q4;
	q4.text = "Яка фігура схожа на м'яч або сонечко?";
	q4.options.push_back("Квадрат");
	q4.options.push_back("Трикутник");
	q4.options.push_back("Круг");
	q4.correctAnswer = 3;
	t2.questions.push_back(q4);
	tests.push_back(t2);

	Test t3;
	t3.category = "Фізика";
	t3.title = "Квантова фізика";
	Question q5;
	q5.text = "Якого кольору трава влітку?";
	q5.options.push_back("Зеленого");
	q5.options.push_back("Синього");
	q5.options.push_back("Фіолетового");
	q5.correctAnswer = 1;
	t3.questions.push_back(q5);

	Question q6;
	q6.text = "Коли на небі видно зорі та Місяць?";
	q6.options.push_back("Вдень");
	q6.options.push_back("Вночі");
	q6.options.push_back("Вранці");
	q6.correctAnswer = 2;
	t3.questions.push_back(q6);
	tests.push_back(t3);

	Test t4;
	t4.category = "Фізика";
	t4.title = "Механіка";
	Question q7;
	q7.text = "Що впаде вниз на землю, якщо підкинути вгору?";
	q7.options.push_back("Яблуко");
	q7.options.push_back("Хмара");
	q7.options.push_back("Сонце");
	q7.correctAnswer = 1;
	t4.questions.push_back(q7);

	Question q8;
	q8.text = "Хто важчий: слон чи мишка?";
	q8.options.push_back("Мишка");
	q8.options.push_back("Слон");
	q8.options.push_back("Однакові");
	q8.correctAnswer = 2;
	t4.questions.push_back(q8);
	tests.push_back(t4);
}



void TestSystemApp::menu() {
	system("color 3F");
	Settings::backColorConsole = Cyan;
	Settings::textColorConsole = White;

	while (true) {
		drawHeader("ГОЛОВНЕ МЕНЮ");

		StringList items;
		items.push_back("Увійти");
		items.push_back("Зареєструватися");
		items.push_back("Про нас");
		items.push_back("Налаштування");
		items.push_back("Вихід");

		int choice = Menu::verticalMenu("", items, Center, 8);

		if (choice == 0) loginScreen();
		else if (choice == 1) registerUser();
		else if (choice == 2) aboutScreen();
		else if (choice == 3) {
			Menu::consoleSettings();
			system("cls");
		}
		else if (choice == 4 || choice == -1) {
			break;
		}
	}
}

void TestSystemApp::aboutScreen() {
	drawHeader("ПРО НАС");
	setCursorPosition(25, 8);
	cout << "Екзаменаційна робота з ООП (C++).";
	setCursorPosition(25, 10);
	cout << "Програма для проходження тестів з математики та фізики.";
	setCursorPosition(25, 12);
	cout << "Успіхів на тестуванні та одних 12 :)";
	setCursorPosition(25, 15);
	system("pause");
}

void TestSystemApp::registerUser() {
	drawHeader("РЕЄСТРАЦІЯ ГОСТЯ");
	string login, password, fullName, address, phone;

	cout << "\n\n\tВведіть унікальний логін: ";
	getline(cin, login);

	if (login.empty() || !isLoginFree(login)) {
		cout << "\tПомилка. Такий логін вже існує або він порожній.\n\t";
		system("pause");
		return;
	}

	cout << "\tВведіть пароль: ";
	getline(cin, password);
	cout << "\tВведіть ПІБ: ";
	getline(cin, fullName);
	cout << "\tВведіть домашню адресу: ";
	getline(cin, address);
	cout << "\tВведіть телефон: ";
	getline(cin, phone);

	User newUser;
	newUser.loginHash = md5(login);
	newUser.passwordHash = md5(password);
	newUser.fullName = fullName;
	newUser.address = address;
	newUser.phone = phone;

	users.push_back(newUser);
	saveUsers();

	cout << "\n\tРеєстрація успішна! Пароль та логін зашифровано.\n\t";
	system("pause");
}

void TestSystemApp::loginScreen() {
	drawHeader("ВХІД У СИСТЕМУ");

	if (!hasAdmin) {
		cout << "\n\n\tУВАГА! Адміністратор ще не створений.\n";
		cout << "\tБажаєте створити Адміністратора зараз? (1 - Так, 0 - Увійти як Гість): ";
		int ans;
		cin >> ans;
		cin.ignore();

		if (ans == 1) {
			string aLogin, aPass;
			cout << "\tЗадайте логін Адміністратора: ";
			getline(cin, aLogin);
			cout << "\tЗадайте пароль Адміністратора: ";
			getline(cin, aPass);

			adminLoginHash = md5(aLogin);
			adminPasswordHash = md5(aPass);
			hasAdmin = true;
			saveAdmin();

			cout << "\tАдміністратора успішно створено!\n\t";
			system("pause");
			adminMenu();
			return;
		}
	}

	string login, password;
	cout << "\n\n\tЛогін: ";
	getline(cin, login);
	cout << "\tПароль: ";
	getline(cin, password);

	string lHash = md5(login);
	string pHash = md5(password);

	if (hasAdmin && lHash == adminLoginHash && pHash == adminPasswordHash) {
		adminMenu();
		return;
	}

	for (int i = 0; i < (int)users.size(); i++) {
		if (users[i].loginHash == lHash && users[i].passwordHash == pHash) {
			guestMenu(users[i]);
			return;
		}
	}

	cout << "\n\tПомилка! Невірний логін або пароль.\n\t";
	system("pause");
}

void TestSystemApp::adminMenu() {
	while (true) {
		drawHeader("ПАНЕЛЬ АДМІНІСТРАТОРА");
		StringList items;
		items.push_back("Змінити логін і пароль адміна");
		items.push_back("Управління користувачами");
		items.push_back("Управління тестуванням");
		items.push_back("Перегляд статистики");
		items.push_back("Вихід у головне меню");

		int choice = Menu::verticalMenu("", items, Center, 8);

		if (choice == 0) changeAdminLoginPass();
		else if (choice == 1) adminManageUsers();
		else if (choice == 2) adminManageTests();
		else if (choice == 3) adminViewStats();
		else if (choice == 4 || choice == -1) break;
	}
}

void TestSystemApp::changeAdminLoginPass() {
	drawHeader("ЗМІНА ДАНИХ АДМІНА");
	string newLogin, newPass;
	cout << "\n\n\tНовий логін адміна: ";
	getline(cin, newLogin);
	cout << "\tНовий пароль адміна: ";
	getline(cin, newPass);
	adminLoginHash = md5(newLogin);
	adminPasswordHash = md5(newPass);
	saveAdmin();
	cout << "\n\tЛогін та пароль змінено і зашифровано!\n\t";
	system("pause");
}
void TestSystemApp::adminManageUsers() {
	while (true) {
		drawHeader("УПРАВЛІННЯ КОРИСТУВАЧАМИ");
		StringList items;
		items.push_back("Список користувачів");
		items.push_back("Створити користувача");
		items.push_back("Модифікувати користувача");
		items.push_back("Видалити користувача");
		items.push_back("Назад");
		int choice = Menu::verticalMenu("", items, Center, 8);
		if (choice == 0) {
			drawHeader("СПИСОК КОРИСТУВАЧІВ");
			cout << "\n\n";
			for (int i = 0; i < (int)users.size(); i++) {
				cout << "\t" << i + 1 << ". ПІБ: " << users[i].fullName
					<< " | Адреса: " << users[i].address
					<< " | Тел: " << users[i].phone << endl;
			}
			if (users.empty()) cout << "\tКористувачів поки немає.\n";
			cout << "\n\t";
			system("pause");
		}
		else if (choice == 1) {
			registerUser();
		}
		else if (choice == 2) {
			drawHeader("МОДИФІКАЦІЯ КОРИСТУВАЧА");
			string login;
			cout << "\n\n\tВведіть логін користувача для зміни: ";
			getline(cin, login);
			string h = md5(login);
			bool found = false;
			for (int i = 0; i < (int)users.size(); i++) {
				if (users[i].loginHash == h) {
					string newPass;
					cout << "\tНовий пароль: "; getline(cin, newPass);
					cout << "\tНовий ПІБ: "; getline(cin, users[i].fullName);
					cout << "\tНова адреса: "; getline(cin, users[i].address);
					cout << "\tНовий телефон: "; getline(cin, users[i].phone);
					users[i].passwordHash = md5(newPass);
					saveUsers();
					cout << "\n\tДані оновлено!\n\t";
					found = true;
					break;
				}
			}
			if (!found) cout << "\tКористувача не знайдено.\n\t";
			system("pause");
		}
		else if (choice == 3) {
			drawHeader("ВИДАЛЕННЯ КОРИСТУВАЧА");
			string login;
			cout << "\n\n\tВведіть логін користувача для видалення: ";
			getline(cin, login);
			string h = md5(login);
			bool deleted = false;
			for (int i = 0; i < (int)users.size(); i++) {
				if (users[i].loginHash == h) {
					users.erase(users.begin() + i);
					saveUsers();
					cout << "\tКористувача видалено!\n\t";
					deleted = true;
					break;
				}
			}
			if (!deleted) cout << "\tКористувача не знайдено.\n\t";
			system("pause");
		}
		else if (choice == 4 || choice == -1) break;
	}
}
void TestSystemApp::adminManageTests() {
	while (true) {
		drawHeader("УПРАВЛІННЯ ТЕСТУВАННЯМ");
		StringList items;
		items.push_back("Переглянути всі тести");
		items.push_back("Додати категорію і тест");
		items.push_back("Додати питання до тесту");
		items.push_back("Експорт тестів у файл");
		items.push_back("Імпорт тестів з файлу");
		items.push_back("Назад");
		int choice = Menu::verticalMenu("", items, Center, 8);
		if (choice == 0) {
			drawHeader("СПИСОК ТЕСТІВ");
			cout << "\n\n";
			for (int i = 0; i < (int)tests.size(); i++) {
				cout << "\t" << i + 1 << ". [" << tests[i].category << "] "
					<< tests[i].title << " (Питань: " << tests[i].questions.size() << ")\n";
			}
			cout << "\n\t";
			system("pause");
		}
		else if (choice == 1) {
			drawHeader("НОВИЙ ТЕСТ");
			Test t;
			cout << "\n\n\tВведіть категорію (розділ): ";
			getline(cin, t.category);
			cout << "\tВведіть назву тесту: ";
			getline(cin, t.title);
			tests.push_back(t);
			saveTests("tests.txt");
			cout << "\tТест створено! Тепер додайте до нього питання.\n\t";
			system("pause");
		}
		else if (choice == 2) {
			drawHeader("ДОДАВАННЯ ПИТАННЯ");
			cout << "\n\n";
			for (int i = 0; i < (int)tests.size(); i++) {
				cout << "\t" << i + 1 << ". [" << tests[i].category << "] " << tests[i].title << endl;
			}
			int num;
			cout << "\n\tОберіть номер тесту: ";
			cin >> num;
			cin.ignore();
			if (num >= 1 && num <= (int)tests.size()) {
				Question q;
				cout << "\tТекст питання: ";
				getline(cin, q.text);
				int optCount;
				cout << "\tСкільки варіантів відповіді (напр. 3 або 4): ";
				cin >> optCount;
				cin.ignore();
				for (int j = 0; j < optCount; j++) {
					string opt;
					cout << "\tВаріант " << j + 1 << ": ";
					getline(cin, opt);
					q.options.push_back(opt);
				}
				cout << "\tНомер правильної відповіді (1-" << optCount << "): ";
				cin >> q.correctAnswer;
				cin.ignore();
				tests[num - 1].questions.push_back(q);
				saveTests("tests.txt");
				cout << "\tПитання додано!\n\t";
			}
			system("pause");
		}
		else if (choice == 3) {
			drawHeader("ЕКСПОРТ ТЕСТІВ");
			string fname;
			cout << "\n\n\tВведіть ім'я файлу (напр. export.txt): ";
			getline(cin, fname);
			saveTests(fname);
			cout << "\tЕкспортовано у файл " << fname << "!\n\t";
			system("pause");
		}
		else if (choice == 4) {
			drawHeader("ІМПОРТ ТЕСТІВ");
			string fname;
			cout << "\n\n\tВведіть ім'я файлу для імпорту: ";
			getline(cin, fname);
			loadTests(fname);
			saveTests("tests.txt");
			cout << "\tТести імпортовано!\n\t";
			system("pause");
		}
		else if (choice == 5 || choice == -1) break;
	}
}
void TestSystemApp::adminViewStats() {
	drawHeader("СТАТИСТИКА ТЕСТУВАННЯ");
	StringList items;
	items.push_back("Загальна статистика");
	items.push_back("За категорією");
	items.push_back("За конкретним тестом");
	items.push_back("За користувачем (логіном)");
	items.push_back("Назад");
	int choice = Menu::verticalMenu("", items, Center, 8);
	if (choice == 4 || choice == -1) return;
	drawHeader("РЕЗУЛЬТАТИ СТАТИСТИКИ");
	string filter;
	cout << "\n\n";
	if (choice == 1) { cout << "\tВведіть категорію: "; getline(cin, filter); }
	else if (choice == 2) { cout << "\tВведіть назву тесту: "; getline(cin, filter); }
	else if (choice == 3) {
		string login;
		cout << "\tВведіть логін користувача: ";
		getline(cin, login);
		filter = md5(login);
	}
	string reportText = "";
	for (int i = 0; i < (int)results.size(); i++) {
		bool show = false;
		if (choice == 0) show = true;
		if (choice == 1 && results[i].category == filter) show = true;
		if (choice == 2 && results[i].testTitle == filter) show = true;
		if (choice == 3 && results[i].userLoginHash == filter) show = true;
		if (show) {
			string line = "Користувач: " + results[i].userName +
				" | [" + results[i].category + "] " + results[i].testTitle +
				" | Правильно: " + to_string(results[i].correctCount) + "/" + to_string(results[i].totalCount) +
				" (" + to_string(results[i].percent) + "%) | Оцінка: " + to_string(results[i].grade) + "/12\n";
			cout << "\t" << line;
			reportText += line;
		}
	}
	if (reportText.empty()) cout << "\tРезультатів не знайдено.\n";
	cout << "\n\tЗберегти статистику у файл? (1 - Так, 0 - Ні): ";
	int saveChoice;
	cin >> saveChoice;
	cin.ignore();
	if (saveChoice == 1) {
		string fname;
		cout << "\tВведіть назву файлу (напр. stat.txt): ";
		getline(cin, fname);
		ofstream out(fname);
		out << reportText;
		out.close();
		cout << "\tЗвіт збережено у файл " << fname << "!\n";
	}
	cout << "\t";
	system("pause");
}
void TestSystemApp::guestMenu(User currentUser) {
	while (true) {
		drawHeader("КАБІНЕТ: " + currentUser.fullName);
		StringList items;
		items.push_back("Пройти нове тестування");
		items.push_back("Продовжити незавершений тест");
		items.push_back("Переглянути мої результати");
		items.push_back("Вихід у головне меню");
		int choice = Menu::verticalMenu("", items, Center, 8);
		if (choice == 0) startTest(currentUser);
		else if (choice == 1) continueTest(currentUser);
		else if (choice == 2) viewMyResults(currentUser);
		else if (choice == 3 || choice == -1) break;
	}
}
void TestSystemApp::startTest(User currentUser) {
	StringList categories;
	for (int i = 0; i < (int)tests.size(); i++) {
		bool exists = false;
		for (int j = 0; j < (int)categories.size(); j++) {
			if (categories[j] == tests[i].category) exists = true;
		}
		if (!exists) categories.push_back(tests[i].category);
	}
	drawHeader("ОБЕРІТЬ КАТЕГОРІЮ ЗНАНЬ");
	int catIndex = Menu::verticalMenu("", categories, Center, 8);
	if (catIndex == -1) return;
	string chosenCategory = categories[catIndex];
	TestList catTests;
	StringList testNames;
	for (int i = 0; i < (int)tests.size(); i++) {
		if (tests[i].category == chosenCategory) {
			catTests.push_back(tests[i]);
			testNames.push_back(tests[i].title);
		}
	}
	drawHeader("КАТЕГОРІЯ: " + chosenCategory);
	int testIndex = Menu::verticalMenu("", testNames, Center, 8);
	if (testIndex == -1) return;
	runTestProcess(currentUser, catTests[testIndex], 0, 0);
}
void TestSystemApp::continueTest(User currentUser) {
	IntList userSessionsIndexes;
	StringList menuItems;
	for (int i = 0; i < (int)sessions.size(); i++) {
		if (sessions[i].userLoginHash == currentUser.loginHash) {
			userSessionsIndexes.push_back(i);
			menuItems.push_back(sessions[i].category + " -> " + sessions[i].testTitle +
				" (Питання №" + to_string(sessions[i].questionIndex + 1) + ")");
		}
	}
	if (userSessionsIndexes.empty()) {
		drawHeader("ПРОДОВЖЕННЯ ТЕСТУ");
		cout << "\n\n\tУ вас немає призупинених тестів.\n\t";
		system("pause");
		return;
	}
	drawHeader("ОБЕРІТЬ ПРИЗУПИНЕНИЙ ТЕСТ");
	int choice = Menu::verticalMenu("", menuItems, Center, 8);
	if (choice == -1) return;
	int realIndex = userSessionsIndexes[choice];
	PauseSession saved = sessions[realIndex];
	sessions.erase(sessions.begin() + realIndex);
	saveSessions();
	for (int i = 0; i < (int)tests.size(); i++) {
		if (tests[i].category == saved.category && tests[i].title == saved.testTitle) {
			runTestProcess(currentUser, tests[i], saved.questionIndex, saved.currentScore);
			return;
		}
	}
}
void TestSystemApp::runTestProcess(User currentUser, Test selectedTest, int startQuestion, int startScore) {
	int total = (int)selectedTest.questions.size();
	if (total == 0) {
		drawHeader("ПОМИЛКА");
		cout << "\n\n\tУ цьому тесті ще немає питань.\n\t";
		system("pause");
		return;
	}
	int score = startScore;
	for (int i = startQuestion; i < total; i++) {
		drawHeader("ТЕСТ: " + selectedTest.title);
		cout << "\n\n\tПитання " << i + 1 << " з " << total << ":\n";
		cout << "\t" << selectedTest.questions[i].text << "\n\n";
		for (int j = 0; j < (int)selectedTest.questions[i].options.size(); j++) {
			cout << "\t" << j + 1 << ") " << selectedTest.questions[i].options[j] << "\n";
		}
		cout << "\n\tВведіть номер відповіді (або 0, щоб ПРИЗУПИНИТИ тест): ";
		int answer;
		cin >> answer;
		cin.ignore();
		if (answer == 0) {
			PauseSession ps;
			ps.userLoginHash = currentUser.loginHash;
			ps.category = selectedTest.category;
			ps.testTitle = selectedTest.title;
			ps.questionIndex = i;
			ps.currentScore = score;
			sessions.push_back(ps);
			saveSessions();
			cout << "\n\tТест призупинено! Прогрес збережено.\n\t";
			system("pause");
			return;
		}
		if (answer == selectedTest.questions[i].correctAnswer) {
			score++;
		}
	}
	int percent = (score * 100) / total;
	int grade = (int)round(((double)score / total) * 12.0);
	drawHeader("РЕЗУЛЬТАТ ТЕСТУВАННЯ");
	cout << "\n\n\tТест завершено!\n";
	cout << "\tПравильних відповідей: " << score << " з " << total << "\n";
	cout << "\tВідсоток правильних відповідей: " << percent << "%\n";
	cout << "\tВаша оцінка (12-бальна система): " << grade << " балів\n\n\t";
	Result res;
	res.userLoginHash = currentUser.loginHash;
	res.userName = currentUser.fullName;
	res.category = selectedTest.category;
	res.testTitle = selectedTest.title;
	res.correctCount = score;
	res.totalCount = total;
	res.percent = percent;
	res.grade = grade;
	results.push_back(res);
	saveResults();
	system("pause");
}
void TestSystemApp::viewMyResults(User currentUser) {
	drawHeader("МОЇ РЕЗУЛЬТАТИ");
	cout << "\n\n";
	bool hasAny = false;
	for (int i = 0; i < (int)results.size(); i++) {
		if (results[i].userLoginHash == currentUser.loginHash) {
			cout << "\t[" << results[i].category << "] " << results[i].testTitle
				<< " -> Правильно: " << results[i].correctCount << "/" << results[i].totalCount
				<< " (" << results[i].percent << "%) | Оцінка: " << results[i].grade << "/12\n";
			hasAny = true;
		}
	}
	if (!hasAny) cout << "\tВи ще не пройшли жодного тесту.\n";
	cout << "\n\t";
	system("pause");
}