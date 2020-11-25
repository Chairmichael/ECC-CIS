////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              patient.h
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include "person.h"
#include "doctor.h"
using namespace std;

namespace Asn3
{
class Patient : public Person {
private:
	Doctor doc;
public:
	Patient();
	Patient(const Person& pr, const Doctor& dr);
	Patient(const Patient& pt);

	void setDoc(const Doctor& dr);
	Doctor& getDoc();
	
};
} //Ans3
#endif //PATIENT_H
