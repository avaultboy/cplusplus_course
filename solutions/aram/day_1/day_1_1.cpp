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
int convertToInt(string s);

int main() {
	int x;
	cin >> x;
	int k=-1;
	if(x>0)
	{k=1;}
		x = checkZero(x);
	    string s = to_string(x);
	    s.assign(s.rbegin(), s.rend());
    	x = convertToInt(s);
	    cout << x*k << endl;

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
int convertToInt(string s)
{
	try{int l = stoi(s);return l;}
	catch(const out_of_range &){return 0;}
}

