// 1_2
#include <iostream>
#include <string>

using namespace std;

int main() {

	int integer = 0;
	cin >> integer;
	if (integer > 0) {
		int num = integer;
		int result = 0;

		while (integer)
		{
			result = result * 10 + integer % 10;
			integer /= 10;
		}
		
		if (result == num)
		cout << "true";
		else
		cout << "false";

	}
	else
		cout << "false";
}
