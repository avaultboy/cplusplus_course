//============================================================================
// Name        : exercise_1_2_2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool checkIfDigitsOccureOnce(long long);
bool checkDigitOccurance(long long, int);
bool compareDigits(int, int);

bool checkIfDigitsOccureOnce(long long permutation_to_check)
{
	long long int permutation = permutation_to_check;
	int current_digit = 0;
	bool flag = true;

	for (int c_count = 0; c_count < 9; c_count++)
	{
		current_digit = 0;
		current_digit = permutation % 10;
		permutation /= 10;

		if (!(checkDigitOccurance(permutation, current_digit)))
		{
			flag = false;
			break;
		}
	}

	return flag;
}

bool checkDigitOccurance(long long permutation, int digit_to_check)
{
	int current_digit = 0;
	long long temp_permutation = permutation;
	bool flag = true;

	for (int c_count = 0; c_count < 9; c_count++)
	{
		current_digit = temp_permutation % 10;

		if (compareDigits(current_digit, digit_to_check))
		{
			flag = false;
			break;
		}

		temp_permutation /= 10;
	}

	return flag;
}

bool compareDigits(int digit_1, int digit_2)
{
	if (digit_1 == digit_2)
	{
		return true;
	}

	return false;
}

int main()
{
	long long initial_permutation = 123456789; // 0123456789
	int c_count = 1;

	while (c_count < 100000)
	{
		initial_permutation += 1;
		if (checkIfDigitsOccureOnce(initial_permutation))
		{
			c_count++;
		}
	}

	cout << initial_permutation << endl;

	//   Answer: 0358926471

	return 0;
}
