// 1_1
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
	
	int integer = 0;
	cin >> integer;
	long long result = 0;
	
	while (integer)
	{
	 result = result*10 + integer%10;
	 integer /= 10;	
	}
	
	if(result >= INT_MAX || result <= INT_MIN)
	cout << 0;
	else
	cout << result;
	
}
