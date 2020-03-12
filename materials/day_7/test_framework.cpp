#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int addition(int a, int b) {
   return a + b;
}
int subtraction (int a, int b) {
   return a - b;
}
int multiplication (int a, int b) {
   return a * b;
}

double division(double a, double b) {
   return a / b;
}

template <class T> void addVector (vector<T>& v1, const vector<T>& v2) {
   unsigned int size = min(v1.size(), v2.size());
   for (unsigned int i = 0; i < size; ++i)
      v1[i] += v2[i];
}
template <class T>
ostream& operator << (ostream& os, vector<T> v) {
   os << "{ ";
   for (auto m : v) {
      os << m << " ";
   }
   os << "}";
   return os;
}

class TestFramework {
   TestFramework(); //Forbid creation of object
protected:
   template <class T, class U>
   static void AssertEqual(const T& t, const U& u, const string& hint) {
      if (t != u) {
         ostringstream os;
         os << "Assertion failed: " << t << " != " << u
            << " Hint: " << hint;
         throw runtime_error(os.str());
      }
   }
   class TestRunner {
   public:
      TestRunner() : passed(0),failed(0){}
      ~TestRunner() {
         if (!failed)
            cout << "TestAll OK: "
            << passed << " passed.\n";
         else
            cerr << "TestAll FAIL: "
                 << passed << " passed, "
                 << failed << " failed.\n";
      }
      template <class FuncType>
      void RunTest(FuncType func,const string& testName) {
         try {
            func();
            cout << testName << " OK\n";
            ++passed;
         }
         catch (runtime_error& err) {
            cerr << "Test " << testName << " failed: "
                 << err.what() << endl;
            ++failed;
         }
      }
   private:
      int passed;
      int failed;
   };
};

class Tests : public TestFramework {
   Tests(); //Forbid creation of object

   static void TestAdd() {
      AssertEqual(addition(3,5),8,"add 3+5");
   }

   static void TestSub() {
      AssertEqual(subtraction(3,5),-2,"sub 3-5");
   }

   static void TestMul() {
      AssertEqual(multiplication(3,5),15,"mul 3*5");
   }

   static void TestDiv() {
      AssertEqual(division(3,5),0.6,"div 3/5");
   }

   static void TestAddVector() {
      vector<int> expect{3,5,7};
      vector<int> v1{1,2,3},v2{2,3,4};
      addVector(v1,v2);
      AssertEqual(v1,expect,"addVector {1,2,3} + {2,3,4}");
   }

public:
   static void TestAll() {
      TestRunner tr;
      tr.RunTest(TestAdd,"TestAdd");
      tr.RunTest(TestSub,"TestSub");
      tr.RunTest(TestMul,"TestMul");
      tr.RunTest(TestDiv,"TestDiv");
      tr.RunTest(TestAddVector,"TestAddVector");
   }
};

int main() {
   Tests::TestAll();
   return 0;
}
