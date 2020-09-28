////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 5
//  Problem Number:         2
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Sept.27, 2020
//  File Name:              lab5_exercise2.cpp
//
//  Purpose of Program:
//       This program demonstrates the vector member functions 
//       such as push_back, pop_back, clear, size. 
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

//Client section
int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 5 Exercise #2 by Jeff Henry - " << "Vector functions\n\n";

    vector<int> values;

    // Store values in the vector.
    values.push_back(3);
    values.push_back(38);
    values.push_back(423);

    cout << "The size of values is " << values.size() << endl;

    // Remove a value from the vector.
    cout << "Popping a value from the vector...\n";
    values.pop_back();
    cout << "The size of values is now " << values.size() << endl;

    // Now remove another value from the vector.
    cout << "Popping a value from the vector...\n";
    values.pop_back();
    cout << "The size of values is now " << values.size() << endl;

    // Remove the last value from the vector.
    cout << "Popping a value from the vector...\n";
    values.pop_back();
    cout << "The size of values is now " << values.size() << endl;

    // Store values in the vector.
    values.push_back(4);
    cout << "I will call the clear member function...\n";
    values.clear();
    cout << "Now, the values vector has "
        << values.size() << " elements.\n";

    return 0;
}
