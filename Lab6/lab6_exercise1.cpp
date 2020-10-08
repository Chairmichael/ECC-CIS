////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 6
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Oct. 8, 2020
//  File Name:              lab6_exercise1.cpp
//
//  Purpose of Program:
//       Overloading input and output operators
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include<iostream> 
#include<cstdlib> 
#include<fstream> 

using namespace std; 

class AltMoney { 
public: 
    AltMoney(); 
    friend void read_money(istream& ins, AltMoney& m); 
    friend AltMoney operator +(AltMoney m1, AltMoney m2); 
    friend void write_money(ofstream& ous, AltMoney m); 
    friend void operator >>(istream& ins, AltMoney& m);
    friend void operator <<(ofstream& ous, AltMoney m);
private: 
    int dollars; 
    int cents; 
}; 

void read_money(istream& ins, AltMoney& m); 
void get_streams(ifstream& ins, ofstream& ous); 
void write_money(ofstream& ous, AltMoney m); 
void operator >>(istream& ins, AltMoney& m);
void operator <<(ofstream& ous, AltMoney m);

int main( )
{
    // Output Identification
    system("CLS");
    cout << "Lab 6 Exercise #1 by Jeff Henry - "
        << "Overloading input and output operators\n\n";


    ifstream ins; 
    ofstream ous; 
    AltMoney m1, m2, sum; 
    get_streams(ins, ous); 
    // read_money(ins, m1); 
    ins >> m1;
    ous << "The first money is: "; 
    // write_money(ous, m1);
    ous << m1; 
    // read_money(ins, m2); 
    ins >> m2;
    ous << "The second money is: "; 
    // write_money(ous, m2); 
    ous << m2;
    sum = m1+m2; 
    ous << "The sum is: "; 
    // write_money(ous, sum); 
    ous << sum;
    ins.close(); 
    ous.close(); 


    cout << "\n\nEnd Program.\n";
    return 0;
} 

AltMoney::AltMoney() { } 

void write_money(ofstream& ous, AltMoney m) 
{ 
    ous << "$" << m.dollars << "."; 
    if(m.cents <= 9) 
        ous << "0";  //to display a 0 on the left for numbers less than 10
    ous << m.cents << endl;
}

AltMoney operator +(AltMoney m1, AltMoney m2) 
{ 
    AltMoney temp; 
    int extra = 0; 
    temp.cents = m1.cents + m2.cents; 
    if(temp.cents >=100){ 
        temp.cents = temp.cents - 100; 
        extra = 1; 
    } 
    temp.dollars = m1.dollars + m2.dollars + extra; 
    return temp; 
} 

void read_money(istream& ins, AltMoney& m) 
{ 
    int d, c; 
    ins >> d; 
    ins >> c; 
    if( d < 0 || c < 0) 
    { 
        cout << "Invalid dollars and cents, negative values\n"; 
        exit(1); 
    } 
    m.dollars = d; 
    m.cents = c; 
} 


void operator >>(istream& ins, AltMoney& m) {
    int d, c; 
    ins >> d; 
    ins >> c; 
    if( d < 0 || c < 0) 
    { 
        cout << "Invalid dollars and cents, negative values\n"; 
        exit(1); 
    } 
    m.dollars = d; 
    m.cents = c; 
}

void operator <<(ofstream& ous, AltMoney m) {
    ous << "$" << m.dollars << "."; 
    if(m.cents <= 9) 
        ous << "0";  //to display a 0 on the left for numbers less than 10 
    ous << m.cents << endl; 
}

void get_streams(ifstream& ins, ofstream& ous) 
{ 
    ins.open("in_file.dat"); 
    if(ins.fail()) 
    { 
       cout << "Failed to open the input file. \n"; 
       exit(1); 
    } 
    ous.open("out_file.dat"); 
    if(ous.fail()) 
    { 
       cout << "Failed to open the output file. \n"; 
       exit(1); 
    } 
} 