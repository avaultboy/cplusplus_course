//============================================================================
// Name        : day_1_2_2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

bool checkDigit(long startValue)
{
	int startValueChecking = startValue;
	for (int i = 0; i < 9; i++)
	{

		int numberLast = startValueChecking  % 10;
		startValueChecking /= 10;
		int checkdValue123 = startValueChecking;
		for (int j = i + 1; j < 10; j++)
		{

			int lastToCheck = checkdValue123 % 10;
			if (numberLast == lastToCheck)
			{
				return false;
			}
			checkdValue123 /= 10;
		}
	}
	return true;
}

int main()
{

	long startValue = 123456789;
	int check = 1;

	while (true)
		{
		startValue++;
			if (checkDigit(startValue))
			{
				check++;

				if (check == 100000)
				{
					break;
					cout<<startValue;
				}
			}
		}

	return 0;
}
