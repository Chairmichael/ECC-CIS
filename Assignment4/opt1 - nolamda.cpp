////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment 4
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  File Name:              opt1.cpp
//
//  Purpose of Program:
//       Permutations
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <functional>

using namespace std;

// Helper function to recursively find permutations
//  theSet - set to add permutations
//  v - the vector to permute
//  begin - initially pass 0 in
//  end - the size of the vector
void permute(set< vector<int> > theSet, vector<int> v, int begin, int end) {
    if (begin == end - 1) {
        theSet.insert(v);
        cout << "inserted" << endl;
        return;
    }
    for (int i = begin; i < end; i++) {
        // start swap forward
        swap(v[begin], v[i]);
        permute(theSet, v, begin + 1, end);
        // swap back
        swap(v[begin], v[i]);
    }
}

set< vector<int> > getPermutations(vector<int> v) {
    set< vector<int> > s;
    permute(s, v, 0, v.size());
    return s;
}


int main() {
    cout << "Assignment 4" << endl;
    vector<int> v = {1,2,3};
    set< vector<int> > pSet = getPermutations(v);
    for (vector<int> vct : pSet) {
        cout << "{ ";
        for (int num : vct) 
            cout << num << " ";
        cout << "}" << endl;
    }

    // for (set< vector<int> >::iterator it=permSet.begin(); it!=permSet.end(); ++it) {
    //     cout << *it << endl;
    // }
    return 0;
}