//============================================================================
// Name        : exercise_1_2.cpp
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
	long long initial_number = 0,
			  input_number = 0,
			  temp_value = 0;
	long long output_number = 0;

	cout << "Enter the input number" << endl;
	cin >> input_number;

	if (input_number < 0)
	{
		cout << "False" << endl;
	}
	else
	{
		initial_number = input_number;

		while (input_number != 0)
		{

			temp_value = input_number % 10;

			input_number /= 10;

			output_number = output_number * 10 + temp_value;
		}

		initial_number == output_number ? cout << "True" << endl : cout << "False" << endl;
	}

	return 0;
}
