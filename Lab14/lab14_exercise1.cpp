////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 14
//  Author:                 Jeff Henry
//  File Name:              lab14_exercise1.cpp
//
//  Purpose of Program:
//       Range checking arrary
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "checkedarray.h"
using namespace std;
using namespace Lab14;

int main() {
    cout << " ~~ Jeff Henry - Lab 14 ~~\n\n";
	try {
	    CheckedArray a;
	    a[2] = 2;
	    cout << a << endl;
	    a[5] = -5;
	    cout << a << endl;
	    a[10] = 88;
	    cout << a << endl;
    }
    catch (ArrayOutOfRangeError& e) {
    	cout << "ArrayOutOfRangeError" << endl;
    }
    const int ARR_LEN = 11;
    int arr[ARR_LEN] = {-1, 4, 5, 7, -11, 18, 19, -22, 24, 33, -51};
    try {
    	CheckedArray a(arr, ARR_LEN);
    	cout << a << endl;
    	a[10] = -52;
    	a[-202] = 89;
    }
    catch (ArrayOutOfRangeError& e) {
    	cout << "ArrayOutOfRangeError" << endl;
    }
}
