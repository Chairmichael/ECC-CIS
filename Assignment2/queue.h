////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 2
//  Author:                 Jeff Henry
//  File Name:              queue.h
//
//  Purpose of Program:
//       Assignment 2
////////////////////////////////////////////////////////////////////////////////

#ifndef QUEUE_H
#define QUEUE_H
namespace DMVqueue
{
    struct QueueNode {
        int custNum;
        int timeStamp;
        QueueNode *link;
    };

    typedef QueueNode* QueueNodePtr;

    class Queue {
    public:
        Queue();

        void add();

        int remove();
        //Precondition: The queue is not empty.
        //Returns the item at the front of the queue and
        //removes that item from the queue.

        bool empty();
        //Returns true if the queue is empty. Returns false otherwise.

        int size();
        // Returns the amount of nodes in the queue.

        int getNextsNumber();
        // Returns the next customer's number

        int getNextsTimestamp();
        // Returns the next customer's timestamp

    private:
        int length;
        int totalSeen;
        QueueNodePtr front; //Points to the head of a linked list.
                            //Items are removed at the head
        QueueNodePtr back; //Points to the node at the other end of the
                           //linked list. Items are added at this end.
    };
}//DMVqueue
#endif //QUEUE_H
