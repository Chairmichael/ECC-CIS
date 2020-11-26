////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              doctor.h
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
#include "person.h"
using namespace std;

namespace Asn3
{
class Doctor : public Person {
private:
	double rate; // Doctor's hourly rate

public:
    // Default constructor
	Doctor();
    // Takes a Person object for the name, and a double for the rate
	Doctor(const Person& pr, double);
    // Copy constructor
	Doctor(const Doctor& dr);
	
    // Getter and setter functions
	void setRate(double r);
	double getRate() const;

	virtual void operator =(const Doctor& pr);
};
} //Asn3
#endif //DOCTOR_H
