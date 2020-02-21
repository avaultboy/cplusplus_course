//============================================================================
// Name        : day_1_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {
	int a, b;
	char oper, answ = 'y';
	while ((answ == 'y') || (answ == 'Y')) {
		cout << "Введите первый операнд, операцию и второй операнд: ";
		if (!(cin >> a)) {
			cin.clear();
			while (cin.get ()!= '\n') continue;
			cout << "ОШИБКА!" << endl << "Операнд должен быть числом." << endl;
			cout << "Продолжить (y/n)? ";
			cin >> answ;
			continue;
		}
		cin >> oper;
		if (!(cin >> b)) {
			cin.clear();
			while (cin.get ()!= '\n') continue;
			cout << "ОШИБКА!" << endl << "Операнд должен быть числом." << endl;
			cout << "Продолжить (y/n)? ";
			cin >> answ;
			continue;
		}
		cout << a << oper << b << "=";
		switch (oper) {
		case '+':
			cout << a + b << endl;
			break;
		case '-':
			cout << a - b << endl;
			break;
		case '*':
			cout << a * b << endl;
			break;
		case '/':
			cout << a / b << endl;
			break;
		default:
			cout << "ОШИБКА!" << endl << "Операция может быть только '+', '-', '*' или '/'" << endl;
		}
		cout << "Продолжить (y/n)? ";
		cin >> answ;
	}
	cout << "Конец" << endl;
	return 0;
}
