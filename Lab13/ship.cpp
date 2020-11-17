////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 13
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              lab13_exercise1.cpp
//
//  Purpose of Program:
//       Polymorphism and Virtual Functions
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include "ship.h"

using namespace std;

namespace Lab13
{
    Ship::Ship() : name(""), year("")
    {}
    Ship::Ship(string theName, string theYear) : name(theName), year(theYear)
    {}

    // Accessor methods for getting name and year
    string Ship::getName() { return name; }
    string Ship::getYear() { return year; }
    // Mutator methods for setting name and year 
    void Ship::setName(string newName) { name = newName; }
    void Ship::setYear(string newYear) { year = newYear; }

    // Prints the ships name and year built
    void Ship::print() {
        cout << setw(20);
        cout << "Ship name: " << name << endl;
        cout << "Year built: " << year << endl;
    }
} //Lab13
