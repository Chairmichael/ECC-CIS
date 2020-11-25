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
	Person::Person() : first(""), last("") { }
	Person::Person(string fn, string ln) : first(fn), last(ln) { }
	Person::Person(const Person& original)
		: first(original.getFirst()), last(original.getLast()) { }

	void Person::setFirst(string fn) { first = fn; }
	void Person::setLast(string ln) { last = ln; }
	string Person::getFirst() const { return first; }
	string Person::getLast() const { return last; }

	bool Person::operator ==(const Person& pr) {
		return (first.compare(pr.getFirst()) == 0 &&
				last.compare(pr.getLast()) == 0);
	}
	void Person::operator =(const Person& pr) {
		first = pr.getFirst();
		last = pr.getLast();
	}
	istream& operator >>(istream& is, Person& pr) {
		string fn, ln;
		is >> fn >> ln;
		pr.setFirst(fn);
		pr.setLast(ln);
		return is;
	}
	ostream& operator <<(ostream& os, const Person& pr) {
		os << pr.first << " " << pr.last;
		return os;
	}
} //Asn3
