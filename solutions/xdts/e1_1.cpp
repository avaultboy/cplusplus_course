#include <stdio.h>
#include <iostream>
#include <climits>
 
 using namespace std;
 
int main(int argc, char **argv)
{
    int32_t  InNumber=0;
    long  long OutNumber = 0;
    
    cout<<"INT_MIN = "<<INT_MIN<<endl;
    cout<<"INT_MAX = "<<INT_MAX<<endl;
    
    cout<<"Enter your number: ";
    cin>>InNumber;
    cout<<"\n";
    
    cout<<"Inverted "<<InNumber<<" is "<<endl;  
 
   while(InNumber)
   {
      OutNumber = OutNumber*10 + InNumber%10;
       InNumber /= 10;
   }
   
    if (  OutNumber < INT_MIN  ||  OutNumber > INT_MAX )  {
         OutNumber = 0; 
         cout<<" Output  overflow !!! "<<endl; 
    }

    cout<<" Output number: "<<OutNumber<<endl;
    return 0;
    }
