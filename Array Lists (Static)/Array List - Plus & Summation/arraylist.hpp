#include <iostream>
#include <bits/stdc++.h>

#include "list.hpp"
using namespace std;

class ArrayList : public List {
    int array[5];
    int size;

    public:
    void add(int num) {
        if (size < 5) {
            array[size++] = num;
        } else {
            cout << "Array full" << endl;
        }
    }

    int get(int pos) {
        return array[pos-1];
    }

    // TODO implement method plus & summation here
    void plus(int num){
        // int array[5];
        for(int i = 0; i < size; i++){
            array[i] += num;
        }
    }
    
    int summation(){
        int sum = 0;
        
        for(int i = 0; i < size; i++){
            sum += array[i];
        }
        return sum;
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};