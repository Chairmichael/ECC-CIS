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
	Doctor::Doctor() : Person(), rate(0) { }
	Doctor::Doctor(const Person& pr, double r) : Person(pr), rate(r)  { }
	Doctor::Doctor(const Doctor& dr)
		: Person(dr.getFirst(), dr.getLast()), rate(dr.getRate()) { }
	
	void Doctor::setRate(double r) { rate = r; }
	double Doctor::getRate() const { return rate; }

	void Doctor::operator =(const Doctor& dr) {
		Person::operator=(dr);
		rate = dr.getRate();
	}
} //Asn3