
#include <iostream>

using namespace std;

void putAndSort(const int* ptrArr[10], int pos, const int* ptr){
    const int* ptrBuf;
    ptrArr[pos] = ptr;
    while (pos > 0 && *ptrArr[pos] < *ptrArr[pos-1]){
        ptrBuf = ptrArr[pos-1];
        ptrArr[pos-1] = ptrArr[pos];
        ptrArr[pos] = ptrBuf;
        pos--;
    }
}

int main() {
    const int arr[10]
    {
        1, 9, 8, 6, 7, 2, 4, 5, 3
    };
    const int* ptrArr[10];

    int arrIdx = 0;
    do{
        putAndSort(ptrArr, arrIdx, &arr[arrIdx]);
    } while (++arrIdx < 10);




    cout << "arr[10] : ";
    for (int i = 0; i < 10; i++){
        cout << arr[i] << ' ';
    }
    cout << endl << "&arr[10] : ";
    for (int i = 0; i < 10; i++){
        cout << &arr[i] << ' ';
    }
    cout << endl << "ptrArr[10] : ";
    for (int i = 0; i < 10; i++){
        cout << ptrArr[i] << ' ';
    }
    cout << endl << "*ptrArr[10] : ";
    for (int i = 0; i < 10; i++){
        cout << *ptrArr[i] << ' ';
    }

	return 0;
}
