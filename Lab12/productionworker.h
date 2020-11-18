////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              productionworker.h
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <string>
using namespace std;

namespace Lab12
{
    class ProductionWorker : public Employee
    {
    public:
        ProductionWorker();
        ProductionWorker(string theName, int theNumber, string theHireDate,
                int theShift, double theRate);

        // Accessor methods
        int getShift();
        double getRate();

        // Mutator methods
        void setShift(int theShift);
        void setRate(double theRate);

        // Prints info of the worker
        virtual void print();

    private:
        int shift;
        double rate;
    };
} //Lab12
#endif //PRODUCTIONWORKER_H