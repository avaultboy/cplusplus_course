//============================================================================
// Name        : day_3_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void checkExit();

int main() {
	int one, three;
	char two;
	cout<<"Input first, second and third operands: "<<endl;
	cin>>one>>two>>three;

	switch(two)
	{
	case '+': {cout<<one+three<<endl;
	break;}
	case '-': {cout<<one-three<<endl;
	break;}
	case '*': {cout<<one*three<<endl;
	break;}
	case '/': {cout<<one/three<<endl;
	break;}
	}
	cout<<"Continue?"<<endl;
	checkExit();


	return 0;
}

void checkExit()
{
char check;
	    cin>>check;
	    if(check=='y')
	    {main();}
	    else if(check=='n')
			{exit(0);}
	    else{cout<<"Wrong value! Try again:"<<endl;checkExit();}
	}
