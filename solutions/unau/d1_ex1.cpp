#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int number;
	long long revert = 0;
	cin >> number;
	while (number != 0) {
		revert *= 10;
		revert += (number % 10);
		number /= 10;
	}
	if (revert > INT_MAX || revert < INT_MIN) {
		cout << 0 << endl;
	}
	else {
		cout << revert << endl;
	};
	return 0;
}
