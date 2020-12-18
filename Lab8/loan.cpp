////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              loan.cpp
//
//  Purpose of Program:
//       ID and Loan Classes
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "loan.h"
#include "id.h"
using namespace std;

namespace Lab8
{
	Loan::Loan( ) {
	}
	Loan::Loan(ID newID, float am, float rt, int trm) {
		id = newID;
		amount = am;
		rate = rt;
		term = trm;
	}

	void Loan::set( )  {
		int l, m, r;
		ID temp_id;
		// Initialize the loan1 object
		cout << "Enter the left part of the loan ID \n";
		cin >> l;
		cout << "Enter the middle part of the loan ID \n";
		cin >> m;
		cout << "Enter the right part of the loan ID \n";
		cin >> r;
		id = ID(l, m, r);
		cout << "Enter the amount of this loan \n";
		cin >> amount;
		cout << "Enter the annual interest rate of this loan (in %) \n";
		cin >> rate;
		cout << "Enter the term (number of months, length of the loan) \n";
		cin >> term;
	}
	void Loan::display() {
		id.display();
		cout << amount << endl;
		cout << rate << endl;
		cout << term << endl;
	}
} //Lab8
