//сортировать массив по указателям
#include <iostream>

using namespace std;

int main()
{
   const int arr[10] { 3, 9, 8, 6, 7, 2, 4, 5, 1};
   const int* ptrArr[10];
   
   for (int i = 0; i < 10; ++i) {
      ptrArr[i] = arr+i;
   }
   for (int i = 0; i < 10; ++i) {
      int m = i;
      for (int y = i+1; y < 10; ++y)
      {
         if (*ptrArr[y] < *ptrArr[m]) {
            m = y;
         }
      }
      if (m != i) {
         ptrArr[i] = (const int*)((unsigned int)ptrArr[i] xor (unsigned int) ptrArr[m]);
         ptrArr[m] = (const int*)((unsigned int)ptrArr[i] xor (unsigned int) ptrArr[m]);
         ptrArr[i] = (const int*)((unsigned int)ptrArr[i] xor (unsigned int) ptrArr[m]);
      }
   }
   for (int i = 0; i < 10; ++i) {
      cout << ptrArr[i] << " " <<**(ptrArr+i) << endl;
   }
   return 0;
}