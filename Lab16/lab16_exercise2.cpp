////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 16
//  Author:                 Jeff Henry
//  File Name:              lab16_exercise2.cpp
//
//  Purpose of Program:
//       Histogram
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int> hist;
	int userInput;
	bool done = false;
	cout << "Enter positive integers. Enter -1 or less to stop." << endl;
	while (!done) {
		cin >> userInput;
		if (userInput <= -1)
			done = true;
		else
			hist[userInput]++;
	}
	// Display the count of each integer
	for (auto it : hist) {
		cout << "Number " << it.first;
		cout << " has been seen " << it.second << " times." << endl;
	}
}
