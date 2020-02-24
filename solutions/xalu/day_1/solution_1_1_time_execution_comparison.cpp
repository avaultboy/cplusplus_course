//сравнение времени выполнения при конвертации в строку
#include <iostream>
#include <climits>
#include <ctime>

using namespace std;

class MyTimer
{
public:
   MyTimer():_t(clock()){};
   void reset(){_t=clock();};
   double getTime(){return (double(clock()-_t))/CLOCKS_PER_SEC;}
   long getT(){return _t;}
private:
   clock_t _t;
};

int checkZero(int a);
int convertToInt(string s);

int checkZero(int a)
{
   if(a%10 == 0) {
      a=a/10;
      checkZero(a);
   } else {
      return a;
   }
}

int convertToInt(string s)
{
   try{
      int l = stoi(s);
      return l;
   }
   catch(const out_of_range &){
      return 0;
   }
}

int reverse(int x) {
   int k=-1;
   if (x > 0){
      k=1;
   }
   x = checkZero(x);
   string s = to_string(x);
   s.assign(s.rbegin(), s.rend());
   x = convertToInt(s);
   return x*k;
}
int reverse2(int number){
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
   return rev;
}


int main () {
   MyTimer _t;
   for (int i = 0; i < 1000000; ++i )
   {
      reverse2(12345678);
   }
   cout << _t.getTime() << endl; //~0.063
   _t.reset();
   for (int i = 0; i < 1000000; ++i )
   {
      reverse(12345678); //~4.764
   }
   cout << _t.getTime();
   return 0;
}
