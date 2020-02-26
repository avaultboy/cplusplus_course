//палиндром по основаниям 2 и 10
#include <iostream>

using namespace std;

bool isPalindrome10(int n)
{
   if(n < 0 || (n % 10 == 0 && n != 0)) {
      return false;
   }

   int rev = 0;
   while (n > rev) {
      rev = rev*10 + n%10;
      n /= 10;
   }
   if (n == rev || n == rev/10) {
      return true;
   }
   return false;
}

bool isPalindrome2(int n)
{
   //если число меньше нуля четное или кратное 10-ти => false
   if(n < 0 or (n and !(n%2 and n%10))) {
      return false;
   }

   int bin[32] = {0};
   int len = 0;

   //переводим число в двоичную систему
   while (n/2 or n) {
      bin[len++] = n%2;
      n /= 2;
   }

   //сравниваем начало с концом
   for (int i = 0; i < len/2; ++i) {
      if (bin[i] != bin[len - i - 1]) {
         return false;
      }
   }
   return true;
}

int main()
{
   int n;
   cout << "Введите число:" << endl;
   cin >> n;

   if (isPalindrome10(n)) {
      if(isPalindrome2(n)) {
         cout << "Число является палиндромом по двум основаниям" <<endl;
      } else {
         cout << "Число является палиндромом только по одному основанию" <<endl;
      }
   } else {
      cout << "Число не является палиндромом" <<endl;
   }

   return 0;
}
