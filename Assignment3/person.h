////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              person.h
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#ifndef PERSON_H
#define PERSON_H


#include <string>
#include <iostream>
using namespace std;

namespace Asn3 
{
class Person {
private:
	string first;
	string last;
public:
	Person();
	Person(string fn, string ln);
	Person(const Person& original);

	void setFirst(string fn);
	void setLast(string ln);
	string getFirst() const;
	string getLast() const;

	bool operator ==(const Person& pr);
	virtual void operator =(const Person& pr); // copy

	friend istream& operator >>(istream& is, Person& pr);
	friend ostream& operator <<(ostream& os, const Person& pr);
};
} //Asn3
#endif //PERSON_H