// TODO create struct Rectangle here, with the methods area() and perimeter()
#include <bits/stdc++.h>
#include "point.hpp"

struct Rectangle {
    Point p1, p2;

    int area() {
        return abs(p1.x - p2.x) * abs(p1.y - p2.y);
    }

    int perimeter() {
        return 2 * (abs(p1.x - p2.x) + abs(p1.y - p2.y));
    }
};