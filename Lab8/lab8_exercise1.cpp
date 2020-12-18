////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              lab8_exercise1.cpp
//
//  Purpose of Program:
//       Money Class
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "money.h"
using namespace std;
using namespace Lab8;

int main() {
	cout << " ~~ Jeff Henry - Lab 8 ~~\n\n";

	Money m1(40);
	Money m2(20,88);
	cout << "m1 = " << m1 << endl;
	cout << "m2 = " << m2 << endl;
	cout << "m1 - m2 = " << m1-m2 << endl;
	cout << "m1 + m2 = " << m1+m2 << endl;
	if (m1 < m2) cout << "m1 < m2 = true" << endl;
	else cout << "m1 < m2 = false" << endl;

	return 0;
}
