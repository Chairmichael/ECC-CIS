////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 3
//  Author:                 Jeff Henry
//  File Name:              person.cpp
//
//  Purpose of Program:
//       Assignment 3
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "person.h"
using namespace std;

namespace Asn3 {
	// Default constructor
	Person::Person() : first(""), last("") { }
	// Creates a person from a specifc first and last name strings
	Person::Person(string fn, string ln) : first(fn), last(ln) { }
	// Copy constructor
	Person::Person(const Person& original)
		: first(original.getFirst()), last(original.getLast()) { }

	// Getter and setter functions
	void Person::setFirst(string fn) { first = fn; }
	void Person::setLast(string ln) { last = ln; }
	string Person::getFirst() const { return first; }
	string Person::getLast() const { return last; }

	// Compares the first and last names, if they're the same then returns true. False otherwise
	bool Person::operator ==(const Person& pr) {
		return (first.compare(pr.getFirst()) == 0 &&
				last.compare(pr.getLast()) == 0);
	}
	// Just assigns the old names to the new object
	void Person::operator =(const Person& pr) {
		first = pr.getFirst();
		last = pr.getLast();
	}
	// Gets the first name and then the last name, seperated by whitespace, from the stream
	istream& operator >>(istream& is, Person& pr) {
		string fn, ln;
		is >> fn >> ln;
		pr.setFirst(fn);
		pr.setLast(ln);
		return is;
	}
	// Outputs the first and last name, seperated by a space, to the stream
	ostream& operator <<(ostream& os, const Person& pr) {
		os << pr.first << " " << pr.last;
		return os;
	}
} //Asn3
