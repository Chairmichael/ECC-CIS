////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              lab12_exercise2.cpp
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "teamleader.h"

using namespace std;
using namespace Lab12;

int main() {
    // string theName, int theNumber, string theHireDate,
    // int theShift, double theRate, double theMnBns, double theTraining
    TeamLeader leader1("Riley", 7001, "8/23/2003", 2, 21.05, 210, 120);
    leader1.print();
}
