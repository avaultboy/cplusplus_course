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
		cout << "Введите первый операнд" << endl;
		cin >> first;
		char operation;
		cout << "Введите символ операции" << endl;
		cin >> operation;
		int second = 0;
		cout << "Введите второй операнд" << endl;
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
		cout << "Результат: " << result << endl;
		cout << "Продолжить? (y/n) " << endl;
		cin >> line;
		if (line == "n")
			req = false;
	}
}
