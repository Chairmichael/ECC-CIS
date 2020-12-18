////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 15
//  Author:                 Jeff Henry
//  File Name:              lab15_exercise1.cpp
//
//  Purpose of Program:
//       Stack Template
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "stack_template.h"
using namespace std;
using namespace Lab15;

int main() {
    cout << " ~~ Jeff Henry - Lab 15 ~~\n\n";
    Stack<int> st;
    for (int i = 0; i < 100; i++) {
        st.push(i*3);
    }
    cout << "size = " << st.getSize() << endl;
    cout << "capacity = " << st.getCapacity() << endl;

    for (int i = 0; i < 50; i++) {
        cout << st.pop() << endl;
    }
    cout << "top element = " << st.get() << endl;
    cout << "size = " << st.getSize() << endl;
    cout << "capacity = " << st.getCapacity() << endl << endl;
    cout << "Adding 10 elements" << endl;
    for (int i = 0; i < 10; i++) {
        st.push(i*2);
    }
    cout << "top element = " << st.get() << endl;
    cout << "size = " << st.getSize() << endl;
    cout << "capacity = " << st.getCapacity() << endl << endl;
    cout << "push(888)" << endl;
    st.push(888);
    cout << "top element = " << st.get() << endl;
    cout << "size = " << st.getSize() << endl;
    cout << "capacity = " << st.getCapacity() << endl << endl;

    cout << "char stack..." << endl;
    Stack<char> sc;

    for (char i = 0; i < 15; i++) {
        sc.push(i*2+'a');
    }
    cout << "top element = " << sc.get() << endl;
    cout << "size = " << sc.getSize() << endl;
    cout << "capacity = " << sc.getCapacity() << endl;
}
