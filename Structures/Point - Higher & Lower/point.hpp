#include <math.h>
#include <bits/stdc++.h>

struct Point {
    int x;
    int y;

    Point* higher (Point* other){
        
        
        if(this->y > other->y){
            return this;
        }
        
        else{
            return other;
        }
        
        // return res;
        
    }
    
    Point* further (Point* other){
        
        
        
        if(abs(this->x) > abs(other->x)){
            return this;
        }
        
        else{
            return other;
        }
        
        
    }
    
    // Point slope(Point* other){
    //     return (double) (other->y - y) / (other -> x - x);
    // }

};

typedef Point point;