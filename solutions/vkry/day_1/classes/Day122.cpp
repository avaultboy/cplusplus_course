/*
 * Day122.cpp
 *
 *  Created on: Feb 24, 2020
 *      Author: vkry
 */

#include "exercises.h"
#include <cmath>

using namespace std;

Day122::Day122() {
	// TODO Auto-generated constructor stub

}

Day122::~Day122() {
	// TODO Auto-generated destructor stub
}

void Day122::do122(){

	int perm = 100000;

	int permutation = perm - 1;
	long long number = 10123456789;
	long long order = 1;
	int quotient = 1;

	long long res = 0;

	while (permutation > 0)
	{
		int tmp = permutation % quotient;
		permutation /= quotient;
		quotient++;
		order *= 10;
		order += tmp;
//		cout << permutation << endl;
	}

	if (order < 10000000000)
	  {
//	    cout << "order: " << order << endl;
	    int tmp = order;
	    int numOfDigits = 0;
	    while (tmp > 0)
	    {
	      tmp /= 10;
	      numOfDigits++;
	    }
//	    cout << "digits " << numOfDigits << endl;
	    int power = 10 - numOfDigits + 1;
//	    cout << "power " << power << endl;
	    int tmp1 = pow(10, power) + 0.5;
//	    cout << sizeof(tmp1) << endl;
//	    cout << INT32_MAX << endl;
//	    cout << "tmp1: " << tmp1 << endl;
	    order = order * tmp1;

//	    cout << "order: " << order << endl;

	  }

	for (int i = 10; i > 0; i--) {
		int lastOfOrder = order % 10;
		order /= 10;
		//cout << "last: " << lastOfOrder << endl;
		double power = i - (lastOfOrder + 1);
		int tenInPower = pow(10.0, power) + 0.5;
		int quot = number / tenInPower;
		int rem = number % tenInPower;
		int x = quot % 10;

//		cout << "quot: " << quot << endl;
//		cout << "x: " << x << endl;
//		cout << "rem: " << rem << endl;

		res += x;
		if (i != 1)
		{
			res *= 10;
		}

		number = quot / 10;
		number *= tenInPower;
		number += rem;

		//cout << "number " << number << endl;
		//cout << "res " << res << endl;
		//cout << endl;


	}

	cout << perm << " permutation of 0123456789 is: " << endl;
	cout << res << endl;
}

