#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int number;
	long long revert = 0, number_bin = 0, revert_bin = 0, temp;
	cin >> number;
	int number_backup = number;

	while (number != 0) {
		revert *= 10;
		revert += (number % 10);
		number /= 10;
	}
	temp = number_backup;
	while (temp != 0) {
		number_bin *= 10;
		number_bin += temp % 2;
		temp /= 2;
	}
	temp = revert;
	while (temp != 0) {
		revert_bin *= 10;
		revert_bin += temp % 2;
		temp /= 2;
	}
	cout << number_bin << endl << revert_bin << endl;
	(revert == number_backup && number_backup >= 0 && number_bin == revert_bin) ? cout << "It's a polyndrome in both systems" << endl : cout << "It's not a polyndrome" << endl;
	return 0;
}
