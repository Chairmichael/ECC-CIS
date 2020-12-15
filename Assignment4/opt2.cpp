////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 4
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              opt2.cpp
//
//  Purpose of Program:
//       Move Ratings
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// returns true if s is a positive integer, false otherwise
bool isPositiveInteger(string s) {
	for (char c : s)
		if (c < 48 || c > 57) return false;
	return true;
}

int main() {
	ifstream inputFile("ratings.txt");
	map< string, vector<int> > movieRatings;
	string line, prevMovie;
	while (getline(inputFile, line)) {
		// This decision tree will effectively ignore the first line if it
		// 	just specifies the amount of ratings in the file.
		// Also if there are multiple ratings under a title separated by
		//	newlines, the program will count them as ratings for that title.
		// New movie to record or add rating
		if (!isPositiveInteger(line)) {
			prevMovie = line;
			// if movie is not in the map
			if (movieRatings.find(line) == movieRatings.end()) {
				vector<int> v;
				movieRatings.insert(pair<string, vector<int> >(line, v));
			}
		}
		// Record new rating if the number is a rating
		else if (isPositiveInteger(line) && !movieRatings.empty()) {
			movieRatings[prevMovie].push_back(stoi(line));
		}
	}

	// get the length of the longest title for better formating
	int maxLength = 0;
	for (auto const& setEl : movieRatings)
		if (setEl.first.length() > maxLength) maxLength = setEl.first.length();

	cout.precision(1);
	cout << fixed;
	// print the average ratings for the movies
	cout << "Average ratings:" << endl;
	for (auto const& setEl : movieRatings) {
		int amount = setEl.second.size();
		cout << setw(maxLength) << setEl.first  << " | ";
		// Average the ratings from the vector
		double avg = 0;
		// If the title has ratings
		if (amount > 0) {
			for (int rating : setEl.second) avg += rating;
			avg /= amount;
			// Output the number of reviews and the average rating
			cout << amount << ((amount > 1) ? " reviews | " : " review  | ");
			cout << avg << "/5.0" << endl;
		}
		// If the title doesn't have ratings
		else {
			cout << "0 reviews" << endl;
		}
	}
}