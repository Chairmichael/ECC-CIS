////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 9
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              lab9_exercise1.cpp
//
//  Purpose of Program:
//       Overloading input and output operators
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>

using namespace std;

enum coin_type {nickel, dime, quarter};

int main( )
{
    // Output Identification
    system("CLS");
    cout << "Lab 9 Exercise #1 by Jeff Henry - "
        << "Enumerated Data Types\n\n";

    coin_type coin;
    int holdings[3] = {3, 6, 2};
    int total = 0;

    // coin++ will not work because the enum is not of type int
    for (coin = nickel; coin <= quarter; coin = static_cast<coin_type>(coin + 1)) {
        switch (coin) {
            case nickel:
                total = total + (5 * holdings[coin]);  
                break;
            case dime:
                total = total + (10 * holdings[coin]);
                break;
            case quarter:
                total = total + (25 * holdings[coin]);
                break;
        }
    }

    cout << "Total holdings are " << total << " cents.\n";


    cout << "\n\nEnd Program.\n";
    return 0;
} 
