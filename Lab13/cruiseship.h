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

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ship.h>
#include <cruiseship.h>

namespace Lab13
{
    class CruiseShip : public Ship
    {
    public:
        CruiseShip();
        CruiseShip(string theName, string theYear, int theMax);

        // Accessor method for maximum passengers
        int getMaxPas();

        // Mutator method for setting the maximum passengers
        void setMaxPas(int newMax);

        // Prints the info of the cruiseship
        virtual void print();
    protected:
        int maxPas; // Maximum passengers
    };
} //Lab13
#endif //CRUISESHIP_H