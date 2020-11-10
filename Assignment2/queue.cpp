//DISPLAY 13.23 Implementation of the Queue Class
//This is the implementation file queue.cpp.
//This is the implementation of the class Queue.
//The interface for the class Queue is in the header file queue.h.
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
using namespace std;

namespace DMVqueue
{
    Queue::Queue( ) {
        front = NULL;
        back = NULL;
    }

    // Queue::Queue(const Queue& aQueue) {
    //     if (aQueue.empty()) {
    //         front = back = NULL;
    //     }
    //     else {
    //         QueueNodePtr tempPtrOld = aQueue.front;
    //         // Moves through the nodes, front to back
    //         QueueNodePtr tempPtrNew;

    //         back = new QueueNode; // First node
    //         back->data = tempPtrOld->data;
    //         back->link = NULL;
    //         front = back;

    //         tempPtrOld = tempPtrOld->link;

    //         while (tempPtrOld != NULL) {
    //             tempPtrNew = new QueueNode;
    //             tempPtrNew->data = tempPtrOld->data;
    //             tempPtrNew->link = NULL;
    //             back->link = tempPtrNew;
    //             back = tempPtrNew;
    //             tempPtrOld = tempPtrOld->link;
    //         }
    //     }
    // }

    // Queue::~Queue( ) {
    //     int next;
    //     while (!empty()) {
    //         next = remove();
    //     }
    // }

    bool Queue::empty( ) {
        return (back == NULL);
    }

    //Uses cstddef:
    void Queue::add(int item)
    {
        if (empty( ))
        {
            front = new QueueNode;
            front->custNum = item;
            front->link = NULL;
            back = front;
        }

        else {
            QueueNodePtr tempPtr;
            tempPtr = new QueueNode;

				tempPtr->custNum = item;
            tempPtr->link = NULL;
            back->link = tempPtr;
            back = tempPtr;
        }
    }

    //Uses cstdlib and iostream:
    int Queue::remove( )
    {
        if (empty( ))
        {
            cout << "Error: Removing an item from an empty queue.\n";
            exit(1);
        }

        int result = front->custNum;

        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if (front == NULL) //if you removed the last node
            back = NULL;

        delete discard;

        return result;
    }
}//DMVqueue

