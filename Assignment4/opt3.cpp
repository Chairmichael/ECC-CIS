////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 4
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              opt3.cpp
//
//  Purpose of Program:
//       String Permutations
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

void printStrPerm(string s, int begin, int end) {
	if (begin == end - 1) {
		cout << s << endl;
		return;
	}
	for (int i = begin; i < end; i++) {
		// start swap forward
		swap(s[begin], s[i]);
		printStrPerm(s, begin + 1, end);
		// swap back
		swap(s[begin], s[i]);
	}
}

int main() {
	string theStr = "abc";
	printStrPerm(theStr, 0, theStr.length());
	return 0;
}
