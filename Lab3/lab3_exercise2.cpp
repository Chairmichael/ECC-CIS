////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 3
//  Problem Number:         2
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.08, 2020
//  Due date:               Spt. 13, 2020
//  File Name:              lab3_exercise2.cpp
//
//  Purpose of Program:
//       Simple OOP implementation of an Employee and a type of Employee
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
protected:
	string name;
	int number;
	string hireDate;
public:
	Employee();
	Employee(string s, int n, string date);
	void setName(string s);
	string getName();
	void setNumber(int n);
	int getNumber();
	void setHireDate(string s);
	string getHireDate();
};
Employee::Employee() {
	name = "";
	number = -1;
	hireDate = "";
}
Employee::Employee(string s, int n, string date) {
	name = s;
	number = n;
	hireDate = date;
}
void Employee::setName(string s) {
	name = s;
}
string Employee::getName() {
	return name;
}
void Employee::setNumber(int n) {
	number = n;
}
int Employee::getNumber() {
	return number;
}
void Employee::setHireDate(string s) {
	hireDate = s;
}
string Employee::getHireDate() {
	return hireDate;
}

class ProductionWorker : public Employee {
private:
	int shift;
	double wage;
public:
	ProductionWorker();
	ProductionWorker(string s, int n, string date, int sh, double w);
	void setShift(int n);
	int getShift();
	void setWage(double d);
	double getWage();
};
ProductionWorker::ProductionWorker() : Employee() {
	shift = 0;
	wage = 0;
}
ProductionWorker::ProductionWorker(
		string s, int n, string date, int sh, double w) {
	name = s;
	number = n;
	hireDate = date;
	shift = sh;
	wage = w;
}
void ProductionWorker::setShift(int n) {
	shift = n;
}
int ProductionWorker::getShift() {
	return shift;
}
void ProductionWorker::setWage(double d) {
	wage = d;
}
double ProductionWorker::getWage() {
	return wage;
}

int main() {
    // Output Identification
    system("CLS");
    cout << "Lab 3 Exercise #2 by Jeff Henry - "<< "Employees\n\n";

	cout << fixed << setprecision(2);
	ProductionWorker worker1("Jon Jacksonaton", 238, "10/10/11", 1, 22.20);
	cout << " << worker1 >> " << endl;
	cout << "Name:     " << worker1.getName() << endl;
	cout << "Number:   " << worker1.getNumber() << endl;
	cout << "HireDate: " << worker1.getHireDate() << endl;
	cout << "Shift:    " << worker1.getShift() << endl;
	cout << "Wage:     " << worker1.getWage() << endl;
}