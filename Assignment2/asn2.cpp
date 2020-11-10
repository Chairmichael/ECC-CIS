////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 2
//  Author:                 Jeff Henry
//  File Name:              asn2.cpp
//
//  Purpose of Program:
//       Assignment 2
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
using namespace std;
using namespace DMVqueue;

//Function declaration
 
 

int main()
{
    // Output Identification
    system("CLS");
    cout << "Assignment 2 by Jeff Henry - "
         << "DMV Queue\n\n";

    bool done = false;
    char userInput;
    int timeStamps = {0,0,0};
    int amountWaiting = 0;
    Queue waitingLine;

    while (!done) {
        if (waitingLine.empty()) {
            cout << "The line is empty."
                << "Enter '1' to simulate a customer's arrival "
                << "or anything else to quit: ";
        }
        else {
            cout << "Enter '1' to simulate a customer's arrival "
                << "'2' to simulate helping the next customer "
                << "or anything else to quit: ";
        }

        cin >> userInput;
        if (userInput == '1') {

        }
        else if (userInput == '2') {

        } 
        else {
            done = true;
        }
    }

    cout << "\n\nEnd Program.\n";
    return 0;
}

 