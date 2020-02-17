//============================================================================
// Name        : exercise_1_1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int input_number = 0,
		temp_value = 0;
	long long output_number = 0;

	cout << "Enter the input number" << endl;
	cin >> input_number;

	while (input_number != 0)
	{
		temp_value = input_number % 10;

		input_number /= 10;

		output_number = output_number * 10 + temp_value;
	}

	if (output_number > INT_MAX || output_number < INT_MIN)
	{
		cout << "Output number is: 0 (Out of range)" << endl;

		return 0;
	}

	cout << "Output number is:" << output_number << endl;

	return 0;
}
