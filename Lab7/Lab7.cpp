
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class StringSet {
public:
    StringSet();
    StringSet(const string str);
    StringSet(const StringSet& s);
    StringSet(const string arr[], int len);
    StringSet(const std::vector<string> vt);
    ~StringSet();

    void add(string s);
    void add(const string arr[], int len);
    void add(const vector<string> vt);
    void remove(string s);
    bool isMember(string s);
    int size();
    string get(int i);
    int find(string s); // Finds the index of the string s
    void operator= (StringSet s2);
    double similarity(StringSet s);
    StringSet operator+= (string s);
    StringSet operator+= (StringSet s2);
    StringSet operator-= (string s);
    StringSet operator-= (StringSet s2);

    friend StringSet operator+ (StringSet s1, string s);
    friend StringSet operator+ (StringSet s1, StringSet s2);
    // friend StringSet operator+= (StringSet s1, string s);
    // friend StringSet operator+= (StringSet s1, StringSet s2);
    friend StringSet operator- (StringSet s1, string s);
    friend StringSet operator- (StringSet s1, StringSet s2);

    // friend istream& operator>>(istream& ins, StringSet& s);
    friend ostream& operator<< (ostream& ous, StringSet& s);
    
    friend bool operator== (StringSet s1, StringSet s2);
    friend bool operator!= (StringSet s1, StringSet s2);
    friend bool operator< (StringSet s1, StringSet s2);
    friend bool operator> (StringSet s1, StringSet s2);
    friend bool operator<= (StringSet s1, StringSet s2);
    friend bool operator>= (StringSet s1, StringSet s2);
    friend StringSet operator* (StringSet s1, StringSet s2);

private:
    vector<string> v;

};

StringSet::StringSet() {
}

StringSet::StringSet(const string str) {
    v.push_back(str);
}

StringSet::StringSet(const StringSet& s) {
    v = s.v;
    // v = vector<string>(s.v);
}

StringSet::StringSet(const string arr[], int len) {
    // v = vector<string>(begin(arr), end(arr));
    for (int i = 0; i < len; i++)
        v.push_back(arr[i]);
}

StringSet::StringSet(const std::vector<string> vt) {
    v = vector<string>(vt);
}

StringSet::~StringSet() {
    delete &v;
    // cout << "Deleting StringSet vector" << endl;
}


/* ## Methods ## */
string StringSet::get(int i) {
    return v[i];
}


int StringSet::size() {
    return v.size();
}

bool StringSet::isMember(string str) {
    for (string se: v)
        if (str.compare(se) == 0) 
            return true;
    return false;
}

void StringSet::add(string str) {
    if (!isMember(str))
        v.push_back(str);
}

void StringSet::add(const string arr[], int len) {
    // v.insert(end(v), begin(arr), end(b));
    for (int i = 0; i < len; i++) {
        add(arr[i]);
    }
}

void StringSet::add(const vector<string> vt) {
    // v.insert(end(v), begin(arr), end(b));
    for (string se: vt)
        add(se);
}

void StringSet::remove(string s) {
    for (int i = 0; i < v.size(); i++) {
        if (s.compare(v[i]) == 0)
            v.erase(v.begin() + i);
    }
}

void StringSet::operator= (StringSet s2) {
    v = s2.v;
}

double StringSet::similarity(StringSet otherSet) {
    StringSet thisSet = *this;
    double nm = (thisSet * otherSet).size();
    // cout << "nm: " << nm << endl;
    double dn = sqrt(thisSet.size()) * sqrt(otherSet.size());
    // cout << "dn: " << dn << endl;
    return nm / dn;
}


/* ## Friend functions ## */
StringSet operator+ (StringSet s1, string str) {
    StringSet resultSS(s1);
    resultSS.add(str);
    return resultSS;
}

StringSet operator+ (StringSet s1, StringSet s2) {
    StringSet resultSS(s1);
    for (int i = 0; i < s2.size(); i++)
        resultSS.add(s2.get(i));
    return resultSS;
}

