//простой калькулятор
#include <iostream>

using namespace std;

int main()
{
   double n1,n2,answer;
   char operation,ch;
   do {
      cout << "Введите первый операнд, операцию и второй операнд:" << endl;
      cin >> n1 >> operation >> n2;
      switch (operation) {
         case '+': answer = n1 + n2; break;
         case '-': answer = n1 - n2; break;
         case '*': answer = n1 * n2; break;
         case '/': answer = n1 / n2; break;
         default:  answer = 0;
      }
      cout << "Ответ = " << answer << endl;
      cout << "\nПродолжить (y/n)?" << endl;
      cin >> ch;
   } while (ch != 'n');
   return 0;
}