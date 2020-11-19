////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 9
//  Problem Number:         3
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              lab9linkedlist.cpp
//
//  Purpose of Program:
//       Linked List Class
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <string>
#include <iostream>
#include "lab9linkedlist.h"
#define CMP_EPSILON 0.0001

using namespace std;

namespace LabLinkedList
{
    LinkedList::LinkedList() {
        head = NULL;
    }

    LinkedList::~LinkedList() {
        NodePtr here = head;
        NodePtr discard;
        if (here == NULL) {
            delete here;
        }
        else {
            while (here != NULL) {
                discard = here;
                here = here->link;
                delete discard;
            }
        }
    }

    // Adds a node to the front of the list
    void LinkedList::add(double x) {
        NodePtr tempPtr = new Node;
        tempPtr->n = x;
        tempPtr->link = head;
        head = tempPtr;
    }

    // Finds x in the list and returns a NodePtr. Returns NULL otherwise.
    NodePtr LinkedList::find(double x) {
        NodePtr here = head;
        if (here == NULL) {
            return NULL;
        }
        else {
            while (here->n == x && here != NULL) {
                here = here->link;
            }
            if (here->n == x)
                return here;
            else
                return NULL;
        }
    }

    // Prints the list from front to back
    void LinkedList::printList() {
        NodePtr here = head;
        if (here == NULL) {
            cout << "NULL" << endl;
        }
        else {
            while (here != NULL) {
                cout << here->n << endl;
                here = here->link;
            }
        }
    }

    // Checks if x is anywhere in the list
    bool LinkedList::isMember(double x) {
        // If find(x) returns somes that's not NULL, then x is in the list.
        return (find(x) != NULL); 
    }

    // Search the list for x. Return the index if found, return -1 if not found.
    int LinkedList::search(double x) {
        NodePtr here = head;
        if (here == NULL) {
            cout << "NULL" << endl;
            return -1;
        }
        else {
            int i = 0;
            while (here->n != x && here != NULL) {
                // cout << "i=" << i << endl;
                i++;
                here = here->link;
            }
            if (here->n == x)
                return i;
            else
                return -1;
        }
    }

    // Removes a node from the list
    void LinkedList::remove(double x) {
        NodePtr here = head;
        NodePtr back = NULL;
        if (head == NULL) {
            cout << "Error: Removing a node from an empty list.\n";
            exit(1);
        }
        else {
            while (here->n != x && here != NULL) {
                back = here;
                here = here->link;
                cout << ".";
            }
            cout << "!\n";
            cout << here->n << "\t" << x << endl;
            if (here->n == x) {
                back->link = here->link;
                delete here;
            }
            else
                cout << "Not found." << endl;
        }
    }

    // Reverses the list
    void LinkedList::reverse() {
        NodePtr here = head;
        NodePtr prev, next = NULL;
        while (here != NULL) {
            next = here->link;
            here->link = prev;
            prev = here;
            here = next;
        }
        head = prev;
    }

    // bool doubleCompare(double a, double b, double epsilon = 0.0001) {
    //     return abs(a - b) < epsilon;
        // !(abs(here->n - x) < CMP_EPSILON)
    // }
} //LabLinkedList
