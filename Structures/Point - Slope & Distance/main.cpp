// Given two points, it would form a line. 
// Your task is to calculate the distance and the slope of the line.

// In the point.hpp file, create the double distance(Point* other) 
// and the double slope(Point* other)methods

// For the distance method, return the distance between the two points. 
// Note that the formula to get the distance is d = √((x₂ - x₁)² + (y₂ - y₁)²)
// For the slope method, return the slope of the two points. 
// Note that the formula to get the slope is m=(y2-y1)/(x2-x1). 
// It does not matter who the first or the second point is -- it will arrive to the same answer.
 
// In this case of the problem, assume that the two points are not the same, 
// for when it is, there is no line and therefore no slope and no distance.

// Note that when the y-coordinates of the two points are the same, 
// the line is horizontal and therefore the slope is zero. 
// Also, when the x-coordinates of the two points are the same, 
// the line is vertical and therefore the slope is infinite. 
// This will be correctly defined in C++ as when floating-point numbers are divided by zero, 
// C++ interprets it as inf, short for infinity.

#include <iostream>
#include "point.hpp"
using namespace std;

int main() {
    Point point1, point2;
    cout << "Enter x of point 1: ";
    cin >> point1.x;
    cout << "Enter y of point 1: ";
    cin >> point1.y;
    cout << "Enter x of point 2: ";
    cin >> point2.x;
    cout << "Enter y of point 2: ";
    cin >> point2.y;

    cout << endl << "The slope of the line connected by the two points is " << point1.slope(&point2) << endl;
    cout << "The distance of the line between the two points is " << point1.distance(&point2) << endl;
    return 0;
}