// StringSet StringSet::operator+= (StringSet s1, string str) {
StringSet StringSet::operator+= (string str) {
    add(str);
    return (*this);
}

// StringSet StringSet::operator+= (StringSet s1, StringSet s2) {
StringSet StringSet::operator+= (StringSet s2) {
    for (string str: s2.v) {
        add(str);
    }
    return (*this);
}

StringSet operator- (StringSet s1, string str) {
    StringSet resultSS(s1);
    resultSS.remove(str);
    return resultSS;
}

StringSet operator- (StringSet s1, StringSet s2) {
    StringSet resultSS(s1);
    for (string str: s2.v) {
        resultSS.remove(str);
    }
    return resultSS;
}

// StringSet operator-= (StringSet s1, string str) {
StringSet StringSet::operator-= (string str) {
    remove(str);
    return (*this);
}

// StringSet operator-= (StringSet s1, StringSet s2) {
StringSet StringSet::operator-= (StringSet s2) {
    for (string str: s2.v) {
        remove(str);
    }
    return (*this);
}

istream& operator>>(istream& ins, StringSet& s) {
    string data;
    ins >> data;
    s.add(data);
    return ins;
}

ostream& operator<< (ostream& ous, StringSet& s) {
    ous << "{ ";
    for (int i = 0; i < s.size()-1; i++) {
        ous << s.get(i) << ", ";
    }
    ous << s.get(s.size()-1) << " }";
    return ous;
}

bool operator== (StringSet s1, StringSet s2) {
    for (string str: s1.v)
        if (!s2.isMember(str))
            return false;
    return true;
}

bool operator!= (StringSet s1, StringSet s2) {
    return !(s1 == s2);
}

bool operator< (StringSet s1, StringSet s2) {
    return s1.size() < s2.size();
}

bool operator> (StringSet s1, StringSet s2) {
    return s1.size() > s2.size();
}

bool operator<= (StringSet s1, StringSet s2) {
    return s1.size() <= s2.size();
}

bool operator>= (StringSet s1, StringSet s2) {
    return s1.size() >= s2.size();
}

StringSet operator* (StringSet s1, StringSet s2) {
    StringSet resultSS;
    for (string str: s1.v) {
        if (s2.isMember(str))
            resultSS.add(str);
            // resultSS += str;
    }
    return resultSS;
}


// Finds the index of the string s, simply by iterating thru the vector
int StringSet::find(string str) {
    for (int i = 0; i < size(); i++) {
        if (v[i].compare(str) == 0)
            return i;
    }
    return -1;
}

void printSet(StringSet s) {
    cout << "{ ";
    for (int i = 0; i < s.size()-1; i++) {
        cout << s.get(i) << ", ";
    }
    cout << s.get(s.size()-1) << " }" << endl;
}

void printSet(StringSet s, string name) {
    cout << "" << name << " = { ";
    for (int i = 0; i < s.size()-1; i++) {
        cout << s.get(i) << ", ";
    }
    cout << s.get(s.size()-1) << " }" << endl;
}

void get_streams(ifstream& ifs, ofstream& ofs) 
{
    ifs.open("in_file.dat"); 
    if(ifs.fail()) 
    { 
       cout << "Failed to open the input file. \n"; 
       exit(1); 
    } 
    ofs.open("out_file.dat"); 
    if(ofs.fail()) 
    { 
       cout << "Failed to open the output file. \n"; 
       exit(1); 
    } 
}


int main(int argc, char const *argv[])
{
    ifstream ifs;
    ofstream ofs;
    get_streams(ifs, ofs);

    string sa[] = {"Tuesday", "Wednesday"};
    StringSet s1(sa, 2);
    cout << s1 << endl;

    vector<string> v = {"foo", "bar", "10"};
    StringSet s2(v);
    printSet(s2,"s2");


    return 0;
}
