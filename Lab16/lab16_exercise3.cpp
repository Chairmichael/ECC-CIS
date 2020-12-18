////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 16
//  Author:                 Jeff Henry
//  File Name:              lab16_exercise3.cpp
//
//  Purpose of Program:
//       STL String Set
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


int main() {
	const int MAX1 = 4, MAX2 = 3;
	set<string> strSet1;
	set<string> strSet2;
	cout << "Enter " << MAX1 << " strings seperated by whitespace:" << endl;
	string userInput;
	for (int i = 0; i < MAX1; i++) {
		cin >> userInput;
		strSet1.insert(userInput);
	}
	cout << "Enter " << MAX2 << " strings seperated by whitespace:" << endl;
	for (int i = 0; i < MAX2; i++) {
		cin >> userInput;
		strSet2.insert(userInput);
	}

	cout << "You first you entered: ";
	for (auto x : strSet1) {
		cout << x << " ";
	}
	cout << endl;

	cout << "You second you entered: ";
	for (auto x : strSet2) {
		cout << x << " ";
	}
	cout << endl;

	cout << endl << "The intersection of the sets is: " << endl;
	set<string> resultSet;
	set_intersection(strSet1.begin(), strSet1.end(),
					 strSet2.begin(), strSet2.end(),
					 inserter(resultSet, resultSet.begin()) );
	for (auto s : resultSet) {
		cout << s << " ";
	}
	cout << endl;

	return 0;
}
