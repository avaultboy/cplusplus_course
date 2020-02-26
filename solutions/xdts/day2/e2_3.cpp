
#include <iostream>

using namespace std;

int main()
{
    const int arr[10] = { 1, 9, 8, 6, 7, 2, 4, 5, 3 };
    const int* ptrArr[10];
    int trigger[10] = {0};
    int min;
    int minind;
    const int  bigbig = 666;
    
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    
    cout <<"Size of arr : "<<arrSize<<endl;
    
 
    for (int i=0; i < arrSize; ++i) {
        cout <<"arr["<< i << "] : " << arr[i] <<endl;
    }
    for (int i=0; i < arrSize; ++i) {
        cout << "&arr[" << i << "] : " << &arr[i] <<endl;
    }
    
    
    min = bigbig;
    int j = 0;
    bool endOfSort =false; 
    
     while (!endOfSort) {    
        endOfSort = true;
        for (int i=0; i < arrSize; ++i) {
           if (trigger[i] == 0) {
               if ( arr[i] <  min ) {
                  min = arr[i];
                  minind = i; 
                  endOfSort = false;
               } 
           }
       }
       if (!endOfSort) {
         trigger[minind] = 1;
         ptrArr[j ] = &arr[minind];
         ++j;
         min = bigbig;
       }
    } 
   
     for (int i=0; i < arrSize; ++i) {
        cout << "ptrArr[" << i << "]  : " << ptrArr[i] <<endl;
    }
        
	return 0;
}
