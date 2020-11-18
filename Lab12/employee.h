////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              employee.h
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

namespace Lab12
{
    class Employee
    {
    public:
        Employee();
        Employee(string theName, int theNumber, string theHireDate);

        // Accessor methods
        string getName();
        int getNumber();
        string getHireDate();

        // Mutator methods
        void setName(string newName);
        void setNumber(int newNumber);
        void setHireDate(string newHireDate);

        // Prints info about the employee
        virtual void print();
        
    private:
        string name;
        int number;
        string hireDate;
    };
} //Lab12
#endif //EMPLOYEE_H