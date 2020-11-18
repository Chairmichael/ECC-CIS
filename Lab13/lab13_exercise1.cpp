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
#include <string>
#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"

using namespace std;
using namespace Lab13;

int main() {
    const int ARR_LENGTH = 3;
    Ship* shipArr[ARR_LENGTH] = {
        new Ship("Boaty McBoatface", "10/10/2011"),
        new CruiseShip("People Mover", "5/3/2001", 12000),
        new CargoShip("Things Mover", "6/29/1991", 78000)
    };
    for (int i = 0; i < ARR_LENGTH; i++) {
        shipArr[i]->print();
        cout << endl;
    }
    return 0;
}