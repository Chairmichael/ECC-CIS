////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              productionworker.cpp
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include "productionworker.h"
using namespace std;

namespace Lab12
{
    ProductionWorker::ProductionWorker() : Employee(), shift(0), rate(0)
    {}
    ProductionWorker::ProductionWorker(string theName, int theNumber, 
            string theHireDate, int theShift, double theRate) 
            : Employee(theName, theNumber, theHireDate) {
        shift = theShift, rate = theRate;
    }

    // Accessor methods
    int ProductionWorker::getShift() { return shift; }
    double ProductionWorker::getRate() { return rate; }

    // Mutator methods
    void ProductionWorker::setShift(int theShift) { shift = theShift; }
    void ProductionWorker::setRate(double theRate) { rate = theRate; }

    // Prints info of the worker
    void ProductionWorker::print() {
        Employee::print();
        if (shift == 1) cout << "Shift:    Day" << endl;
        else if (shift == 2) cout << "Shift:    Night" << endl;
        else cout << "Shift:    " << shift << endl;
        cout << "Pay rate: " << fixed << setprecision(2) << rate << endl;
    }
} //Lab12
