////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              money.h
//
//  Purpose of Program:
//       Money Class
////////////////////////////////////////////////////////////////////////////////

#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

namespace Lab8 {
	class Money {
	public:
		Money(long dollars, int cents);
		Money(long dollars);
		Money( ) : allCents(0) { }

		friend Money operator +(const Money& amount1, const Money& amount2);
		friend Money operator -(const Money& amount1, const Money& amount2);
		friend bool operator ==(const Money& amount1, const Money& amount2);

		friend bool operator <(const Money& amount1, const Money& amount2);
		friend bool operator <=(const Money& amount1, const Money& amount2);
		friend bool operator >(const Money& amount1, const Money& amount2);
		friend bool operator >=(const Money& amount1, const Money& amount2);

		double getValue( ) const;

		friend istream& operator >>(istream& ins, Money& amount);
		//Overloads the >> operator so it can be used to input values of type Money.
		//Notation for inputting negative amounts is as in -$100.00.
		//Precondition: If ins is a file input stream, then ins has already been
		//connected to a file.

		friend ostream& operator <<(ostream& outs, const Money& amount);
		//Overloads the << operator so it can be used to output values of type Money.
		//Precedes each output value of type Money with a dollar sign.
		//Precondition: If outs is a file output stream,
		//then outs has already been connected to a file.
	private:
		long allCents;
	}; //Money

	int digitToInt(char c);
	//Used in the definition of the overloaded input operator >>.
	//Precondition: c is one of the digits '0' through '9'.
	//Returns the integer for the digit; for example, digitToInt('3') returns 3.

} //Lab8
#endif //MONEY_H
