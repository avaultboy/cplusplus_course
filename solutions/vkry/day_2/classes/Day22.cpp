/*
 * Day22.cpp
 *
 *  Created on: Feb 21, 2020
 *      Author: vkry
 */

#include "exercises.h"

using namespace std;

Day22::Day22() {
	// TODO Auto-generated constructor stub

}

Day22::~Day22() {
	// TODO Auto-generated destructor stub
}


void Day22::do22(){
	int in = 0;
	string answer = "";

	string ones[] = {
			"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	string tenToTwenty[] = {
			"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};

	string tens[] = {
			"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};


	cout << "enter number(1 - 1000): ";
	cin >> in;

	while (in > 1000 || in < 0){
		cin.clear();
		cout << "number should be from 1 to 1000" << endl;
		cout << "enter number(1 - 1000): ";
		cin >> in;
	}

	if (in == 1000){
		cout << ones[1] + "thousand" << endl;
	}

	if (in == 0){
		cout << ones[0] << endl;
	}


	if (in >= 100){
		int tmp = in / 100;
		answer = ones[tmp] + "hundred";
		in %= 100;
	}


	if (in > 0){
		if (answer.length() > 0){
			answer += "and";
		}

		if (in >= 10 && in < 20){
			in = in % 10;
			answer += tenToTwenty[in];
			in = 0;
		} else if (in >= 20){
			int tmp = in / 10;
			answer += tens[tmp];
			in %= 10;
		}

		if (in > 0){
			answer += ones[in];
		}

	}


//	cout << "answer " << answer << endl;
	cout << "length: " << answer.length() << endl;
}
