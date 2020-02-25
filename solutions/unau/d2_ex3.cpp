#include <iostream>

using namespace std;
void main()
{
	const int arr[10]{ 1,9,8,6,7,2,4,5,3 };
	const int* ptrArr[10];

	for (int i = 0; i <= 9; i++) ptrArr[i] = &arr[i];
	for (int j = 1; j <= 9; j++) {
		for (int i = 0; i <= 10 - j - 1; i++) {
			if (*ptrArr[i] > * ptrArr[i + 1]) {
				const int* hold = ptrArr[i + 1];
				ptrArr[i + 1] = ptrArr[i];
				ptrArr[i] = hold;
			}
		}
	}
	for (int i = 0; i <= 9; i++) cout << *ptrArr[i] << " ";
}
