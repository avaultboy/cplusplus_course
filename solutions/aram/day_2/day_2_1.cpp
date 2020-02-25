#include <iostream>
#include <cmath>

using namespace std;


int reverse(int n) {
    int r = n%10;
    while (n/=10) {
        r = r*10 + n%10;
    }
    return r;
}

int decToBinary(int a) {
long long int n = 0;
int k,m = 0;
while(a) {
    k = a % 2;
    a = a / 2;
    n += k * pow(10, m);
    m++;
}
return n;
}


bool palindromCheck(int n) {
    return n == reverse(n);
}

int main() {
	cout<<"Enter number to check: ";
	int x;
	cin>>x;
	int decimalCheck = palindromCheck(x);
	int binaryCheck = palindromCheck(decToBinary(x));
	if(decimalCheck == 1 && binaryCheck == 1)
	{
		cout<<"Palindrome in two systems";
	}
	else{cout<<"Not a palindrome in two systems";}

}
