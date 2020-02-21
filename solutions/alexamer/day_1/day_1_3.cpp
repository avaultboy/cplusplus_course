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
		cout << "������� ������ �������, �������� � ������ �������: ";
		if (!(cin >> a)) {
			cin.clear();
			while (cin.get ()!= '\n') continue;
			cout << "������!" << endl << "������� ������ ���� ������." << endl;
			cout << "���������� (y/n)? ";
			cin >> answ;
			continue;
		}
		cin >> oper;
		if (!(cin >> b)) {
			cin.clear();
			while (cin.get ()!= '\n') continue;
			cout << "������!" << endl << "������� ������ ���� ������." << endl;
			cout << "���������� (y/n)? ";
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
			cout << "������!" << endl << "�������� ����� ���� ������ '+', '-', '*' ��� '/'" << endl;
		}
		cout << "���������� (y/n)? ";
		cin >> answ;
	}
	cout << "�����" << endl;
	return 0;
}
