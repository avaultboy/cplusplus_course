#include <stdio.h>
#include <iostream>
 
 using namespace std;
 
int main(){
    
    float a = 0;
    float b = 0;
    float res =0;
    char operation;
    char again ;
 
   do {
        
    cout << "������ ���� ���࠭�, ������ (+,-,*,/) � ��ன ���࠭�:" << endl;
    cin >> a;
    cin >> operation;
    cin >> b;
    
    switch (operation){
    case '-':
        res = a - b ;
        break;
    case '+':
        res = a + b ;
        break;
    case '*':
        res = a * b ;
        break;
    case '/':
        res = a / b ;
        break;
    default:
        cout << "�訡��:  �������⭠� ������ !"<<endl<< endl; 
        goto  askAgain;  
     }
    
   cout << "�⢥� = " << res << endl<< endl;
  
  askAgain:
  
   cout<< "�த������ (y/n) ?" << endl;
   cin>>again;
    
   }  while (again == 'y'  || again == 'Y');    

    return 0;
}