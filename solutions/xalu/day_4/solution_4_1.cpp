#include <algorithm>
#include <deque>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <vector>


using namespace std;

typedef unsigned int uint;

typedef deque<string> DS;
typedef vector<string> VS;
typedef VS::iterator VS_It;
typedef set<string> SS;
typedef SS::iterator SS_It;
typedef list<string> LS;
typedef LS::iterator LS_It;

class MyTimer {
public:
   MyTimer():_t(clock()){};
   void reset(){_t=clock();};
   double getTime(){return (double(clock()-_t))/CLOCKS_PER_SEC;}
   long getT(){return _t;}
private:
   clock_t _t;
};

string path = "D:\\names2.txt";
int nofTimes = 100;

uint wordSum(const string& word) {
   uint result = 0;
   for (uint i = 1; i < word.size()-1;++i) {
      result += word[i] - 64;
   }
   return result;
}

long long deque_solution(){
   DS names;
   string name;
   long long sum = 0;

   std::ifstream in(path);
   if (in.is_open()) {
       while (getline(in,name,',')) {
          names.push_back(name);
       }
   }
   in.close();

   sort(names.begin(),names.end());
   for (int it = 0; it < nofTimes; ++it){
      sum = 0;
      for (uint i = 1; i <= names.size();++i) {
         sum += i*wordSum(names[i-1]);
      }
   }
   return sum; //871198282
}

long long vector_solution(){
   VS names;
   string name;
   long long sum = 0;

   std::ifstream in(path);
   if (in.is_open()) {
       while (getline(in,name,',')) {
          names.push_back(name);
       }
   }
   in.close();

   sort(names.begin(),names.end());
   for (int it = 0; it < nofTimes; ++it){
      sum = 0;
      for (uint i = 1; i <= names.size();++i) {
         sum += i*wordSum(names[i-1]);
      }
   }
   return sum; //871198282
}

long long set_solution(){
   SS names;
   string name;
   long long sum = 0;

   std::ifstream in(path);
   if (in.is_open()) {
       while (getline(in,name,',')) {
          if (!names.count(name))
             names.insert(name);
          else
             cout << name << endl;
       }
   }
   in.close();

   for (int it = 0; it < nofTimes; ++it){
      sum = 0;
      int count = 0;
      for (SS_It it = names.begin(); it != names.end(); ++it) {
         sum +=  ++count * wordSum(*it);
      }
   }
   return sum; //871198282
}

long long list_solution(){
   LS names;
   string name;
   long long sum = 0;

   std::ifstream in(path);
   if (in.is_open()) {
       while (getline(in,name,',')) {
          names.push_back(name);
       }
   }
   in.close();

   names.sort();
   for (int it = 0; it < nofTimes; ++it){
      sum = 0;
      int count = 0;
      for (LS_It it = names.begin(); it != names.end(); ++it) {
         sum +=  ++count * wordSum(*it);
      }
   }
   return sum; //871198282
}

int main() {
   long long vs,ss,ls,ds;
   double tv,ts,tl,td;

   MyTimer _t;
   vs = vector_solution();
   tv = _t.getTime();

   _t.reset();
   ds = deque_solution();
   td = _t.getTime();

   ls = list_solution();
   tl = _t.getTime();
   _t.reset();

   _t.reset();
   ss = set_solution();
   ts = _t.getTime();

   cout << "vector " << vs << " = " << tv << endl;
   cout << "deque  " << ds << " = " << td << endl;
   cout << "list   " << ls << " = " << tl << endl;
   cout << "set    " << ss << " = " << ts << endl;
}