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


#include "billing.h"
#include "doctor.h"
#include "patient.h"

namespace Asn3
{
    const double NONPRIMARY_DOC = 1.25;

    // The default constructor
    Billing::Billing() {
        Doctor d;
        doc = d;
        Patient pt;
        pat = pt;
        due = 0;
    }
    // Takes a doctor, patient and an amount of hours and the total amount due is calculated
    Billing::Billing(Doctor& d, Patient& pt, int hours) {
        doc = d, pat = pt, due = hours;
        if (pat.getDoc() == doc) { // Doc is the patients primary doctor
            // No additional factor when its the primary doctor
            due = hours * doc.getRate();
        }
        else { // Doc is not the patients primary doctor
            // And additional factor is multiplied in when theres a different doctor
            due = hours * doc.getRate() * NONPRIMARY_DOC;
        }
    }

    // Returns the amount due on the bill
    double Billing::getDue() { return due; }
    // Combines the first and last name of the doctor and returns it
    string Billing::getDocName() const {
        return doc.getFirst() + " " + doc.getLast();
    }
    // Combines the first and last name of the patient and returns it
    string Billing::getPatientName() const {
        return pat.getFirst() + " " + pat.getLast();
    }
}
