////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              teamleader.cpp
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include "productionworker.h"
#include "teamleader.h"
using namespace std;

namespace Lab12
{
    TeamLeader::TeamLeader() : ProductionWorker(), monthlyBonus(0), yearlyTraining(0)
    {}

    TeamLeader::TeamLeader(string theName, int theNumber, string theHireDate, 
        int theShift, double theRate, double theMnBns, double theTraining)
        : ProductionWorker(theName, theNumber, theHireDate, theShift, theRate)
    {
        monthlyBonus = theMnBns, yearlyTraining = theTraining;
    }

    // Accessor methods
    double TeamLeader::getMonthlyBonus() { return monthlyBonus; }
    double TeamLeader::getTraining() { return yearlyTraining; }

    // Mutator methods
    void TeamLeader::setMonthlyBonus(double newMnBns) {
        monthlyBonus = newMnBns;
    }
    void TeamLeader::setTraining(double newTraining) {
        yearlyTraining = newTraining;
    }

    // Prints info of the teamleader
    void TeamLeader::print() {
        ProductionWorker::print();
        cout << "Monthly bonus: " << monthlyBonus << endl;
        cout << "Yearly training hours : " << yearlyTraining << endl;
    }
}