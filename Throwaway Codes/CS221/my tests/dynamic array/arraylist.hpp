#include <iostream>
#include <cstdlib>
#include <cmath>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    int* array;
    int size;
    int capacity = 5;

    public:
    // constructor
    ArrayList() {
    	array = (int*) calloc( capacity, sizeof(int) );
        // size = 0;
    }

    void add(int num) {
        if(size == capacity){
            int newCap = (capacity * 3 + 1) / 2;
            
            int* newArr = new int[newCap];
            
            for(int i = 0; i < size; i++){
                newArr[i] = array[i];
            }
            
            delete[] array;
            array = newArr;
            capacity = newCap;
        }
        array[size++] = num;
    }

    int remove(int num) {
        for (int i = 0; i < size; i++){
            if(array[i] == num){
                int posi = i;
                
                for(int j = i; j < size - 1; j++){
                    array[j] = array[j + 1];
                }
                size--;
                
                if(size <= (2 * capacity) / 3){
                    int newCap = ceil((capacity * 3) / 4.0);
                    
                    if(newCap < 5){
                        newCap = 5;
                    }
                    
                    int* newArray = new int[newCap];
                    for(int k = 0; k < size; k++){
                        newArray[k] = array[k];
                    }
                    delete[] array;
                    array = newArray;
                    capacity = newCap;
                }
                return posi + 1;
            }
        }
        return -1;
    }

    int get(int pos) {
        return array[pos-1];
    }

    void addAt(int num, int pos){
        
        if(size == capacity){
            int newCap = (capacity * 3 + 1) / 2;
            
            int* newArr = new int[newCap];
            
            for(int i = 0; i < size; i++){
                newArr[i] = array[i];
            }
            
            delete[] array;
            array = newArr;
            capacity = newCap;
        }
        
        for(int i = size; i >= pos; i--){
            array[i] = array[i - 1];
        }
        
        array[pos - 1] = num;
        size++;
        
    }
    
    int removeAt(int pos){
        int removeVal = array[pos - 1]; // finds removal of array val at pos
        
        for(int i = pos - 1; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        size--;
                
        if(size <= (2 * capacity) / 3){
            int newCap = ceil((capacity * 3) / 4.0); //resize 25% down
                    
            if(newCap < 5){
                newCap = 5;
            }
            
            if(newCap < capacity){
                int* newArray = new int[newCap];
                for(int k = 0; k < size; k++){
                    newArray[k] = array[k];
                }
                
                delete[] array;
                array = newArray;
                capacity = newCap;
            }
            
        }
        return removeVal;
    }
    
    int removeAll(int num){
        int ctr = 0;
        int newSize = 0;
        
        for(int i = 0; i < size; i++){
            if(array[i] != num){
                array[newSize++] = array[i];   
            }
            
            else{
                ctr++;
            }
        }
        
        
        size = newSize;
        dynamic_deduce(); // calls dynamic deduce to remove offending
        return ctr;
        
    }
    
    void dynamic_deduce(){
        if(size <= floor((3.0 * capacity) / 4.0)){  //3/4 capacity
            int reduce = floor(capacity * 0.2);
            int newCap = capacity - reduce; // 20% round down
            
            if(newCap < 5){
                newCap = 5;  //to enforce a 5 capacity minimum
            }
            
            if(newCap < capacity){
                int* newArray = new int[newCap];
                for(int k = 0; k < size; k++){
                    newArray[k] = array[k];
                }
                
                delete[] array;
                array = newArray;
                capacity = newCap;
            }
        }
    }


    //for printing
    void print() {
        int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
        }
        cout << endl;
    }
};


//testtest reduce

// if(size <= (2 * capacity) / 3){
//     int newCap = ceil((capacity * 3) / 4.0);
    
//     if(newCap < 5){
//         newCap = 5;
//     }
    
//     int* newArray = new int[newCap];
//     for(int k = 0; k < size; k++){
//         newArray[k] = array[k];
//     }
//     delete[] array;
//     array = newArray;
//     capacity = newCap;
// }


// //rect

// struct Point {
//     int x;
//     int y;
// };

// typedef Point point;

// #include <iostream>
// #include <bits/stdc++.h>
// #include "rectangle.hpp"
// using namespace std;

// int main() {
//     Rectangle rect;

//     cout << "Enter x of rectangle point 1: ";
//     cin >> rect.p1.x;
//     cout << "Enter y of rectangle point 1: ";
//     cin >> rect.p1.y;
//     cout << "Enter x of rectang le point 2: ";
//     cin >> rect.p2.x;
//     cout << "Enter y of rectangle point 2: ";
//     cin >> rect.p2.y;

//     cout << endl << "Perimeter of the rectangle: " << rect.perimeter();
//     cout << endl << "Area of the rectangle: " << rect.area() << endl;

//     return 0;
// }


// #include <bits/stdc++.h>
// #include "point.hpp"

// struct Rectangle {
//     Point p1, p2;

//     int area() {
//         return abs(p1.x - p2.x) * abs(p1.y - p2.y);
//     }

//     int perimeter() {
//         return 2 * (abs(p1.x - p2.x) + abs(p1.y - p2.y));
//     }
// };