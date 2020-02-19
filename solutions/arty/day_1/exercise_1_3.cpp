//============================================================================
// Name        : exercise_1_3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{

	double operand_1, operand_2;

	char operator_to_use;

	string answer;

	cout
		<< "Enter left operand :" << endl;
	cin >> operand_1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid Operand, try one more time:" << endl;
		cin >> operand_1;
	}

	cout << "Enter operator to apply" << endl;
	cin >> operator_to_use;
	cout << "Enter right operand :" << endl;

	cin >> operand_2;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid Operand, try one more time:" << endl;
		cin >> operand_2;
	}

	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid" << endl;
	}

	if (operator_to_use == '+')
	{
		cout << "Result:"
			 << (operand_1 + operand_2) << endl;
	}
	else if (operator_to_use == '-')
	{
		cout << "Result:" << (operand_1 - operand_2) << endl;
	}
	else if (operator_to_use == '/')
	{
		cout << "Result:" << (operand_1 / operand_2) << endl;
	}
	else if (operator_to_use == '*')
	{
		cout << "Result:" << (operand_1 * operand_2) << endl;
	}
	else if (operator_to_use == '%')
	{
		cout << "Result:" << ((int)operand_1 % (int)operand_2) << endl;
	}
	else if (operator_to_use == '|')
	{
		cout << "Result:" << ((int)operand_1 | (int)operand_2) << endl;
	}
	else if (operator_to_use == '&')
	{
		cout << "Result:" << ((int)operand_1 & (int)operand_2) << endl;
	}
	else if (operator_to_use == '^')
	{
		cout << "Result:" << ((int)operand_1 ^ (int)operand_2) << endl;
	}
	else
	{
		cout << "Available operators are: +, -, /, *, %, |, &, ^" << endl;
	}

	do
	{
		answer = "";
		cout << "Do you want to Continue? (Y/N)" << endl;
		cin >> answer;

		cout << answer << endl;

		if (answer == "Y" || answer == "y")
		{
			main();
			break;
		}
	} while (answer != "n" && answer != "N");

	return 0;
}
