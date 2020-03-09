#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

long long CalcNameSum(string, long);

int main()
{
    long  nameNum = 1;
    long long nameSum = 0;
    long long finalSum =0;

    ifstream input("D:/ProjectsCPP/4_1/names.txt");
    string name;
    set<string> names;
    cout << "Reading names from file ... " ;
    if (input.is_open()) {
        while (getline(input, name, ',')) {
            //cout << name << endl;
            names.insert(name);
        }
        cout << "done !" << endl;

        cout << "Calculating names from set ... " ;
        for (auto sName : names) {
            nameSum = CalcNameSum(sName,nameNum);
            finalSum += nameSum;
            ++nameNum;
        }
        cout << "done !" << endl;
        cout << endl << "Result: " << --nameNum << " names, " << finalSum << " scores." << endl;
    } else {
        cout << "error!" << endl;

        return 0;
    }
    return 0;
}

long long CalcNameSum(string n, long j)
{
    long long res = 0;
    int strSize = 0;
    // remove " from name
    n.erase(remove(n.begin(), n.end(), '"'), n.end());
    // calculate sum of char
    strSize = n.length();
    for (int i = 0; i < strSize; i++) {
        res += ((int)n[i] - 64) ;
    }
    // mult on position in list
    res = res * j;
    //cout << "Name: " << n <<  " , length: " << strSize << " , pos:  " <<  j << " , res: " << res << endl;
    //
    return res;
}
