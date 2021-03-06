////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              patient.cpp
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "patient.h"
using namespace std;

namespace Asn3
{
    // Default constructor, sets person to default and keeps the doctor unassigned
	Patient::Patient() : Person() { }
    // Takes a specic person and doctor object
	Patient::Patient(const Person& pr, const Doctor& dr) 
		: Person(pr), doc(dr) { }
    // Copy constructor
	Patient::Patient(Patient& pt)
		: Person(pt.getFirst(), pt.getLast()) { doc = pt.getDoc(); }

    // Getter and setter functions
	void Patient::setDoc(const Doctor& dr) { doc = dr; }
	Doctor& Patient::getDoc() { return doc; }
}
