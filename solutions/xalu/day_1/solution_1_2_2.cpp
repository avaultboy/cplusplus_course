//100k перестановка 0123456789
#include <iostream>
using namespace std;

int main() {
   long long i = 123456788;
   long long check = 987654321;
   int count = 0;
   while (++i < 9876543211) {
      long long i2 = i;
      long long num = 0;
      while (i2) {
         int digit = i2%10;
         int shift = 1;
         for (int d = 1; d < digit; ++d)
         {
            shift *= 10;
         }
         num += digit*shift;
         i2 /= 10;
      }
      if (num == check and ++count == 100000) {
         cout << i << endl;
         break;
      }
   }
   return 0;
}