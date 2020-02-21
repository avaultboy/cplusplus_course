//============================================================================
// Name        : day_1_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {
	int a, dec = 1;
	long long res = 0;
	cout << "Введите число: ";
	cin >> a;
	while (a != 0) {
		res = res* dec + (a % 10); //остаток от деления на 10
		dec = 10; //установить множитель на 10
		a /= 10;
	}
	if (res > INT32_MAX || res < INT32_MIN)
		cout << 0 << endl;
	else
		cout << res << endl;
	return 0;
}

