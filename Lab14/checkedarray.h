////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 14
//  Author:                 Jeff Henry
//  File Name:              checkedarray.h
//
//  Purpose of Program:
//       Range checking arrary
////////////////////////////////////////////////////////////////////////////////

#ifndef CHECKEDARRAY_H
#define CHECKEDARRAY_H

#include <iostream>
using namespace std;

namespace Lab14
{
    const int MAX_LENGTH = 10;
    class CheckedArray {
    private:
        int arrayData[MAX_LENGTH];
        int* arrayPtr;
    public:
        // Default constructor
        CheckedArray();
        // Takes an array and its size
        CheckedArray(int arr[], int len);

        // Index operator returns an element of the array
        int &operator[](int i);
        // Outputs the contents of the array to the stream
        friend ostream& operator <<(ostream& os, const CheckedArray& ca);

    };
} //Lab14
#endif //CHECKEDARRAY_H
