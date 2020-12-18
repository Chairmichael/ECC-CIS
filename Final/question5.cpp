////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223-100 Fall 2020
//
//  Type of Assignment:     Final Programming
//  Author:                 Jeff Henry
//  File Name:              question5.cpp
//
//  Purpose of Program: Recursive string reverse method
//    Write a recursive method to reverse a string. Explain why you would
//    not normally use recursion to solve this problem.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int getSquareRoot(int n) {
	for (int i = 1; i < sqrt(n)+1; i++) {
		if (i*i == n)
			return i;
	}
	throw n;
}

int main() {
	cout << "~~ Jefferson Henry - Final Programming - Question 5 ~~\n\n";
	try {
		cout << "getSquareRoot(36) = " << getSquareRoot(36) << endl;
		cout << "getSquareRoot(66) = " << getSquareRoot(66) << endl;
	}
	catch (int e) {
		cout << e << " is not a perfect square." << endl;
	}
}
