#include <iostream>

using namespace std;

int main()
{
	int number;
	long long revert = 0;
	cin >> number;
	int number_backup = number;

	while (number != 0) {
		revert *= 10;
		revert += (number % 10);
		number /= 10;
	}
	(revert == number_backup && number_backup >= 0) ? cout << "It's a polyndrome" << endl : cout << "It's not a polyndrome" << endl;
	return 0;
}
