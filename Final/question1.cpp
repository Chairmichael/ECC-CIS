////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223-100 Fall 2020
//
//  Type of Assignment:     Final Programming
//  Author:                 Jeff Henry
//  File Name:              question1.cpp
//
//  Purpose of Program: Dynamic array allocation
//    Write a function that dynamically allocates an array. Your program should
//    allow the user to enter the size of the dynamic array, then uses a loop to
//    initialize the array by random numbers between -100 to 100.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int RANGE = 100;

void randArrInit(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % (RANGE*2 + 1)) - RANGE;
	}
}

int main() {
	cout << "~~ Jefferson Henry - Final Programming - Question 1 ~~\n\n";

	srand(time(0));
	cout << "Enter the size of the dynamic array: ";
	int arrSize;
	cin >> arrSize;

	int *arr = new int(arrSize);
	randArrInit(arr, arrSize);

	cout << "Array with random numbers between -" << RANGE << " and " << RANGE << ":\n";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}
