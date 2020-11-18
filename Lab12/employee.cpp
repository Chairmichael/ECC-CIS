////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              employee.cpp
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <iomanip>
#include "employee.h"
using namespace std;

namespace Lab12
{
    Employee::Employee() : name(""), number(0), hireDate("")
    {}
    Employee::Employee(string theName, int theNumber, string theHireDate)
            : name(theName), number(theNumber), hireDate(theHireDate)
    {}

    // Accessor methods
    string Employee::getName() { return name; }
    int Employee::getNumber() { return number; }
    string Employee::getHireDate() { return hireDate; }

    // Mutator methods
    void Employee::setName(string newName) { name = newName; }
    void Employee::setNumber(int newNumber) { number = newNumber; }
    void Employee::setHireDate(string newHireDate) { hireDate = newHireDate; }

    // Prints info about the employee
    void Employee::print() {
        cout << "Employee Name: " << name << endl;
        cout << "Number:        " << number << endl;
        cout << "Hire date:     " << hireDate << endl;
    }
} //Lab12
