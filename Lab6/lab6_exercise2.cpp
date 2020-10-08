////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 6
//  Problem Number:         2
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Oct. 8, 2020
//  File Name:              lab6_exercise2.cpp
//
//  Purpose of Program:
//       Building a set data structure with overloading operators.
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <climits>
using namespace std;

#define MAX_ELEMENTS 1000

class Set {
public:
    //default constructor
    Set();
    //constructor to copy from another Set object
    Set(const Set& s);
    //construct set from array of ints
    Set(int nums[], int length);
    //add element to set
    void addElement (int element);
    //add array of int to set
    void addElement(int nums[], int length);
    //remove element from set
    void removeElement(int element);
    //check for membership
    bool isMember(int element);
    //size of set
    int size();
    //get element i
    int getElement(int i);    
    //finds element, returns index, return -1 if not found
    int find(int element);
    friend Set operator+ (Set s1, Set s2);
    friend Set operator+ (Set s1, int n);
    friend Set operator- (Set s1, Set s2);
    friend Set operator- (Set s1, int n);
    friend bool operator== (Set s1, Set s2);
    friend bool operator!= (Set s1, Set s2);
    //randomize set
    void randomize(int n, int max);
private:
    //set members
    int elements[MAX_ELEMENTS];
    //next empty position in elements
    int next;
};

Set::Set() {
    next = 0;
}

Set::Set(const Set& s) {
    next = s.next;
    for (int i = 0; i < next; i++)
        elements[i] = s.elements[i];
}

Set::Set(int nums[], int length) {
    next = 0;
    for (int i = 0; i < length - 1; i++) {
        addElement(nums, length);
    }
}

void Set::addElement(int element) {
    if (next >= MAX_ELEMENTS) {
        cerr << "Exceded maximum number of elements: " << MAX_ELEMENTS << endl;
        return;
    }
    if (isMember(element))
        return;
    elements[next] = element;
    // cout << " " << element << endl;
    next++;
}

void Set::addElement(int nums[], int length) {
    if (next + length >= MAX_ELEMENTS) {
        cerr << "Exceded maximum number of elements: " << MAX_ELEMENTS << endl;
        return;
    }
    for (int i = 0; i < length; i++) {
        if (!isMember(nums[i])) {
            elements[next] = nums[i];
            // cout << " " << nums[i] << endl;
            next++;
        }
    }
}

void Set::removeElement(int element) {
    int i, j;
    for (i = 0; i < next; i++) {
        if (elements[i] == element) {
            for (j = i; j < next - 1; j++) {
                elements[j] = elements[j + 1];
            }
            next--;
            return;
        }
    }
}

bool Set::isMember(int element) {
    for (int i = 0; i < next; i++) {
        if (elements[i] == element)
            return true;
    }
    return false;
}

// Sets n elements to random ints between 0 - max
void Set::randomize(int n, int max) {
    bool done = false;
    if (n > max) n = max;
    while (size() < n) {
        int rn = rand() % max;
        // cout << rn << " ";
        addElement(rand() % max);
    }
    cout << endl;
}

int Set::size() {
    return next;
}

int Set::getElement(int i) {
    return elements[i];
}

int Set::find(int element) {
    for (int i = 0; i < next; i++) {
        if (elements[i] == element) {
            return i;
        }
    }
    return -1;
}

Set operator+ (Set s1, Set s2) {
    Set resultSet;
    for (int i = 0; i < s1.next; i++)
        resultSet.addElement(s1.elements[i]);
    for (int i = 0; i < s2.next; i++)
        resultSet.addElement(s2.elements[i]);
    return resultSet;
}

Set operator+ (Set s, int n) {
    Set resultSet(s);
    resultSet.addElement(n);
    return resultSet;
}

Set operator- (Set s1, Set s2) {
    Set resultSet(s1);
    for (int i = 0; i < s2.next; i++) {
        resultSet.removeElement(s2.elements[i]);
    }
    return resultSet;
}

Set operator- (Set s, int n) {
    Set resultSet(s);
    resultSet.removeElement(n);
    return resultSet;
}

bool operator== (Set s1, Set s2) {
    return 0;
}

bool operator!= (Set s1, Set s2) {
    return 0;
}

int getIntUserInput(int min, int max) {
    bool done = false;
    int userInput;
    while (!done) {
        cin >> userInput;
        if (userInput < min || userInput > max)
            cout << "Not valid input." << endl;
        else
            done = true;
    }
    return userInput;
}

void printSet(Set s) {
    cout << "{ ";
    int i;
    for (i = 0; i < s.size(); i++)
        cout << s.getElement(i) << " ";
    cout << "}" << endl << i << endl;
}

int main() {
    // Output Identification
    system("CLS");
    cout << "Lab 6 Exercise #2 by Jeff Henry - "
        << "Sets\n\n";


    srand(time(0));
    Set s1;
    s1.randomize(5, 100);
    printSet(s1);
    Set s2;
    s2.randomize(9, 100);
    printSet(s2);
    printSet(s1+s2);

    cout << "Enter the size of the set you wish to be generated (0 - ";
    cout << MAX_ELEMENTS << "): " << endl;
    int setSize = getIntUserInput(0, MAX_ELEMENTS);
    cout << "Enter the maximum value for the set (0 - " << INT_MAX << "): " << endl;
    int maxValue = getIntUserInput(0, INT_MAX);
    Set s3;
    s3.randomize(setSize, maxValue);
    printSet(s3);


    cout << "\n\nEnd Program.\n";
    return 0;
}
