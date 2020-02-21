//============================================================================
// Name        : day_1_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {
	int a, origin, dec = 1;
	long long res = 0;
	cout << "Введите число: ";
	cin >> a;
	if (a < 0) {
		cout << false << endl;
		return 0;
	}
	origin = a;
	while (a != 0) {
		res = res* dec + (a % 10); //остаток от деления на 10
		dec = 10; //установить множитель на 10
		a /= 10;
	}
	if (res == origin)
		cout << true << endl;
	else
		cout << false << endl;

	return 0;
}

