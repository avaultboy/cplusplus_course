/*
 * day11.cpp
 *
 *  Created on: Feb 18, 2020
 *      Author: vkry
 */

#include "exercises.h"

using namespace std;


Day11::Day11() {
	// TODO Auto-generated constructor stub
}

Day11::~Day11() {
	// TODO Auto-generated destructor stub
}

void Day11::do11(){
	int in;

	cout << "enter number: ";
	cin.clear();
	cin >>  in;

	int reversed = 0;

	if (in < 0){
		in  = -in;
		reversed = getReversed(in);
		reversed = -reversed;
		if (reversed < INT32_MIN) {
			reversed = 0;
		}
	} else {
		reversed = getReversed(in);
	}

	cout << reversed << endl;
}


bool Day11::chkAdd(int a, int b)
{
	if(INT32_MAX - b < a) {
		return false;
	}
	return true;
}

bool Day11::chkMul(int a){
	if (INT32_MAX / 10 < a) {
		return false;
	}
	return true;
}

int Day11::getReversed(int in){
	int revInt = 0;
	while (in > 0){
		int rem = in % 10;
		int tmpIn = in / 10;

		if (!chkAdd(rem, revInt)) {
			revInt = 0;
			break;
		}
		revInt += rem;
		if (tmpIn > 0) {
			if (!chkMul(revInt)) {
				revInt = 0;
				break;
			}
			revInt *=10;
		}
		in = tmpIn;
	}
	return revInt;
}
