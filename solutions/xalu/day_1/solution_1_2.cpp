//палиндром число или нет
#include <iostream>

using namespace std;

int main()
{
   int n;
   cout << "Введите число:" << endl;
   cin >> n;

   if(n < 0 || (n % 10 == 0 && n != 0)) {
      cout << "false";
      return 0;
   }

   int rev = 0;
   while (n > rev) {
      rev = rev*10 + n%10;
      n /= 10;
   }
   if (n == rev || n == rev/10) {
      cout << "true";
   } else {
      cout << "false";
   }
   return 0;
}
