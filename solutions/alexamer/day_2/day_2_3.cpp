//============================================================================
// Name        : day_2_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int arr[10] {
//	1, 9, 8, 6, 7, 2, 4, 5, 3, 0
	9, 6, 4, 8, 2, 0, 5, 3, 7, 1
};
const int* ptrArr[10];

int main() {

	for (int i = 0; i < 10; i++) {
		ptrArr[i] = arr + i;
	}
	int count = 0;
	for (int i = 0; i < 9; i++) {
		int min = *ptrArr[i];
		int index = i;
		const int *ptr;
		for (int j = i + 1; j < 10; j++) {
			if (*ptrArr[j] < min) {
				min = *ptrArr[j];
				index = j;
			}
			count++;
		}
		ptr = ptrArr[index];
		ptrArr[index] = ptrArr[i];
		ptrArr[i] = ptr;
		cout << *ptrArr[i];
	}
	cout << *ptrArr[9];
	cout << endl << count;
	return 0;
}
