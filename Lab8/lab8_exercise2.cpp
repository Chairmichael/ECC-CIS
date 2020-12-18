////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              lab8_exercise2.cpp
//
//  Purpose of Program:
//       ID and Loan Classes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "id.h"
#include "loan.h"

using namespace std;
using namespace Lab8;

int main( ) {
	Loan loan1(ID(111,22,4444), 2300, 5.5, 48);  // initialize to values given
	Loan loan2;

	cout << "Display loan1 \n";
	loan1.display();

	loan2.set( ); // set the values
	cout << "Display loan2 \n";
	loan2.display();

	return 0;
}
