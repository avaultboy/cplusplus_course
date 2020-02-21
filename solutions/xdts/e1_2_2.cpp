#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// calculate Factorial
int fact(int n)
{
  return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

int main() 
{

auto t1 = chrono::high_resolution_clock::now(); 
   
/*
int fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
3628800, 39916800, 479001600}; // вспомогательный массив факториалов
 */
 
int n = 10;                 // число цифр в 012..89
int num = 100000;   // номер перестановки
int savenum = num;

/*
int digit[n] = {0,0,0,0,0,0,0,0,0,0};  // маска использованных цифр 0..9 ( f.e. digit [7] = 1  -  использована 7 )
 */
 int  digit0 = 0,
       digit1 = 0,
       digit2 = 0,
       digit3 = 0,
       digit4 = 0,
       digit5 = 0,
       digit6 = 0,
       digit7 = 0,
       digit8 = 0,
       digit9 = 0;
       
 
int d;
int Np;
string result="";   //  результат

for (int i=n; i>0;--i){
  Np=num%fact(i-1);  //Определение номера группы перест.
  d=num/fact(i-1);      //Определение индекса текущей цифры
  cout<<"Position = "<<i<<" Np = "<<Np<<" d = "<<d<<endl;
  if (Np) d++; else Np+=fact(i-1);
  num=Np;
  //
  int pos=0;
  
  if (!digit0 ) {
      cout<<"-- test digit  :  0"<<endl;
      pos++;
      if ( d == pos) {
        digit0 = 1;
        result += to_string(0);
        continue;
        }
  }

  if (!digit1) {
      cout<<"-- test digit  :  1"<<endl;
      pos++;
      if ( d == pos) {
        digit1 = 1;
        result += to_string(1);
        continue;
        }
  }
  
  if (!digit2) {
     cout<<"-- test digit  :  2"<<endl;
     pos++;
      if ( d == pos) {
        digit2 = 1;
        result += to_string(2);
        continue;
        }
  }
  
  if (!digit3) {
     cout<<"-- test digit  :  3"<<endl;
     pos++;
      if ( d == pos) {
        digit3 = 1;
        result += to_string(3);
        continue;
        }
  }
  
  if (!digit4) {
     cout<<"-- test digit  :  4"<<endl;
     pos++;
      if ( d == pos) {
        digit4 = 1;
        result += to_string(4);
        continue;
        }
  }
  
  if (!digit5) {
     cout<<"-- test digit  :  5"<<endl;
     pos++;
      if ( d == pos) {
        digit5 = 1;
        result += to_string(5);
        continue;
        }
  }
  
  if (!digit6) {
     cout<<"-- test digit  :  6"<<endl;
     pos++;
      if ( d == pos) {
        digit6 = 1;
        result += to_string(6);
        continue;
        }
  }
  
  if (!digit7) {
     cout<<"-- test digit  :  7"<<endl;
     pos++;
      if ( d == pos) {
        digit7 = 1;
        result += to_string(7);
        continue;
        }
  }
  
  if (!digit8) {
     cout<<"-- test digit  :  8"<<endl;
     pos++;
      if ( d == pos) {
        digit8 = 1;
        result += to_string(8);
        continue;
        }
  }
  
  if (!digit9) {
      cout<<"-- test digit  :  9"<<endl;
      pos++;
      if ( d == pos) {
        digit9 = 1;
        result += to_string(9);
        continue;
        }
  }
 
}   

  //
  /*
  int pos=0;
  for (int j=0;j<=n;++j){ //Определение текущей цифры
    cout<<"-- test digit  : "<<j<<endl;
    if (!digit[j]) pos++;
    if (pos==d) {
      digit[j]=1;
      result += to_string(j);  //Формирование перестановки
      break;
    }
     */
    //
 //  }
//}

 // Вывод результата на экран
 cout << endl<<"num = " <<savenum<< " :  " ;
 cout<<result<<endl;
 
 auto t2 = chrono::high_resolution_clock::now();
 
 auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
 
 cout <<endl<<"Time elapsed: " <<duration /1000000.0<<" sec"<<endl;
 
return 0;

}