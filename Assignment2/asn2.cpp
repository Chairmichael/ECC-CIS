////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 2
//  Author:                 Jeff Henry
//  File Name:              asn2.cpp
//
//  Purpose of Program:
//       Assignment 2
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "queue.h"
using namespace std;
using namespace DMVqueue;

//Function declaration
int main()
{
    // Output Identification
    system("CLS");
    cout << "Assignment 2 by Jeff Henry - "
         << "DMV Queue\n\n";

    bool done = false;
    char userInput;
    vector<int> waitTimes;
    int amountWaiting = 0;
    Queue waitingQueue;

    while (!done) {
        if (waitingQueue.empty()) {
            cout << "The line is empty."
                << "Enter '1' to simulate a customer's arrival "
                << "or anything else to quit: ";
        }
        else {
            cout << "Enter '1' to simulate a customer's arrival." << endl
                << "'2' to simulate helping the next customer "
                << "or anything else to quit: ";
        }
        cin >> userInput;

        if (userInput == '1') {
            waitingQueue.add();
            cout << "Customer " << waitingQueue.getNextsNumber()
                << " has entered the queue at time " << time(NULL) << ".\n";
        }
        else if (userInput == '2') {
            time_t newTimeStamp = waitingQueue.getNextsTimestamp();
            int curTime = time(NULL);

            int wait = curTime - newTimeStamp;
            cout << "Customer " << waitingQueue.getNextsNumber()
                << " is being helped at time " << curTime << endl
                << "Wait time was " << wait << " seconds." << endl;

            waitingQueue.remove();
            waitTimes.insert(waitTimes.begin(), wait);

            if (waitTimes.size() == 3) {
                double avgTime = 0;
                for (int t : waitTimes) {
                    avgTime += t;
                }
                avgTime /= 3;
                cout << "Estimated wait time for next customer "
                    << avgTime << " seconds." << endl;

                waitTimes.pop_back();
            }
        } 
        else {
            done = true;
        }
    }

    cout << "\n\nEnd Program.\n";
    return 0;
}

 
