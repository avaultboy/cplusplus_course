/*
 * Day13.cpp
 *
 *  Created on: Feb 18, 2020
 *      Author: vkry
 */

#include "exercises.h"

using namespace std;

Day13::Day13() {
	// TODO Auto-generated constructor stub

}

Day13::~Day13() {
	// TODO Auto-generated destructor stub
}



void Day13::do13(){
	string cont = "y";

	while (cont.compare("y") == 0){
		int a = 0;
		int b = 0;
		int res = 0;
		string sign;

		cin.clear();
		cout << "enter first number:" << endl;
		cin >> a;
		cin.clear();

		cout << "enter sign:" << endl;
		cin >> sign;
		cin.clear();

		cout << "enter second number:" << endl;
		cin >> b;
		cin.clear();

		if (sign.compare("+") == 0) {
			res = a + b;
		} else if (sign.compare("-") == 0) {
			res = a - b;
		} else if (sign.compare("*") == 0) {
			res = a * b;
		} else if (sign.compare("/") == 0) {
			res = a / b;
		}

		cout << "answer is: " << res << endl;
		cout << "do you want to continue? (y/n): ";
		cin >> cont;

		while (cont.compare("y") != 0 && cont.compare("n") != 0){
			cout << "please type just 'y' or 'n': ";
			cin.clear();
			cin >> cont;
		}

	}
}
