////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 4
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              opt1.cpp
//
//  Purpose of Program:
//       Permutations
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <functional>

using namespace std;

const int LIST_SPACING = 5;
const int DEFUALT_MAX = 9;

// returns true if s is an integer, false otherwise
bool isInteger(string s) {
    bool first = true;
    for (char c : s) {
        if (first && s[0] == '-') 
        	first = false;
        else if (c < 48 || c > 57) 
        	return false;
    }
    return true;
}

// Get permutations on the vector and add them to the set
//  theSet - set to add permutations
//  vct - the vector to permute
set< vector<int> > getPermutations(vector<int> vct) {
    set< vector<int> > theSet;
    // Recursive lamda function for permutations
    function<void(vector<int>, int, int)>
    permute = [&](vector<int> v, int begin, int end) {
        if (begin == end - 1) {
            v.shrink_to_fit();
            theSet.insert(v);
            return;
        }
        for (int i = begin; i < end; i++) {
            // start swap forward
            swap(v[begin], v[i]);
            permute(v, begin + 1, end);
            // swap back
            swap(v[begin], v[i]);
        }
    };
    permute(vct, 0, vct.size());
    return theSet;
}

// Prints a vector with brackets around the elements
void printVector(vector<int> v) {
    cout << "{ ";
    for (int num : v)
        cout << num << " ";
    cout << "}" << endl;
}

// Prints out a set containing vectors
//  theSet - the set to print from
//  max - the max number of set elements to print, skips elements in the middle
//        if -1, prints whole set
void printSetVectors(set< vector<int> > theSet, int max = DEFUALT_MAX) {
    long int i = 0;
    bool firstSkip = true;
    for (vector<int> const& v: theSet) {
        if (max < 0 || max/2 > i || (theSet.size() - max/2) <= i) {
            cout << setw(LIST_SPACING + v.size()/2) << i+1 << ": ";
            printVector(v);
        }
        else if(firstSkip && max%2 != 0) {
            cout << setw(LIST_SPACING + v.size()/2) << i+1 << ": ";
            printVector(v);
            cout << setw(LIST_SPACING + v.size()/2) << " . . ." << endl;
            firstSkip = false;
        }
        else if(firstSkip) {
            cout << setw(LIST_SPACING + v.size()/2) << " . . ." << endl;
            firstSkip = false;
        }
        i++;
    }
}

// Prints the the permutations of 1 to n (inclusive)
void printPermutations(int n, int max = DEFUALT_MAX) {
    cout << "Permutations of ";
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    printVector(v);
    printSetVectors(getPermutations(v), max);
}

int main(int argc, char const *argv[]) {
    if (argc == 1) {
        cout << " ~~ Jefferson Henry - Assignment 4 ~~\n\n";
        printPermutations(4);
    }
    else if (argc == 2 && isInteger(string(argv[1]))) {
        printPermutations(atoi(argv[1]));
    }
    else if (argc == 3 && isInteger(string(argv[1])) && isInteger(string(argv[2]))) {
        printPermutations(atoi(argv[1]), atoi(argv[2]));
    }
    else {
        cout << "USAGE: *.exe n m" << endl;
        cout << "    n: Print all permutations of the first n whole numbers." << endl;
        cout << "    m: Max number of set elements to print. -1 to print all." << endl;
        cout << " Note: Values of n greater than 9 may not work as intended." << endl;
    }
    return 0;
}
