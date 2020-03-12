// exercise_2_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


void swapElements(int * firstElement,int * secondElement) {
	int tempElement = *firstElement;
	*firstElement = *secondElement;
	*secondElement = tempElement;
}

int divide(const int * arrayToDivide[], int startIndex, int endIndex) {
	int mainElement = *arrayToDivide[endIndex];
	int smallerElementIndex = (startIndex - 1);

	for (int index = startIndex; index <= endIndex - 1; index++)
	{
		if (*arrayToDivide[index] < mainElement) {
			 smallerElementIndex++;
			swapElements(const_cast <int *>(arrayToDivide[smallerElementIndex]), const_cast<int *>(arrayToDivide[index]));
		}
	}
	swapElements(const_cast <int *>(arrayToDivide[smallerElementIndex + 1]), const_cast<int *>(arrayToDivide[endIndex]));
	return (smallerElementIndex + 1);
}

void performQuickSort(const int * arrayToSort[], int startIndex, int endIndex) {
	if (startIndex < endIndex) {
		int divisionIndex = divide(arrayToSort, startIndex, endIndex);

		performQuickSort(arrayToSort, startIndex, divisionIndex - 1);
		performQuickSort(arrayToSort, divisionIndex + 1, endIndex);
	}
}


int main()
{
      const int constArray[10]{ 1, 9, 8, 6, 7, 2, 4, 5, 3}; // last element  0...
      const int* pointerArray[10];

	for (int index = (sizeof(constArray)/sizeof(constArray[0])) - 1; index >= 0; index--)
	{
		pointerArray[index] = constArray + index;

		std::cout <<"ptrArr["<<index<<"]"<< "\tAddress:"<< pointerArray[index] << "\tValue:" << *pointerArray[index] << std::endl;
	}

	// Performing Quick Sort
	performQuickSort(pointerArray, 0, 9);


	std::cout << "Sorted array: " << std::endl;

	for (int index = 9; index >= 0; index--) {
		std::cout << "ptrArr[" << index << "]" << "\tAddress:" << pointerArray[index] << "\tValue" << *pointerArray[index] << std::endl;
	}

}


