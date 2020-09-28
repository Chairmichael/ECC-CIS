////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 5
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Sept.27, 2020
//  File Name:              lab5_exercise1.cpp
//
//  Purpose of Program:
//       This program demonstrates the vector's empty member function.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

// Function prototype
double avgVector(vector<int>);

int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 5 Exercise #1 by Jeff Henry - " << "Vectors\n\n";

    vector<int> values;    // A vector to hold values
    int numValues;       // The number of values
    double average;      // To hold the average

    // Get the number of values to averge.
    cout << "How many values do you wish to average? ";
    cin >> numValues;
    values.resize(numValues);

    // Get the values and store them in the vector.
    cout << "Provide value and then enter:" << endl;
    for (int count = 0; count < numValues; count++) {
        cin >> values[count];
    }

    // Get the average of the values and display it.
    average = avgVector(values);
    cout << "Average: " << average << endl;
    return 0;
}

//*************************************************************
// Definition of function avgVector.                          *
// This function accepts an int vector as its argument. If    *
// the vector contains values, the function returns the       *
// average of those values. Otherwise, an error message is    *
// displayed and the function returns 0.0.                    *
//*************************************************************

double avgVector(vector<int> vect)
{
    double total = 0;    // accumulator
    double avg;       // average

    // Determine if the vector is empty
    if (vect.size() == 0) {
        return 0;
    }
    else {
        for (int i = 0; i < vect.size(); i++) {
            total += vect[i];
        }
        avg = total / vect.size();
    }
    return avg;
}