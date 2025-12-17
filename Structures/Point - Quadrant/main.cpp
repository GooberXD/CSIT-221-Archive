// In a 2-dimensional plane, a point is located on a quadrant 
// depending on the values of x and y.

// Quadrant 1 - x is positive, y is positive
// Quadrant 2 - x is negative, y is positive
// Quadrant 3 - x is negative, y is negative
// Quadrant 4 - x is positive, y is negative

// In the point.h file, create the int quadrant() method and return the quadrant of the point. 
// Note that if the point lies on the x- or the y- axis exclusively, 
// return -1 to indicate that it is lying on the axes. If the point is in the origin 
// (i.e. the point's coordinate is (0, 0) ), return 0 to indicate that it is in the origin.

#include <iostream>
#include "point.hpp"
using namespace std;

int main() {
    Point point1;
    cout << "Enter x of point: ";
    cin >> point1.x;
    cout << "Enter y of point: ";
    cin >> point1.y;

    int res = point1.quadrant();
    switch (res) {
        case 0:
            cout << endl << "The point is in the origin" << endl;
            break;
        case -1:
            cout << endl << "The point is in the axis" << endl;
            break;
        default:
            cout << endl << "The point belongs to Quadrant " << point1.quadrant() << endl;
    }
    return 0;
}