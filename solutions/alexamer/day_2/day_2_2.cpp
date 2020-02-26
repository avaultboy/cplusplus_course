//============================================================================
// Name        : day_2_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

const string up20str[20] = {
		"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
const string decstr[8] {
	"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

int main() {
	int a;
	string resstr;
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
			if (resstr.length() != 0)
			{
				resstr = "and" + resstr;
			}
			resstr = up20str[digit] + "hundred" + resstr;
			break;
		case 4:
			resstr = up20str[digit] + "thousand" + resstr;
			break;
		}
		cout << resstr << endl;
		count++;
	}
	cout << "Length of number is " << resstr.length() << endl;
	return 0;
}
