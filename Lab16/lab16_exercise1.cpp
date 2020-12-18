////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 16
//  Author:                 Jeff Henry
//  File Name:              lab16_exercise1.cpp
//
//  Purpose of Program:
//       Random shuffle
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cout << " ~~ Jefferson Henry - Lab 16 ~~ \n\n";

	vector<char> myVect;
	for (char c = 'a'; c<'a'+10; c++)
		myVect.push_back(c);

	cout << "Vector has 10 elements: " << endl;
	for (char c : myVect) cout << c; // Print vector
	cout << endl;

	srand(time(0)); // Set seed so shuffle will be different each time
	random_shuffle(myVect.begin(), myVect.end()); // Shuffle vector

	cout << "Vector has been shuffled:" << endl;
	for (char c : myVect) cout << c; // Print vector
	cout << endl;

	sort(myVect.begin(), myVect.end(), less<char>());

	cout << "Vector has been sorted:" << endl;
	for (char c : myVect) cout << c; // Print vector
	cout << endl;

	cout << "Enter a charactor to search for in the vector: ";
	char target;
	cin >> target;
	if (binary_search(myVect.begin(), myVect.end(), target))
		cout << target << " is in the vector." << endl;
	else
		cout << target << " is NOT in the vector!" << endl;

	return 0;
}
