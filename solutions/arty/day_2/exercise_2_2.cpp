//============================================================================
// Name        : exercise_2_2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int input_number = 0;
	string output_words = "";

	string digit_bundle[2][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
								  "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	string digit_teen_bundle[10] = {
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen",
	};

	int digits[3] = {0, 0, 0};

	cout << "Enter the number (1-1000):" << endl;
	cin >> input_number;

	if (input_number == 1000)
	{
		cout << (output_words += "onethousand").length() << endl;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			digits[i] = input_number % 10;
			input_number /= 10;
		}

		// hundreds

		if (digits[0] == 0 && digits[1] == 0)
		{
			cout << (output_words += digit_bundle[0][digits[2]] + "hundred").length() << endl;
			return 0;
		}
		digits[2] == 0 ? output_words += "" : output_words += digit_bundle[0][digits[2]] + "hundred" + "and";

		// tens

		if (digits[1] == 1)
		{
			cout << (output_words += digit_teen_bundle[digits[0]]).length() << endl;
			return 0;
		}

		output_words += digit_bundle[1][digits[1]];

		// singles

		cout << (output_words += digit_bundle[0][digits[0]]) << endl;
	}

	cout << output_words.length() << endl;

	return 0;
}