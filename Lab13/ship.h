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

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <iomanip>
#include <string>

namespace Lab13
{
    class Ship
    {
    public:
        Ship();
        Ship(string theName, string theYear);

        // Accessor methods for getting name and year
        string getName();
        string getYear();

        // Mutator methods for setting name and year 
        void setName(string newName);
        void setYear(string newYear);

        // Prints the ship info
        virtual void print();
    protected:
        string name;
        string year;

    };
} //Lab13
#endif //SHIP_H
