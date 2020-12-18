////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              id.cpp
//
//  Purpose of Program:
//       ID and Loan Classes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "id.h"
using namespace std;

namespace Lab8
{
	ID::ID( ) {
	}
	ID::ID(int l, int r, int m) {
		left = l;
		right = r;
		middle = m;
	}
	void ID::display() {
		cout << left << "-" << middle << "-" << right << endl;
	}
} //Lab8
