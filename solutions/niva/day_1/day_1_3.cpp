// 1_3
#include <iostream>
#include <string>
#include <clocale>


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	bool req = true;
	string line;

	while (req) {
		int first = 0;
		cout << "������� ������ �������" << endl;
		cin >> first;
		char operation;
		cout << "������� ������ ��������" << endl;
		cin >> operation;
		int second = 0;
		cout << "������� ������ �������" << endl;
		cin >> second;

		int result = 0;
		switch (operation)
		{
		case '+': result = first + second;
			break;
		case '-': result = first - second;
			break;
		case '*': result = first * second;
			break;
		case '/': result = first / second;
			break;
		default:
			break;
		}
		cout << "���������: " << result << endl;
		cout << "����������? (y/n) " << endl;
		cin >> line;
		if (line == "n")
			req = false;
	}
}
