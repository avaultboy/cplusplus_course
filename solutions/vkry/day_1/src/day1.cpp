#include <iostream>
#include <climits>
#include <algorithm>

#include "../classes/exercises.h"

using namespace std;

int toInt(string s);


int main() {

//	int in;
//	string tmp;
//
//	cout << "enter number: ";
//	cin >>  in;

//	tmp = to_string(in);
//	if (tmp.at(0) == '-'){
//		tmp = tmp.substr(1);
//		reverse(tmp.begin(), tmp.end());
//		tmp = "-" + tmp;
//
//		cout << toInt(tmp) << endl;
//
//	} else {
//		reverse(tmp.begin(), tmp.end());
//		cout << toInt(tmp) << endl;
//	}


	string proceed = "y";

	while (proceed.compare("y") == 0){
		int in;
		Day11 day11;
		Day12 day12;
		Day13 day13;

		cout << "1. Задание 1 Развернуть число" << endl;
		cout << "2. Задание 2 Палиндром" << endl;
		cout << "3. Задание 3 Калькулятор +,-,*,/" << endl;
		cout << "Press 1, 2 or 3 to choose an exercise" << endl;
		cin >> in;

		switch (in) {
			case 1:
				day11.do11();
				break;

			case 2:
				day12.do12();
				break;

			case 3:
				day13.do13();
				break;

			default:
				cout << "please type just 1, 2 or 3: " << endl;
				cin.clear();
				continue;
		}

		cout << "do you want to proceed with another exercise? (y/n): ";
		cin >> proceed;

		while (proceed.compare("y") != 0 && proceed.compare("n") != 0){
			cout << "please type just 'y' or 'n': ";
			cin.clear();
			cin >> proceed;
		}

	}

	cout << "End program" << endl;

}



int toInt(string s){
	try {
		return stoi(s);
	} catch (const out_of_range &e) {
		return 0;

	}
}






