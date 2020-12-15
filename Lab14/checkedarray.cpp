////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 14
//  Author:                 Jeff Henry
//  File Name:              checkedarray.cpp
//
//  Purpose of Program:
//       Range checking arrary
////////////////////////////////////////////////////////////////////////////////

#include "checkedarray.h"
using namespace std;

namespace Lab14
{
    // Default constructor
    CheckedArray::CheckedArray() {
        // Fills in array with 0s
        for (int i = 0; i < MAX_LENGTH; i++)
            arrayData[i] = 0;
        arrayPtr = arrayData;
    }
    // Takes an array and its size
    CheckedArray::CheckedArray(int arr[], int len) {
        // Disregard any elements in arr past MAX_LENGTH
        if (MAX_LENGTH < len) { 
            for (int i = 0; i < MAX_LENGTH; i++)
                arrayData[i] = arr[i];
        }
        else {
            // Fill in array
            for (int i = 0; i < len; i++)
                arrayData[i] = arr[i];
            // Fill in the rest of array with 0s
            for (int i = len; i < MAX_LENGTH; i++)
                arrayData[i] = 0;
        }
        arrayPtr = arrayData;

    }

    // Index operator returns a pointer to an element of the array
    int &CheckedArray::operator[](int i) {
        if (i < 0 || i >= MAX_LENGTH) {
            throw ArrayOutOfRangeError();
            int* np = nullptr;
            return *np;
        }
        return *(arrayPtr + i);
    }
    // Outputs the contents of the array to the stream
    ostream& operator <<(ostream& os, const CheckedArray& ca) {
        os << "[";
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (i == MAX_LENGTH - 1)
                os << " " << ca.arrayData[i];
            else
                os << " " << ca.arrayData[i] << ",";
        }
        os << "]";
        return os;
    }
} //Lab14
