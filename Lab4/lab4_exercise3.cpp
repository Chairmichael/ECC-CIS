////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 4
//  Problem Number:         3
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Sept.20, 2020
//  File Name:              lab4_exercise3.cpp
//
//  Purpose of Program:
//       Getting started with dynamic arrays by counting sales.
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Function declaration
 
 

int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 4 Exercise #3 by Jeff Henry - "
         << "Dynamic Arrays\n\n";


    float *monthSales;      // a pointer used to point to an array
                            // holding monthly sales 
    float total = 0; // total of all sales
    float average; // average of monthly sales
    int numOfSales; // number of sales to be processed
    int count; // loop counter 

    cout << fixed << showpoint << setprecision(2); 
    cout << "How many monthly sales will be processed? ";
    cin >> numOfSales; 
    // Fill in the code to allocate memory for the array pointed to by
    // monthSales. 
    monthSales = new float(numOfSales);

    if ( monthSales == NULL ) { // Determine if memory has been allocated
        cout << "Error allocating memory!\n";
        return 1; 
    }
    cout << "Enter the sales below\n"; 
    for (count = 0; count < numOfSales; count++)
    { 
        cout << "Sales for Month number "
             // Fill in code to show the number of the month 
             << count+1 << ": "; 
        // Fill in code to bring sales into an element of the array
        cin >> monthSales[count];
    } 

    for (count = 0; count < numOfSales; count++)
    { 
        total = total + monthSales[count];
    } 
    average = total / numOfSales;
    cout << "Average Monthly sale is $" << average << endl;
    // Fill in the code to deallocate memory assigned to the array. 

    delete monthSales;
    monthSales = NULL;

    cout << "\n\nEnd Program.\n";
    return 0;
}

 