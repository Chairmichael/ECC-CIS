////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 13
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              cargoship.cpp
//
//  Purpose of Program:
//       Polymorphism and Virtual Functions
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include "ship.h"
#include "cargoship.h"

using namespace std;

namespace Lab13
{
    CargoShip::CargoShip() : Ship(), maxTons(0)
    {}
    CargoShip::CargoShip(string theName, string theYear, int newMax)
            : Ship(theName, theYear), maxTons(newMax)
    {}

    // Accessors method for maximum passengers
    int CargoShip::getMaxTons() { return maxTons; }
    // Mutator method for setting the maximum passengers
    void CargoShip::setMaxTons(int newMax) { maxTons = newMax; }

    // Prints the info of the CargoShip
    void CargoShip::print() {
        Ship::print();
        cout << "Maximum tonnage: " << maxTons << endl;
    }
} //Lab13
