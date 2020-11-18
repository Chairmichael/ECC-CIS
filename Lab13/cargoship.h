////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 13
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              cargoship.h
//
//  Purpose of Program:
//       Polymorphism and Virtual Functions
////////////////////////////////////////////////////////////////////////////////

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <string>
#include "ship.h"
using namespace std;

namespace Lab13
{
	class CargoShip : public Ship
	{
	public:
		CargoShip();
		CargoShip(string theName, string theYear, int theMax);
		
		// Gets the maximum cargo tonnage
		int getMaxTons();

		// Sets the maximum cargo tonnage
		void setMaxTons(int newMax);

		// Prints the info of the cargoship
        virtual void print();

	protected:
		int maxTons;
	};
} //Lab13
#endif //CARGOSHIP_H