
#include <iostream>
#include <climits>
using namespace std;

int rotate (int number) {
	int sign = 1;
	int digit;
	int result = 0;
	int resultPrev = 0;

	if (number < 0) { //check if number is positive or negative
		sign = -1;    //store the sign: -1 or +1;
	}
	number *= sign;   //remove sign to operate with positive number

	do {
		resultPrev = result; //store result of previous iteration
		digit = number % 10; //get last digit of the number
		number /= 10;        //remove last decimal place of the number
		result *= 10;        //add one decimal place to the result
		result += digit;     //add the digit

		//check if result exceeds max value for int, if it is then there is overflow and result becomes negative value
		//so compare result and resultPrev
		if (resultPrev > result || result > INT_MAX)//check for result > INT_MAX is redundant, for 32bits int type first check is enough
		{
			result = 0;
			number = 0;
		}

	} while (number > 0);

	return sign*result;
}

bool isPalindrome(int number){
	bool result = false;
	if (number > 0) {
		result = (number == rotate(number));
	}
	return result;
}





int main() {
	int number;
	cout << "Enter number: ";
	cin >> number;
	cout << "You entered: " << number << endl;
	cout << "Number is palindrome: " << boolalpha << bool(isPalindrome(number)) << endl;
	return 0;
}
