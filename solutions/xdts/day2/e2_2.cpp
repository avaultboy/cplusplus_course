    #include <iostream>
    #include <string>

   using namespace std;

    string ones[10] = {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10]= {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    string nameForNumber (long number) {
        if (number < 10) {
            return ones[number];
        } else if (number < 20) {
            return teens [number - 10];
        } else if (number < 100) {
            return tens[number / 10] + ((number % 10 != 0) ? "-" + nameForNumber(number % 10) : "");
        } else if (number < 1000) {
            return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " and " + nameForNumber(number % 100) : "");
        } else if (number == 1000) {
            return  "one thousand" ;
        }
        return "error";
    }

    int main()
    {
        long input;
        int LenWithout = 0;
        string Input2String;
        do
        {
            cout << "Please enter a positive integer (1-1000) : ";
            cin >> input;
            Input2String = nameForNumber(input) ;
            if (Input2String == "error") {
                cout << endl ;
                continue;
            }
            cout << endl << Input2String << endl << endl;
            int l =Input2String.length();
            for (int i=0; i<l; ++i) {
                if ((Input2String[i] != ' ') && (Input2String[i] !=  '-' ))  {
                    ++LenWithout;
                }
            }
            if (LenWithout) {
                cout << "Length without  ' ' and '-'  : " << LenWithout << endl << endl;
            }
            LenWithout = 0;
        }while (input > 0);
        return 0;
    }