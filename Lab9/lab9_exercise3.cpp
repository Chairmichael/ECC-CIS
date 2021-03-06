////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 9
//  Problem Number:         2
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              lab9_exercise3.cpp
//
//  Purpose of Program:
//       Overloading input and output operators
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <string>
#include <iostream>
#include "lab9linkedlist.h"

using namespace std;
using namespace LabLinkedList;

int main( )
{
    // Output Identification
    system("CLS");
    cout << "Lab 9 Exercise #3 by Jeff Henry - "
        << "Linked List\n\n";

    LinkedList list;
    list.add(3);
    list.add(8);
    list.add(-29);
    list.printList();

    cout <<  "list.search(3) = " << list.search(3) << endl;

    cout << "Reversing..." << endl;
    list.reverse();
    list.printList();

    cout <<  "list.search(3) = " << list.search(3) << endl;

    cout << "Removing 3 and -29" << endl;
    list.remove(-29);
    list.remove(3);
    cout << "Adding 883" << endl;
    list.add(883);
    list.printList();

    cout << "\n\nEnd Program.\n";
    return 0;
} 
