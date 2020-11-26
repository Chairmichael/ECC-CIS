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
    Billing::Billing(Doctor& d, Patient& pt, int hours) {
        doc = d, pat = pt, due = hours;
        if (pat.getDoc() == doc) { // Doc is the patients primary doctor
            due = hours * doc.getRate();
        }
        else { // Doc is not the patients primary doctor
            due = hours * doc.getRate() * NONPRIMARY_DOC;
        }
    }

    double Billing::getDue() { return due; }
    string Billing::getDocName() const {
        return doc.getFirst() + " " + doc.getLast();
    }
    string Billing::getPatientName() const {
        return pat.getFirst() + " " + pat.getLast();
    }
}
