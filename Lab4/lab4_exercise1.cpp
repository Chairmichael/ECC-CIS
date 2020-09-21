////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 4
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Sept.20, 2020
//  File Name:              lab4_exercise1.cpp
//
//  Purpose of Program:
//       Warming up to the concept of pointers.
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration
 
 

int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 4 Exercise #1 by Jeff Henry - "
         << "Intro to Pointers\n\n";


    int length; // holds length
    int width; // holds width
    int area; // holds area 
    int *lengthPtr; // int pointer which will be set to point to length
    int *widthPtr; // int pointer which will be set to point to width 

    cout << "Please input the length of the rectangle" << endl;
    cin >> length;
    cout << "Please input the width of the rectangle" << endl;
    cin >> width; 

    // Fill in code to make lengthPtr point to length (hold its address)
    lengthPtr = &length;

    // Fill in code to make widthPtr point to width (hold its address) 
    widthPtr = &width;

    // Fill in code to find the area by using only the pointer variables
    area =  (*lengthPtr) * (*widthPtr);


    cout << "The area is " << area << endl; 

    // Fill in the condition length > width by using only the pointer variables
    if ((*lengthPtr) > (*widthPtr))
        cout << "The length is greater than the width" << endl; 

    // Fill in the condition of width > length by using only the pointer variables
    else if ((*widthPtr) > (*lengthPtr))
        cout << "The width is greater than the length" << endl; 
    else
        cout << "The width and length are the same" << endl;


    cout << "\n\nEnd Program.\n";
    return 0;
}

 