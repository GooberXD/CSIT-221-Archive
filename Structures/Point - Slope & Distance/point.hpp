#include <cmath>
#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x;
    int y;

    double distance(Point* other){
        int neg_x = this->x - other->x;
        int neg_y = this->y - other->y;
        int squarex = neg_x * neg_x;
        int squarey = neg_y * neg_y;
        int res = squarex + squarey;
        double answer = sqrt(res);
        return answer;
    }
    
    double slope(Point* other){
        return (double) (other->y - y) / (other -> x - x);
    }

};

typedef Point point;