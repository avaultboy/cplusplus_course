//============================================================================
// Name        : day_2_2_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int up20str[20] = {
		0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
		6, 6, 8, 8, 7, 7, 9, 8, 8
};
const int decstr[8] {
	6, 6, 5, 5, 5, 7, 6, 6
};

int main() {
	int a;
	int resstr;
	cout << "¬ведите число: ";
	cin >> a;
	int count = 1;
	while (a != 0) {
		int digit;
		if (count == 1) {
			digit= a % 100;
			if (digit < 20) {
				resstr = up20str[digit];
				count = 3;
				a /= 100;
				continue;
			}
		}
		digit = a % 10;
		a /= 10;
		switch (count) {
		case 1:
			resstr = up20str[digit];
			break;
		case 2:
			resstr = decstr[digit-2] + resstr;
			break;
		case 3:
			if (digit == 0) {
				count++;
				continue;
			}
			if (resstr != 0)
			{
				resstr = 3 + resstr; //and
			}
			resstr = up20str[digit] + 7 + resstr; //hundred
			break;
		case 4:
			resstr = up20str[digit] + 8 + resstr; //thousend
			break;
		}
//		cout << resstr << endl;
		count++;
	}
	cout << "Length of number is " << resstr << endl;
	return 0;
}
