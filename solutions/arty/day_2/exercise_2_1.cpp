//============================================================================
// Name        : exercise_2_1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

bool decimalSystemCheck(long long initial_number)
{
	long long input_number = 0, output_number = 0, temp_value = 0;

	input_number = initial_number;

	while (input_number != 0)
	{
		temp_value = input_number % 10;
		input_number /= 10;
		output_number = output_number * 10 + temp_value;
	}

	return initial_number == output_number ? true : false;
}

bool binarySystemCheck(long long initial_number)
{
	string binary_number;

	do
	{
		binary_number += ('0' + (initial_number % 2));
		initial_number /= 2;
	} while (initial_number > 0);

	for (int i = 0; i < (binary_number.length()) / 2; i++)
	{
		if (binary_number[i] != binary_number[binary_number.length() - i - 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	long long initial_number = 0;

	cout << "Enter the initial number" << endl;
	cin >> initial_number;

	if (initial_number < 0)
	{
		cout << "False" << endl;
	}
	else
	{
		(decimalSystemCheck(initial_number) && binarySystemCheck(initial_number)) ? cout << "True" << endl : cout << "False" << endl;
	}

	return 0;
}
