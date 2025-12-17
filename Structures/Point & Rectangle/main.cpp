// Two points, when connected using horizontal and vertical lines, will form a rectangle.

// In a rectangle header file, create the Rectangle struct that contains two Points. 
// Since this will use the Point struct, 
// don't forget to have the Point struct added as a header file.

// With this, you will also be able to calculate for the rectangle's area and 
// perimeter and so, create these methods that will utilize the Rectangle 
// struct and shall return int.

#include <iostream>
#include <bits/stdc++.h>
#include "rectangle.hpp"
using namespace std;

int main() {
    Rectangle rect;

    cout << "Enter x of rectangle point 1: ";
    cin >> rect.p1.x;
    cout << "Enter y of rectangle point 1: ";
    cin >> rect.p1.y;
    cout << "Enter x of rectangle point 2: ";
    cin >> rect.p2.x;
    cout << "Enter y of rectangle point 2: ";
    cin >> rect.p2.y;

    cout << endl << "Perimeter of the rectangle: " << rect.perimeter();
    cout << endl << "Area of the rectangle: " << rect.area() << endl;

    return 0;
}