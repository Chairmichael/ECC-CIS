////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 4
//  Problem Number:         4
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Sept.20, 2020
//  File Name:              lab4_exercise4.cpp
//
//  Purpose of Program:
//       
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


int* getRandomNumbers(int num) {
    minstd_rand randEng(time(NULL));
    int *randArr = new int(num);
    for (int i = 0; i < num; i++) {
        randArr[i] = randEng();
    }
    return randArr;
}

int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 4 Exercise #4 by Jeff Henry - "
         << "Returning Pointers from Functions\n\n";

    
    int amount;
    cout << "Enter the amount of random numbers to generate: ";
    cin >> amount;

    int *randomArray = getRandomNumbers(amount);

    cout << "Numbers generated for you (0-999999): " << endl;
    for (int i = 0; i < amount; i++) {
        cout << "\t" << randomArray[i] << endl;
    }

    float avg;
    float total;
    for (int i = 0; i < amount; i++) {
        total += randomArray[i];
    }
    avg = total / amount;
    cout << "Total: " << total << endl;
    cout << "Average: " << avg << endl;

    cout << "\n\nEnd Program.\n";
    return 0;
}

 