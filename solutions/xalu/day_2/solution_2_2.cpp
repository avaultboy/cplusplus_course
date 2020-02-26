#include <iostream>

using namespace std;

int getWordLen (int number) {
   switch (number) {
      case 1:  return   3; //one
      case 2:  return   3; //two
      case 3:  return   5; //three
      case 4:  return   4; //four
      case 5:  return   4; //five
      case 6:  return   3; //six
      case 7:  return   5; //seven
      case 8:  return   5; //eight
      case 9:  return   4; //nine
      case 10: return   3; //ten
      case 11: return   6; //eleven
      case 12: return   6; //twelve
      case 13: return   8; //thirteen
      case 14: return   8; //fourteen
      case 15: return   7; //fifteen
      case 16: return   7; //sixteen
      case 17: return   9; //seventeen
      case 18: return   8; //eighteen
      case 19: return   8; //nineteen
      case 20: return   6; //twenty
      case 30: return   6; //thirty
      case 40: return   5; //fourty
      case 50: return   5; //fifty
      case 60: return   5; //sixty
      case 70: return   7; //seventy
      case 80: return   6; //eighty
      case 90: return   6; //ninety
      case 100: return  7; //hundred
      case 1000: return 11; //one thousand
      default : return 0;
   }
}

int main()
{
   int number = 0, length = 0;
   while (number < 1 or number > 1000) {
      cout << "Введите число (от 1 до 1000):" << endl;
      cin >> number;
   }
   cout << "Длина числа: ";
   if (number == 1000){
      cout << getWordLen(number) << endl;
   } else if (number > 99) {
      length += getWordLen(number/100);
      length += getWordLen(100);
      if (number%100 == 0) {
         cout << length;
         return 0;
      } else {
         length += 3; //and
      }
      number %= 100;
   }
   if (number > 20) {
      if (number %10 == 0) {
         length += getWordLen(number);
      } else {
         length += getWordLen((number/10)*10);
         length += getWordLen(number%10);
      }
   } else {
      length = getWordLen(number);
   }
   cout << length;
   return 0;
}