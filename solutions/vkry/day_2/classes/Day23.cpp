/*
 * Day23.cpp
 *
 *  Created on: Feb 24, 2020
 *      Author: vkry
 */

#include "exercises.h"

using namespace std;

Day23::Day23() {
	// TODO Auto-generated constructor stub

}

Day23::~Day23() {
	// TODO Auto-generated destructor stub
}


void Day23::do23(){

    const int arr[10] = {1, 9, 8, 6, 7, 2, 4, 5, 3};
    const int* ptrArr[10];

    for (int i = 0; i < 9; i++){
    	int min = INT32_MAX;
    	const int *minPtr = &min;

    	for (int j = 0; j < 9; j++){
    		if (arr[j] < *minPtr) {
    			bool minExists = false;

    			for (int z = i; z >= 0; z--) {
    				if (ptrArr[z] == &arr[j]) {
    					minExists = true;
    					break;
    				}
    			}

    			if (minExists == false) {
    				minPtr = &arr[j];
    			}
    		}
    	}
    	ptrArr[i] = minPtr;
    }

    cout << "unsorted array of ints (<pointer> <value>):" << endl;
    for (int i = 0; i < 9; i++) {

    	cout << &arr[i] << " " << arr[i] << "  ";
    }

    cout << endl;

    cout << "sorted array of pointers (<pointer> <value>):" << endl;
    for (int i = 0; i < 9; i++) {

    	cout << ptrArr[i] << " " << *ptrArr[i] << "  ";
    }

    cout << endl;
}
