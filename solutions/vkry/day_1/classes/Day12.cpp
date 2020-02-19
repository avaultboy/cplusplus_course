/*
 * Day12.cpp
 *
 *  Created on: Feb 18, 2020
 *      Author: vkry
 */

#include "exercises.h"

using namespace std;

Day12::Day12() {
	// TODO Auto-generated constructor stub

}

Day12::~Day12() {
	// TODO Auto-generated destructor stub
}

void Day12::do12(){
	int in;
	Day11 day11;

	cout << "enter number: ";
	cin.clear();
	cin >>  in;

	bool res = false;

	if (in > 0){
		int revInt = day11.getReversed(in);
		if (revInt == in){
			res = true;
		}
	}

	cout << boolalpha << res << endl;
}

