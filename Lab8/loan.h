////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              loan.h
//
//  Purpose of Program:
//       ID and Loan Classes
////////////////////////////////////////////////////////////////////////////////

#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include "id.h"
using namespace std;

namespace Lab8
{
	class Loan { // Loan is called structure tag
	public:
		Loan( );
		Loan(ID newID, float amount, float rate, int term);
		void set( );
		void display( );
	private:
		ID id;  // assume an unique integer between 1111-9999
		float amount; // $ amount of the loan
		float rate; // annual interest rate
		int term;  // number of months, length of the loan
	};

} //Lab8
#endif //LOAN_H
