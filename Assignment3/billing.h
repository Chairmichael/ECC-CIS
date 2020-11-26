////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              billing.h
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#ifndef BILLING_H
#define BILLING_H

#include <string>
#include "doctor.h"
#include "patient.h"
using namespace std;

namespace Asn3
{
    class Billing {
    private: 
        Doctor doc; // The doctor
        Patient pat; // The doctor's patient
        double due; // amount of money due
    public:
        // Default constructor
        Billing();
        // Builds a bill from a specific Doctor, Patient and some hours
        Billing(Doctor& d, Patient& pt, int hours);

        // Gets the amount due on the bill
        double getDue();
        // Gets the Doctor's name (first, then last)
        string getDocName() const;
        // Gets the Patient's name (first, then last)
        string getPatientName() const;
    };
} //Asn3
#endif //BILLING_H
