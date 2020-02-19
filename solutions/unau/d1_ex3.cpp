#include <iostream>

using namespace std;

int main()
{
	int number_1, number_2;
	float result = 0;
	char operand,flag;
	do{
	cout << "Enter the first number, the operand and the second number: " << endl;
	cin >> number_1 >> operand >> number_2;
	switch (operand)
	{
	case '+':
		result = number_1 + number_2;
		break;
	case '-':
		result = number_1 - number_2;
		break;
	case '*':
		result = number_1 * number_2;
		break;
	case '/':
	case ':':
		result = float(number_1) / float(number_2);
		break;
	default:
		break;
	}
	cout << result << endl << "Would you like to continue? (y/n)?" << endl;
	cin >> flag;
	while (flag  != 'n' && flag != 'y') {
		cout << "Wrong symbol, enter y or n" << endl;
		cin >> flag;
	};
	} while ( flag  == 'y');
	return 0;
}
