////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223-100 Fall 2020
//
//  Type of Assignment:     Final Programming
//  Author:                 Jeff Henry
//  File Name:              question6.cpp
//
//  Purpose of Program: Double array capacity function
//    Write a function that returns a pointer to a new int array that is double
//    the size of the array passed in the parameters to this function.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int *double_capacity(const int *list, int size) {
	int *newArr = new int(size*2);
	for (int i = 0; i < size; i++)
		newArr[i] = list[i];
	return newArr;
}

int main() {
	cout << "~~ Jefferson Henry - Final Programming - Question 6 ~~\n\n";

	// Get the starting size of the array
	int arrSize;
	cout << "Enter the size of the array: ";
	cin >> arrSize;
	int *arr = new int(arrSize);

	// Get starting values from the user
	int userInput;
	cout << "Enter " << arrSize << " int values: ";
	for (int i = 0; i < arrSize; i++) {
		cin >> userInput;
		arr[i] = userInput;
	}

	// Create larger array
	int newArrSize = arrSize*2;
	int *largerArr = double_capacity(arr, arrSize);
	delete[] arr;

	// Get more values from the user
	cout << "Enter " << arrSize << " more int values: ";
	for (int i = 0; i < arrSize; i++) {
		cin >> userInput;
		largerArr[arrSize+i] = userInput;
	}

	// Display the larger array with the new values
	cout << "The elements in the array are: ";
	for (int i = 0; i < newArrSize; i++)
		cout << largerArr[i] << " ";
	cout << endl;
}
