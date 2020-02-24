/*
 * day11.h
 *
 *  Created on: Feb 18, 2020
 *      Author: vkry
 */

#ifndef EXERCISES_H_
#define EXERCISES_H_

#include <iostream>
#include <climits>

class Day11 {
private:
	bool chkAdd(int a, int b);
	bool chkMul(int a);
public:
	Day11();
	virtual ~Day11();

	void do11();
	int getReversed(int in);
};

class Day12 {
public:
	Day12();
	virtual ~Day12();

	void do12();
};

class Day13 {
public:
	Day13();
	virtual ~Day13();

	void do13();
};

class Day122 {
public:
	Day122();
	virtual ~Day122();

	void do122();
};
#endif /* EXERCISES_H_ */

