////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 2
//  Author:                 Jeff Henry
//  File Name:              queue.cpp
//
//  Purpose of Program:
//       Assignment 2
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include "queue.h"
using namespace std;

namespace DMVqueue
{
    Queue::Queue( ) {
        front = back = NULL;
        length = totalSeen = 0;
    }

    bool Queue::empty() {
        return (back == NULL);
    }

    void Queue::add()
    {
        length++, totalSeen++;
        if (empty()) {
            front = new QueueNode;
            front->custNum = totalSeen;
            front->timeStamp = time(NULL);
            front->link = NULL;
            back = front;
        }
        else {
            QueueNodePtr tempPtr;
            tempPtr = new QueueNode;
            tempPtr->custNum = totalSeen;
            tempPtr->timeStamp = time(NULL);
            tempPtr->link = NULL;
            back->link = tempPtr;
            back = tempPtr;
        }
    }

    int Queue::remove() {
        if (empty()) {
            cout << "Error: Removing an item from an empty queue.\n";
            exit(1);
        }

        int result = front->timeStamp;
        length--;

        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if (front == NULL) //if you removed the last node
            back = NULL;

        delete discard;

        return result;
    }

    int Queue::size() {
        return length;
    }

    int Queue::getNextsNumber() {
        return front->custNum;
    }

    int Queue::getNextsTimestamp() {
        return front->timeStamp;
    }
}//DMVqueue

