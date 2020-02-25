//============================================================================
// Name        : day_2_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int lengthNumber(int num);

int main() {
	int number;
	cin>>number;
	switch(number)
	{
	case 100:cout<<7;break; //hundred
	case 1000:cout<<8;break; //thousand
	default:cout<<(lengthNumber(number));
	}
	return 0;
}


int  lengthNumber(int num)
{
	string digits[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string digits1[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",};
	string digits2[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	if (num<10)
	{
		return digits[num].length();
	}
	if(num>9 && num<20)
	{
		return digits1[num%10].length();
	}
	if (num>19 && num < 100)
	{
		return ((digits2[num/10]+digits[num%10]).length());
	}
	if(num>100 && num%100<10 )
	{
		return (digits[num/100]+"hundredand"+digits[num%10]).length();
	}
	if(num>100 && num%100<20 )
	{
		return (digits[num/100]+"hundredand"+digits1[num%10]).length();
	}
	if(num>100 && num%10 == 0)
	{
		return (digits[num/100]+"hundredand"+digits2[num%100/10]).length();
	}
	if(num>100)
	{
		return (digits[num/100]+"hundredand"+digits2[num%100/10]+digits[num%10]).length();
	}




	return 0;
}
