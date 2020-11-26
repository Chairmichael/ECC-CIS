////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              doctor.cpp
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "doctor.h"
using namespace std;

namespace Asn3
{
	// Defualt constructor calls the person defualt constructor and sets the rate to 0
	Doctor::Doctor() : Person(), rate(0) { }
	// Takes the person obect and a specific rate
	Doctor::Doctor(const Person& pr, double r) : Person(pr), rate(r)  { }
	// Copy constructor
	Doctor::Doctor(const Doctor& dr)
		: Person(dr.getFirst(), dr.getLast()), rate(dr.getRate()) { }
	
	// Getter and setter functions
	void Doctor::setRate(double r) { rate = r; }
	double Doctor::getRate() const { return rate; }

	// Reassigns the Person member values and the sets the rate
	void Doctor::operator =(const Doctor& dr) {
		Person::operator=(dr);
		rate = dr.getRate();
	}
} //Asn3
