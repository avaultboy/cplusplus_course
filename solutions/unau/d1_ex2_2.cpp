#include <iostream>

using namespace std;

int main()
{
	int number = 123456789;
	int counter = 0;
	bool check_number(int number);
	while (true) {
		if (check_number(number)) counter++;
		if (counter == 100000) break;
		number++;
	}
	cout << "0" << number;
	return 0;
}

bool check_number(int number) {
	bool check_zero = false;
	if (number <= 987654321) check_zero = true;
	int check = number % 10;
	int number_back = number / 10;
	number /= 10;
	int flag = 0;
	while (number_back) {
		while (!flag && number) {
			flag = 0;
			if (check == number % 10 || (check_zero == true && check == 0)) flag = 1;
			if (flag == 1) {
				return false;
			}
			number /= 10;
		}
		number = number_back;
		check = number % 10;
		number_back /= 10;
		number /= 10;

	}
	return true;
}
