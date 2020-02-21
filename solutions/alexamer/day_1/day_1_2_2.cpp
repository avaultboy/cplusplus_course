//============================================================================
// Name        : day_1_2_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

bool nextiter(int ta)
{
	int di, dj, tai = ta, taj;
	for (int i = 0; i < 9; i++)
	{
//		di = (int)(ta / pow(10, i)) % 10;
		di = tai  % 10;
		tai /= 10;
		taj = tai;
		for (int j = i + 1; j < 10; j++)
		{
//			dj = (int)(ta / pow(10, j)) % 10;
			dj = taj % 10;
			if (di == dj)
			{
				return false;
			}
			taj /= 10;
		}
	}
	return true;
}

int main()
{
	clock_t start = clock();
	long long a = 123456789;
	int counter = 1;
//	cout << nextiter(123456789);
	while (true)
	{
		a++;
		if (nextiter(a))
		{
			counter++;
//			if (counter % 1000 == 0)
//				cout << counter << endl;
			if (counter == 100000)
			{
				break;
			}
		}
	}
	clock_t end = clock();
	cout << ((end - start) / CLOCKS_PER_SEC) << endl << a << endl;
	return 0;
}
