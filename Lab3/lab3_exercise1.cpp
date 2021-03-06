////////////////////////////////////////////////////////////////////////////////
//                          ECC CIS-223 Fall 2020
//
//  Type of Assignment:     Lab 3
//  Problem Number:         
//  Section Number          100
//  Author:                 Jeff Henry
//  Date Assigned:          Sept.08, 2020
//  Due date:               Spt. 13, 2020
//  File Name:              lab3_exercise1.cpp
//
//  Purpose of Program:
//       This program declares a class for a circle that will have
//       member functions that set the center, find the area, find
//       the circumference and display these attributes.
//       The program as written does not allow the user to input data, but
//       rather has the radii and center coordinates of the circles (spheres in the program)
//       initialized  at declaration or set by a function.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

//class declaration section   
class Circles    
{
public:
    void setCenter(int x, int y);
    double findArea();   
    double findCircumference(); 
    void printCircleStats(); // This outputs the radius and center of the circle. 
    Circles (float r);       // Constructor
    Circles(float r, int x, int y);
    Circles();               // Default constructor
private: 
    float  radius;
    int    center_x;
    int    center_y;
};      
const double PI = 3.14;

//Client section
int main()
{
    // Output Identification
    system("CLS");
    cout << "Lab 3 Exercise #1 by Jeff Henry - "<< "Circle Program\n\n";

    Circles sphere(8);
    sphere.setCenter(9,10);
    sphere.printCircleStats();
    cout << "The area of the circle is " << sphere.findArea() << endl;
    cout << "The circumference of the circle is "
          << sphere.findCircumference() << endl << endl;


    Circles sphere1(2);
    sphere1.printCircleStats();
    cout << "The area of the circle is " << sphere1.findArea() << endl;
    cout << "The circumference of the circle is "
         << sphere1.findCircumference() << endl << endl;

    Circles sphere2;
    sphere2.printCircleStats();
    cout << "The area of the circle is " << sphere2.findArea() << endl;
    cout << "The circumference of the circle is "
         << sphere2.findCircumference() << endl << endl;

    float r;
    int x, y;
    cout << "Provide a number, or provide anything else to use default values:" << endl;
    cout << "Radius = ";
    cin >> r;
    if (cin.fail()) {
        r = 1;
        cin.clear();
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.ignore();
    }
    cout << "Center_x = ";
    cin >> x;
    if (cin.fail()) {
        x = 0;
        cin.clear();
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.ignore();
    }
    cout << "Center_y = ";
    cin >> y;
    if (cin.fail()) {
        y = 0;
        cin.clear();
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.ignore();
    }
    // cout << "r=" << r << "\tx=" << x << "\ty=" << y << endl;

    Circles sphere3(r, x, y);
    sphere3.printCircleStats();
    cout << "The area of the circle is " << sphere3.findArea() << endl;
    cout << "The circumference of the circle is "
         << sphere3.findCircumference() << endl << endl;

    return 0;
}

//___________________________________________________________________________
//Implementation section     Member function implementation

Circles::Circles() {
    radius = 1;
    center_x = center_y = 0;
}

// Fill in the code to implement the non-default constructor
Circles::Circles(float r) {
    radius = r;
    center_x = center_y = 0;
}

Circles::Circles(float r, int x, int y) {
    radius = r;
    center_x = x;
    center_y = y;
}

// Fill in the code to implement the findArea member function
double Circles::findArea() {
    return PI * radius * radius;
};

// Fill in the code to implement the findCircumference member function
double Circles::findCircumference() {
    return 2 * PI * radius;
};


void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.

{
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x 
          << "," << center_y << ")" << endl;
}

void Circles::setCenter(int x, int y)
// This procedure will take the coordinates of the center of the circle from 
// the user and place them in the appropriate member data.

{
    center_x = x;
    center_y = y;
} 
