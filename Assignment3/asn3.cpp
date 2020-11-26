////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              asn3.cpp
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "doctor.h"
#include "patient.h"
#include "billing.h"
using namespace std;
using namespace Asn3;

//Function declaration
int main()
{
    // Output Identification
    system("CLS");
    cout << "Assignment 3 by Jeff Henry - Doctors\n\n";

    const int NUM_OF_PATIENTS = 2;
    vector<Billing*> bills;

    // Get users input
    for (int i = 0; i < NUM_OF_PATIENTS; i++) {
        Doctor docForPat;
        Doctor doc;
        Patient pat;
        double docRate;
        int hours;

        cout << "Enter the patient's name: ";
        cin >> pat;
        cout << "Enter primary physician's name and their rate: ";
        cin >> docForPat >> docRate;
        docForPat.setRate(docRate);
        pat.setDoc(docForPat);
        cout << "Enter a doctor's name and their hourly rate: ";
        cin >> doc >> docRate;
        doc.setRate(docRate);
        cout << "Enter amount of hours: ";
        cin >> hours;

        bills.push_back(new Billing(doc, pat, hours));
    }

    double total = 0;
    for (Billing* bill : bills) {
        cout << bill->getPatientName() << " owes: " << bill->getDue() << " Dollars." << endl;
        total += bill->getDue();
    }
    cout << "The total income from the billing records: " << total << " Dollars." << endl;

    cout << "\n\nEnd Program.\n";
    return 0;
}
