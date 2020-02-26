//============================================================================
// Name        : day_2_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	const int arr[10]{ 1,9,8,6,7,2,4,5,3 }; //arr[9] = 0
	const int* ptrArr[10];

	cout<<"Base list: ";
	for (int i = 0; i <= 9; i++)
		{
			ptrArr[i] = &arr[i];
			cout <<ptrArr[i] << " ";
		}
	for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j <= 10 - i - 1; j++)
			{
				if (*ptrArr[j] > * ptrArr[j + 1])
				{
					const int *temp = ptrArr[j + 1];
					ptrArr[j + 1] = ptrArr[j];
					ptrArr[j] = temp;
				}
			}
		}
	//cout<<endl;
	//for (int i = 0; i <= 9; i++) cout << *ptrArr[i] << " ";
	cout<<endl<<"New list:  ";
	for (int i = 0; i <= 9; i++) cout <<ptrArr[i] << " ";
	return 0;
}
