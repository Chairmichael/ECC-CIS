////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 8
//  Author:                 Jeff Henry
//  File Name:              id.h
//
//  Purpose of Program:
//       ID and Loan Classes
////////////////////////////////////////////////////////////////////////////////

#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

namespace Lab8
{
	class ID {
	public:
		ID( );
		ID(int, int, int);
		void display();
	private:
		int left;
		int middle;
		int right;
	};

} //Lab8
#endif //ID_H
