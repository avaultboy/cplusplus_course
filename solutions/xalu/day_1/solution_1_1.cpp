//развернуть число
#include <iostream>
#include <climits>

using namespace std;

int main()
{
   int number;
   cout << "Введите число:" << endl;
   cin >> number;
   int rev = 0;
   while (number != 0)
   {
      int pop = number % 10;
      number /= 10;

      if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) {
          rev = 0;
          break;
      }
      if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) {
          rev = 0;
          break;
      }
      rev = rev*10 + pop;
   }
   cout << "обратное представление числа: " << rev;
   return 0;
}

/* упрощенное решение с использованием типа long long
int main()
{
   int number;
   cout << "Введите число:" << endl;
   cin >> number;
   long long rev = 0;
   while (number != 0)
   {
      rev = rev*10 + number%10;
      number /= 10;
   }
   if (rev > INT_MAX or rev < INT_MIN) {
      cout << "обратное представление числа: 0";
   } else {
      cout << "обратное представление числа: " << rev;
   }
   return 0;
}

*/