/*
 * exercises.h
 *
 *  Created on: Feb 19, 2020
 *      Author: vkry
 */

#ifndef EXERCISES_H_
#define EXERCISES_H_

#include <iostream>
#include <climits>
#include <bitset>

class Day21 {
private:
	bool chkAdd(int a, int b);
	bool chkMul(int a);
	int getReversed(int in);
	int getFirstSignificant(std::bitset<32> bits);
	bool checkBitPalindrome(std::bitset<32> bits, int firstSignificant);
public:
	Day21();
	virtual ~Day21();

	void do21();
};

#endif /* EXERCISES_H_ */
