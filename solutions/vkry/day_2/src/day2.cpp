/*
 * day2.cpp
 *
 *  Created on: Feb 19, 2020
 *      Author: vkry
 */


#include <iostream>
#include <bitset>
#include "../classes/exercises.h"

using namespace std;

int main(){

	string proceed = "y";

	while (proceed.compare("y") == 0){
		int in;
		Day21 day21;
		Day22 day22;
		Day23 day23;

		cout << "1. Задание 1 Двухосновные палиндромы" << endl;
		cout << "2. Задание 2 Счет букв в числительных" << endl;
		cout << "3. Задание 3 Массив указателей" << endl;

		cout << "Press 1, 2, or 3 to choose an exercise" << endl;
		cin >> in;

		switch (in) {
			case 1:
				day21.do21();
				break;

			case 2:
				day22.do22();
				break;

			case 3:
				day23.do23();
				break;

			default:
				cout << "please type just 1, 2, or 3: " << endl;
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

