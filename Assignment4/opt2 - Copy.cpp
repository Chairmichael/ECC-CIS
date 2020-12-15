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
#include <cmath>
#include <map>

using namespace std;

struct Rating {
	int totalRating{0};
	int numOfRatings{0};
};

// returns true if s is a positive integer, false otherwise
bool isNumber(string s) {
	for (char c : s)
		if (c < 48 || c > 57) return false;
	return true;
}

int main() {
	ifstream inputFile("ratings.txt");
	map<string, Rating> movieRatings;
	string line, prevMovie;
	while (getline(inputFile, line)) {
		// New movie to record or add rating
		if (!isNumber(line)) {
			prevMovie = line;
			// if movie is not in the map
			if (movieRatings.find(line) == movieRatings.end()) {
				Rating r;
				// Rating r* = new Rating;
				movieRatings.insert(pair<string, Rating>(line, r));
			}
		}
		// Record new rating if the number is a rating
		else if (isNumber(line) && !movieRatings.empty()) {
			movieRatings[prevMovie].totalRating += stoi(line);
			// cout << prevMovie << endl;
			movieRatings[prevMovie].numOfRatings += 1;
		}
	}
	// get the length of the longest title for better formating
	int maxLength = 0;
	for (auto const& x : movieRatings)
		if (x.first.length() > maxLength) maxLength = x.first.length();
	// print the average ratings for the movies
	cout << "Average ratings:" << endl;
	cout.precision(1);
	cout << fixed;
	for (auto const& x : movieRatings) {
		// cout << setw(maxLength) << x.first << " | " << x.second.totalRating << " - " << x.second.numOfRatings << endl;
		cout << setw(maxLength) << x.first  << " | ";
		double avg = (double) x.second.totalRating / (double) x.second.numOfRatings;
		cout << avg << "/5.0" << endl;
	}
}