////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 4
//  Problem Number:         2
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Sept.20, 2020
//  File Name:              lab4_exercise2.cpp
//
//  Purpose of Program:
//       Experimenting with dynamic memory
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXNAME = 10; 

//Function declaration
 
 

int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 4 Exercise #2 by Jeff Henry - "
         << "Dynamic Memory\n\n";


    int pos;
    char * name;
    int * one;
    int * two;
    int * three;
    int result; 

    // Fill in code to allocate the integer variable one here
    one = new int;
    // Fill in code to allocate the integer variable two here
    two = new int;
    // Fill in code to allocate the integer variable three here
    three = new int;
    // Fill in code to allocate the character array pointed to by name 
    name = new char[MAXNAME];

    cout << "Enter your last name with exactly 10 characters." << endl;
    cout << "If your name has < 10 characters, repeat last letter. " << endl 
    << "Blanks at the end do not count." << endl; 
    
    for (pos = 0; pos < MAXNAME; pos++) 
        cin >> *(name + pos); // Fill in code to read a character into the name array
                             // WITHOUT USING a bracketed subscript 
    cout << "Hi ";

    
    for (pos = 0; pos < MAXNAME; pos++)
        cout << *(name + pos); // Fill in code to a print a character from the name array
                // WITHOUT USING a bracketed subscript 
        
    cout << endl << "Enter three integer numbers separated by blanks" << endl; 

    // Fill in code to input three numbers and store them in the
    // dynamic variables pointed to by pointers one, two, and three.
    // You are working only with pointer variables 
    cin >> *one >> *two >> *three;
    
    cout << "The three numbers are " << endl; 
    // Fill in code to output those numbers 
    cout << *one << " " << *two << " " << *three << endl;
    
    // Fill in code to calculate the sum of the three numbers
    result = *one + *two + *three;
    
    cout << "The sum of the three values is " << result << endl; 
    
    // Fill in code to deallocate one, two, three and name
    delete one;
    delete two;
    delete three; 
    delete name;
    one, two, three, name = NULL;

    cout << "\n\nEnd Program.\n";
    return 0;
}

 