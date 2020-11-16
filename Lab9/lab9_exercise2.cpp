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

struct Node {
    string item;
    int count;
    Node *link;
};
typedef Node* NodePtr;

void headInsert(NodePtr& head, string newItem, int newCount);
NodePtr search(NodePtr head, int target);
void showList(NodePtr& head);
void printNode(NodePtr& n);


void headInsert(NodePtr& head, string newItem, int newCount) {
    NodePtr tempPtr;
    tempPtr = new Node;

    tempPtr->item = newItem;
    tempPtr->count = newCount;

    tempPtr->link = head;
    head = tempPtr;
}

NodePtr search(NodePtr head, string target) {
    NodePtr here = head;
    if (here == NULL) {
        return NULL;
    }
    else {
        while (here->item.compare(target) != 0 && here->link != NULL)
            here = here->link;
        if (here->item == target)
            return here;
        else
            return NULL;
    }
}

void showList(NodePtr& head) {
    NodePtr here = head;
    if (here == NULL) {
        cout << "NULL" << endl;
    }
    else {
        while (here->link != NULL) {
            cout << here->count << "\t" << here->item << endl;
            here = here->link;
        }
    }
}

void printNode(NodePtr& n) {
    cout << n->count << "\t" << n->item << endl;
}


int main( )
{
    // Output Identification
    system("CLS");
    cout << "Lab 9 Exercise #2 by Jeff Henry - "
        << "Linked List\n\n";

    NodePtr listHead = new Node;
    headInsert(listHead, "Foo", 1);
    headInsert(listHead, "Bar", 2);
    headInsert(listHead, "Last", 18);
    showList(listHead);

    cout << "\nExecuting search..." << endl;
    NodePtr location = search(listHead, "Bar");
    printNode(location);

    cout << "\n\nEnd Program.\n";
    return 0;
} 
