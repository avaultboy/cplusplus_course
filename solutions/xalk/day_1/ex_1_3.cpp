
#include <iostream>
using namespace std;



int main() {

	const char add = '+';
	const char sub = '-';
	const char mul = '*';
	const char div = '/';
	int a, b;
	char oper;

	do {
		cout << "Enter first operand, operation (+,-,*,/) and second operand:" << endl;
		cin >> a;
		cin >> oper;
		cin >> b;
		switch (oper){
		case add:
			cout << a + b << endl;
			break;
		case sub:
			cout << a - b << endl;
			break;
		case mul:
			cout << a * b << endl;
			break;
		case div:
			cout << a / b << endl;
			break;
		default:
			cout << "unknown operation: " << oper << endl;
		}
		cout << "Continue (y/n)? ";
		cin >> oper;
	} while (oper == 'y');

	return 0;
}
