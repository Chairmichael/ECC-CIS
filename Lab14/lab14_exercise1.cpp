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
    CheckedArray a;
    a[2] = 2;
    cout << a << endl;
}
