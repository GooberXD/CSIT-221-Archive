#include <math.h>
#include <bits/stdc++.h>

struct Point {
    int x;
    int y;
    
    int quadrant(){
        if(x > 0 && y > 0){
            return 1;
        }
        if(x < 0 && y > 0){
            return 2;
        }
        if(x < 0 && y < 0){
            return 3;
        }
        if(x > 0 && y < 0){
            return 4;
        }
        
        if(x == 0 && y == 0){
            return 0;
        }
     
            return -1;
        
    }
    

};

typedef Point point;