#include <stdio.h>
#include <iostream>
#include <climits>
 
 using namespace std;
 
// function declaration
 bool Palindrom(int32_t , int ) ;
 
int main()
{

    int32_t  InNumber=0;

    bool isPalindrom2Base = false;
    bool isPalindrom10Base = false;
    
    cout<<"INT_MIN = "<<INT_MIN<<endl;
    cout<<"INT_MAX = "<<INT_MAX<<endl;
    
    cout<<"Enter your number: ";
    cin>>InNumber;
    cout<<endl;

    isPalindrom10Base = Palindrom(InNumber, 10);
    isPalindrom2Base = Palindrom(InNumber, 2);
    
    if  ( isPalindrom10Base && isPalindrom2Base) {
        cout<<"Input number: "<<InNumber<< " is BOTH 2- and 10-based palindrom  "<<endl;
    } 
    else {
        cout<<"Input number: "<<InNumber<< " is NOT BOTH 2- and 10-based palindrom  "<<endl;
    }
    return 0;
    }

// function definition
 bool Palindrom(int32_t Number, int Base)  {
    long  long OutNumber = 0;
    bool isPalindrom = false;
    int32_t SaveNumber = Number;
    
    while(Number)
    {
      OutNumber = OutNumber*Base + Number%Base;
       Number /= Base;
    }
   
    if (  OutNumber < INT_MIN  ||  OutNumber > INT_MAX )  {
         OutNumber = 0; 
         cout<<" Output  overflow !!! "<<endl; 
         return isPalindrom; 
    }
   if (SaveNumber == OutNumber) {
     isPalindrom = true;
   }
  return isPalindrom; 
 }
