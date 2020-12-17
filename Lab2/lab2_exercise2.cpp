////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 2
//  Author:                 Jeff Henry
//  File Name:              lab2_exercise2.cpp
//
//  Purpose of Program:
//       Payroll class
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

class PayRoll {
public:
	PayRoll();
	PayRoll(double rate, double hours);
	double getRate();
	void setRate(double rate);
	double getHoursWorked();
	void setHoursWorked(double h);
	double getTotalPay();
	void setTotalPay(double t);
	void getInput();
	void printAll();
	void calculatePay();
private:
	double hourlyRate; // Hourly
	double hoursWorked; // Weekly
	double totalPay; // Weekly
};

// Constructors
PayRoll::PayRoll() {
	hourlyRate = 0;
	hoursWorked = 0;
	totalPay = 0;
}
PayRoll::PayRoll(double rate, double hours) {
	hourlyRate = rate;
	hoursWorked = hours;
	PayRoll::calculatePay();
}

// Getter and setter functions
double PayRoll::getRate() { return hourlyRate; }
void PayRoll::setRate(double rate) { hourlyRate = rate; }
double PayRoll::getHoursWorked() { return hoursWorked; }
void PayRoll::setHoursWorked(double hours) { hoursWorked = hours; }
double PayRoll::getTotalPay() { return totalPay; }
void PayRoll::setTotalPay(double pay) { totalPay = pay; }

// Gets the hourly rate and hours worked from the user
void PayRoll::getInput() {
	cout << "Please enter your hourly rate and hours worked for the week." << endl;
	cin >> hourlyRate >> hoursWorked;
}

// Prints out the three member variables
void PayRoll::printAll() {
	cout << "Hourly rate : " << hourlyRate << endl;
	cout << "Hours worked : " << hoursWorked << endl;
	cout << "Total pay : " << totalPay << endl;
}

// Calculate the pay for the week
void PayRoll::calculatePay() {
	totalPay = hourlyRate * hoursWorked;
}

int main() {
	int const NUMBER_OF_EMPLOYEES = 5;
	PayRoll employees[NUMBER_OF_EMPLOYEES];
	for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++) {
		cout << "Employee " << i+1 << ":" << endl;
		employees[i].getInput();
		employees[i].calculatePay();
	}
	for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++) {
		cout << endl << "Employee " << i+1 << ":" << endl;
		employees[i].printAll();
	}
}
