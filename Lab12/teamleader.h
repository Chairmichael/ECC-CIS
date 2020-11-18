////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              teamleader.h
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <string>
#include "productionworker.h"
using namespace std;

namespace Lab12
{
    class TeamLeader : public ProductionWorker
    {
    public:
        TeamLeader();
        TeamLeader(string theName, int theNumber, string theHireDate,
            int theShift, double theRate, double theMnBns, double theTraining);

        // Accessor methods
        double getMonthlyBonus();
        double getTraining();

        // Mutator methods
        void setMonthlyBonus(double newMnBns);
        void setTraining(double newTraining);

        // Prints info of the teamleader
        virtual void print();

    private:
        double monthlyBonus; // Monthly pay bonus for teamleader
        double yearlyTraining; // Required hours of yearly training
    };
} //Lab12
#endif //TEAMLEADER_H