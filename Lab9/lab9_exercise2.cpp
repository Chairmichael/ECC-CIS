////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 9
//  Problem Number:         2
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              lab9_exercise2.cpp
//
//  Purpose of Program:
//       Overloading input and output operators
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <string>
#include <iostream>

using namespace std;

void headInsert(NodePtr& head, string newItem, int newCount);

struct Node {
    string item;
    int count;
    Node *link;
};
typedef Node* NodePtr;

void headInsert(NodePtr& head, string newItem, int newCount) {
    NodePtr tempPtr;
    tempPtr = new Node;

    tempPtr->item = theNumber;
    tempPtr->count = newCount;

    tempPtr->link = head;
    head = tempPtr;
}

NodePtr search(NodePtr head, int target) {
    NodePtr here = head;

    if (here == NULL) {
        return NULL;
    }
    else {
        while (here->data != target && here->link != NULL)
            here = here->link;
        if (here->data == target)
            return here;
        else
            return NULL;
    }
}


int main( )
{
    // Output Identification
    system("CLS");
    cout << "Lab 9 Exercise #2 by Jeff Henry - "
        << "Linked List\n\n";

    

    cout << "\n\nEnd Program.\n";
    return 0;
} 
