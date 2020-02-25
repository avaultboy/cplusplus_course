
#include <iostream>
#include <climits>
using namespace std;


bool isPalindrome(char* numArray, char length){
    char i = 0;
    if (length == 1){
        return true;
    } else {

        while (i < length/2 && (numArray[i] == numArray[length - 1 - i])){
            i++;
        }
        return i == length/2;
    }
}

bool isDecimalPalindrome(int number){
	char decimal[10];
	char length = 0;
	if (number < 0){
		return false;
	} else {
		do {
		    decimal[length++] = number % 10;
		    number /= 10;
		} while(number > 0);
		return isPalindrome(decimal, length);
	}
}

bool isBinaryPalindrome(int number){
	char binary[32];
    char length = 0;
    if (number < 0){
        return false;
    } else {
        do {
            binary[length++] = number & 1;
            number >>= 1;
        } while(number > 0);
        return isPalindrome(binary, length);
    }
}

int main() {
	int number;
	cout << "Enter number: ";
	cin >> number;
	cout << "You entered: " << number << endl;
	//just for fun: all dual palindromes from 0 till entered number
//	for (int i=0; i<number; i++){
//	    if (isDecimalPalindrome(i)&&isBinaryPalindrome(i)) {
//	        cout << i << endl;
//	    }
//	}
	cout << "Is decimal and binary palindrome: " << boolalpha << (isDecimalPalindrome(number) && isBinaryPalindrome(number)) << endl;
	return 0;
}
