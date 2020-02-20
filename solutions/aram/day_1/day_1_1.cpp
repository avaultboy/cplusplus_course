//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

int checkZero(int a);
int reverse(int n);

int main() {
	int x;
	cin >> x;
	int k=-1;
	if(x>0)
	{k=1;}
		x = checkZero(x);
	    x = reverse(x);

	    cout << x << endl;

	return 0;
}

int checkZero(int a)
    {
		if(a%10 == 0)
		{
			a=a/10;
			checkZero(a);
		}
		else
		{
			return a;
		}
	}

int reverse(int n) {
    int r = n%10;
    while (n/=10) {
        r = r*10 + n%10;
    }
    return r;
}
