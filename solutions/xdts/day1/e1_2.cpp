#include <stdio.h>
#include <iostream>
#include <climits>
 
 using namespace std;
 
int main(int argc, char **argv)
{
    int32_t  InNumber=0;
    int32_t  SaveInNumber=0;
    long  long OutNumber = 0;
    
    cout<<"INT_MIN = "<<INT_MIN<<endl;
    cout<<"INT_MAX = "<<INT_MAX<<endl;
    
    cout<<"Enter your number: ";
    cin>>InNumber;
    cout<<"\n";
    SaveInNumber = InNumber;
 
   while(InNumber)
   {
      OutNumber = OutNumber*10 + InNumber%10;
       InNumber /= 10;
   }
   
    if (  OutNumber < INT_MIN  ||  OutNumber > INT_MAX )  {
         OutNumber = 0; 
         cout<<" Output  overflow !!! "<<endl; 
    }
   if (SaveInNumber == OutNumber) {
    cout<<"Input number: "<<SaveInNumber<< " is palindrom "<<endl; 
    }
    else {
    cout<<"Input number: "<<SaveInNumber<< " is NOT palindrom "<<endl; 
    }
    return 0;
    }
