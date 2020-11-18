////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 13
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              cruiseship.cpp
//
//  Purpose of Program:
//       Polymorphism and Virtual Functions
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include "ship.h"
#include "cruiseship.h"

using namespace std;

namespace Lab13
{
    CruiseShip::CruiseShip() : Ship(), maxPas(0)
    {}
    CruiseShip::CruiseShip(string theName, string theYear, int newMax)
            : Ship(theName, theYear), maxPas(newMax)
    {}

    // Accessor method for maximum passengers
    int CruiseShip::getMaxPas() { return maxPas; }
    // Mutator method for setting the maximum passengers
    void CruiseShip::setMaxPas(int newMax) { maxPas = newMax; }

    // Prints the info of the cruiseship
    void CruiseShip::print() {
        Ship::print();
        cout << "Maximum passengers: " << maxPas << endl;
    }
} //Lab13
