//============================================================================
// Name        : day_2_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {
	for (int b = 0; b < INT_MAX; b++) {
		int a, origin, dec = 1;
		long long res = 0;
		bool res2 = true;
//	cout << "Введите число: ";
//	cin >> a;
//	if (a < 0) {
//		cout << false << endl;
//		return 0;
//	}
		a = b;
		origin = a;
		while (a != 0) {
			res = res * dec + (a % 10); //остаток от деления на 10
			dec = 10; //установить множитель на 10
			a /= 10;
		}
		if (res == origin)
		{
			bool ar2[32];
			int i = 0;

			a = origin;
			while (a != 0) {
				ar2[i] = a % 2;
				a /= 2;
				i++;
			}

			int n = i;

			for (i = 0; i < n / 2; i++)
			{
				if (ar2[i] != ar2[n-i-1])
				{
					res2 = false;
					break;
				}
			}

//			cout << (res2) << endl;
			if (res2) cout << origin << endl;
		}
	}
	return 0;
}
