////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              money.cpp
//
//  Purpose of Program:
//       Money Class
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "money.h"
using namespace std;

namespace Lab8 {

	Money::Money(long dollars, int cents) {
		allCents = dollars*100 + cents;
	}
	Money::Money(long dollars) {
		allCents = dollars*100;
	}

	double Money::getValue() const {
		return allCents / 100.0;
	}


	bool operator <(const Money& amount1, const Money& amount2) {
		return amount1.allCents < amount2.allCents;
	}
	bool operator <=(const Money& amount1, const Money& amount2) {
		return amount1.allCents <= amount2.allCents;
	}
	bool operator >(const Money& amount1, const Money& amount2) {
		return amount1.allCents > amount2.allCents;
	}
	bool operator >=(const Money& amount1, const Money& amount2) {
		return amount1.allCents >= amount2.allCents;
	}
	bool operator ==(const Money& amount1, const Money& amount2) {
		return amount1.allCents == amount2.allCents;
	}


	Money operator +(const Money& amount1, const Money& amount2) {
		long newCents = amount1.allCents + amount2.allCents;
		Money sum(newCents/100, newCents%100);
		return sum;
	}
	Money operator -(const Money& amount1, const Money& amount2) {
		long newCents = amount1.allCents - amount2.allCents;
		Money diff(newCents/100, newCents%100);
		return diff;
	}


	//Uses iostream, cctype, cstdlib:
	istream& operator >>(istream& ins, Money& amount) {
		char oneChar, decimalPoint,
			 digit1, digit2; //digits for the amount of cents
		long dollars;
		int cents;
		bool negative;//set to true if input is negative.

		ins >> oneChar;
		if (oneChar == '-')
		{
			negative = true;
			ins >> oneChar; //read '$'
		}
		else
			negative = false;
		//if input is legal, then oneChar == '$'

		ins >> dollars >> decimalPoint >> digit1 >> digit2;

		if ( oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2) ) {
			cout << "Error illegal form for money input\n";
			exit(1);
		}

		cents = digitToInt(digit1)*10 + digitToInt(digit2);

		amount.allCents = dollars*100 + cents;
		if (negative)
			amount.allCents = -amount.allCents;

		return ins;
	}
	//Uses cstdlib and iostream:
	ostream& operator <<(ostream& outs, const Money& amount) {
		long positiveCents, dollars, cents;
		positiveCents = labs(amount.allCents);
		dollars = positiveCents/100;
		cents = positiveCents%100;

		if (amount.allCents < 0)
			outs << "-$" << dollars << '.';
		else
			outs << "$" << dollars << '.';

		if (cents < 10)
			outs << '0';
		outs << cents;

		return outs;
	}

	int digitToInt(char c) {
		return ( static_cast<int>(c) - static_cast<int>('0') );
	}
} //Lab8
