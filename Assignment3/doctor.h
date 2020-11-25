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
	Doctor();
	Doctor(const Person& pr, double);
	Doctor(const Doctor& dr);
	
	void setRate(double r);
	double getRate() const;

	virtual void operator =(const Doctor& pr);
};
} //Asn3
#endif //DOCTOR_H