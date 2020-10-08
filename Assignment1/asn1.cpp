////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Assignment
//  Problem Number:         1
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.20, 2020
//  Due date:               Oct. 07, 2020
//  File Name:              asn_1.cpp
//
//  Purpose of Program:
//       Computer labs
////////////////////////////////////////////////////////////////////////////////
 
// Include Section
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getUserID();

class ComputerLab {
public:
    ComputerLab();
    ComputerLab(int labNum, int numStations);
    int getLabNumber();
    int getUserByStation(int stationNum);
    int getStationAmount();
    // int* getStationList();
    void login(int stationNum, int user);
    void logoff(int stationNum);
    int search(int user);
protected:
    int labNumber; // A number of the lab
    int stationAmount; // Amount of stations
    int *stationList; // Dynamic array containing the userIDs for each station
};

ComputerLab::ComputerLab() {
}

ComputerLab::ComputerLab(int labNum, int numStations) {
    labNumber = labNum;
    stationAmount = numStations;
    stationList = new int(numStations);
    for (int i = 0; i < numStations; i++)
        stationList[i] = 0;
}

int ComputerLab::getLabNumber() {
    return labNumber;
}

int ComputerLab::getUserByStation(int stationNum) {
    return stationList[stationNum];
}

// int* ComputerLab::getStationList() {
//     return stationList;
// }

int ComputerLab::getStationAmount() {
    return stationAmount;
}

void ComputerLab::login(int stationNum, int user) {
    stationList[stationNum] = user;
}

void ComputerLab::logoff(int stationNum) {
    stationList[stationNum] = 0; // stations index starting at 1
}

int ComputerLab::search(int user) {
    for (int i = 0; i < stationAmount; i++) {
        if (stationList[i] == user)
            return i; // stations index starting at 1
    }
    return -1; // not found
}

int getUserID() {
    bool done = false;
    int userID;
    while (!done) {
        cout << "5-digit user ID: ";
        cin >> userID;
        if (userID < 10000 || userID > 99999)
            cout << "Enter a valid ID." << endl;
        else {
            done = true;
        }
    }
    return userID;
}

int main()
{
    // Output Identification
    system("CLS");
    cout << "Assignment 1 by Jeff Henry - "
         << "Computer Labs\n\n";

    // Create the computer labs

    ComputerLab labs[4];
    labs[0] = ComputerLab(1, 5);
    labs[1] = ComputerLab(2, 6);
    labs[2] = ComputerLab(3, 4);
    labs[3] = ComputerLab(4, 3);

    bool done = false;
    while (!done) {
        // Print the menu of options for the user
        cout << "Main Menu" << endl;
        cout << "0) Quit" << endl;
        cout << "1) Simulate login" << endl;
        cout << "2) Simulate logoff" << endl;
        cout << "3) Search" << endl;

        // Get user's selection
        int input;
        cin >> input;

        // Exucte user's command
        if (input == 0) {
            done = true;
        }
        else if (input == 1) { // login
            int userID = getUserID();
            cout << "Lab number to log into: ";
            int labNum;
            cin >> labNum;
            cout << "Computer station number to log into: ";
            int stationNum;
            cin >> stationNum;
            labs[labNum].login(stationNum, userID);
        }
        else if (input == 2) { // logoff
            int userID = getUserID();
            cout << "Lab number to log off: ";
            int labNum;
            cin >> labNum;
            cout << "Computer station number to log off: ";
            int stationNum;
            cin >> stationNum;
            labs[labNum].logoff(stationNum);
        }
        else if (input == 3) { // search
            int userID = getUserID();
            bool found = false;
            for (int i = 0; i < 4; i++) {
                int result = labs[i].search(userID);
                if (result != -1) {
                    cout << userID << " found logged on in ";
                    cout << "Lab " << i << " at station " << result << ".\n";
                    found = true;
                }
            }
            if (!found) {
                cout << "User " << userID << " not found." << endl;
            } 
        }
        else {
            cout << "Not valid input." << endl;
        }

        // Output lab status
        cout << "Lab Status" << endl;
        cout << "Lab #\tComputer Stations" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i+1 << setw(13);
            for (int j = 0; j < labs[i].getStationAmount(); j++) {
                string s = to_string(j+1) + ": ";
                if (labs[i].getUserByStation(j) == 0)
                    s += "empty";
                else
                    s += to_string(labs[i].getUserByStation(j));
                cout << s;
            }
            cout << endl;
        }
        cout << setw(0);
    }

    cout << "\n\nEnd Program.\n";
    return 0;
}
