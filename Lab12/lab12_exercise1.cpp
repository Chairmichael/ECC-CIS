////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 12
//  Author:                 Jeff Henry
//  File Name:              lab12_exercise1.cpp
//
//  Purpose of Program:
//       Creating Derived Classes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "employee.h"
#include "productionworker.h"

using namespace std;
using namespace Lab12;

int main() {
	Employee worker1("Jake", 322, "10/10/2018");
	worker1.print();
	ProductionWorker worker2("Leif", 193, "7/8/2010", 2, 19.25);
	worker2.print();
	return 0;
}