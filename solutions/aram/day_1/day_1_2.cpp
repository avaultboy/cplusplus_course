//============================================================================
// Name        : polindrom.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;


int reverse(int n) {
    int r = n%10;
    while (n/=10) {
        r = r*10 + n%10;
    }
    return r;
}


bool palindromCheck(int n) {
    return n == reverse(n);
}

int main() {
	int x;
	cin>>x;
    std::cout << palindromCheck(x);
}
