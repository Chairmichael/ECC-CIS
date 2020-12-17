////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 2
//  Author:                 Jeff Henry
//  File Name:              lab2_exercise1.cpp
//
//  Purpose of Program:
//       Savings account
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

class SavingsAccount 
{
public:
    // Default constructor, sets dollars and cents to 0
    SavingsAccount() { dollars = cents = 0; }
    // Initializes a SavingsAccount obj with dollars and cents input by user
    SavingsAccount(int dollars, int cents);

    // Open/set account, ask user for dollars and cents
    void setAccount(int dollars, int cents);
    // Deposit money in the account, adds the dollars and cents
    void deposit(int dollars, int cents);
    // Withdraw money from the account, removed the dollars and cents
    void withdraw(int dollars, int cents);
    // Print account balance in dollars and cents
    void printBalance();

private:
    int dollars;
    int cents;
    void normalizeCents();
};

SavingsAccount::SavingsAccount(int d, int c) {
    if (d >= 0 && c >= 0) {
        dollars = d;
        cents = c;
        normalizeCents();
    } else {
        cout << "Invalid dollar and/or cents amount" << endl;
        exit(EXIT_FAILURE);
    }
}

void SavingsAccount::setAccount(int d, int c) {
    if (d >= 0 && c >= 0) {
        dollars = d;
        cents = c;
        normalizeCents();
    } else {
        cout << "Invalid dollar and/or cents amount" << endl;
        exit(EXIT_FAILURE);
    }
}

void SavingsAccount::deposit(int d, int c) {
    if (d >= 0 && c >= 0) {
        dollars += d;
        cents += c;
        normalizeCents();
    } else {
        cout << "Invalid dollar and/or cents amount" << endl;
        exit(EXIT_FAILURE);
    }
}

void SavingsAccount::withdraw(int d, int c) {
    if (d >= 0 && c >= 0) {
        double oldBal = dollars;
        oldBal += (cents / 100.0);
        double withdrawBal = d;
        withdrawBal += (c / 100.0);
        if (oldBal >= withdrawBal) {
            dollars -= d;
            cents -= c;
            normalizeCents();
        } else {
            cout << "Dollars to be withdrawn exceeded ammount in account." << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cout << "Invalid dollar and/or cents amount" << endl;
        exit(EXIT_FAILURE);
    }
}

void SavingsAccount::printBalance() {
    cout << "dollars = " << dollars << "\tcents = " << cents << endl;
}

void SavingsAccount::normalizeCents() {
    int n = cents / 100;
    dollars += n;
    cents -= 100 * n;
    if (cents < 0) {
        cents += 100;
        dollars -= 1;
    }
}


int main() {
    SavingsAccount bank1(100,30);
    SavingsAccount bank2;
    bank1.withdraw(39,40);
    bank1.printBalance();
    bank2.deposit(12,255);
    bank2.printBalance();
    return 0;
}
