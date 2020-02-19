/*
 * day21.cpp
 *
 *  Created on: Feb 19, 2020
 *      Author: vkry
 */

#include "exercises.h"

using namespace std;

Day21::Day21() {
	// TODO Auto-generated constructor stub

}

Day21::~Day21() {
	// TODO Auto-generated destructor stub
}

void Day21::do21(){
	int in;

	cout << "enter number: ";
	cin.clear();
	cin >>  in;

	bool res10base = false;
	bool res2base = false;

	if (in > 0){
		int revInt = getReversed(in);
		if (revInt == in){
			res10base = true;
		}

		bitset<32> bits(in);
		int firstSignificant = getFirstSignificant(bits);

		res2base = checkBitPalindrome(in, firstSignificant);

	} else if (in == 0){
		res10base = true;
		res2base = true;
	}

	cout << "is palindrome in base 10: " << boolalpha << res10base << endl;
	cout << "is palindrome in base 2: " << boolalpha << res2base << endl;

}


bool Day21::chkAdd(int a, int b)
{
	if(INT32_MAX - b < a) {
		return false;
	}
	return true;
}

bool Day21::chkMul(int a){
	if (INT32_MAX / 10 < a) {
		return false;
	}
	return true;
}

int Day21::getReversed(int in){
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

int Day21::getFirstSignificant(bitset<32> bits){
	int idx = 31;

	while (bits[idx] != 1){
		idx--;
	}

	return idx;
}

bool Day21::checkBitPalindrome(bitset<32> bits, int firstSignificant){

	for (int i = firstSignificant; i >= 0; i--){
		int j = firstSignificant - i;
		if (bits[i] != bits[j]){
			return false;

		}
	}

	return true;
}

