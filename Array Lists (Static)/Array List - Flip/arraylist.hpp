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

    // TODO implement method flip here
    void flip() {
        // for(int i = 0; i < 5 - 1; i++){
        //     for (int j = 0; j < 5 - i - 1; j++){
        //         if(array[j + 1] > array[j]){
        //             int temp = array[j + 1];
        //             array[j + 1] = array[j];
        //             array[j] = temp;
        //         }
        //     }
        // }
        
        // for(int i = 0; i < 5 - 1; i++){
        //             for(int j = 0; j < 5 - i - 1; j++){
        //                 if(array[j] == 0){
        //                     int temp = array[j + 1];
        //                     array[j + 1] = array[j];
        //                     array[j] = temp;
        //                 }
        //             }
        //         }
                
        int temp1 = array[0];
        int temp2 = array[1];
        int temp4 = array[3];
        int temp5 = array[4];
        
        array[0] = temp5;
        array[1] = temp4;
        array[3] = temp2;
        array[4] = temp1;
        
        for(int i = 0; i < 5 - 1; i++){
                    for(int j = 0; j < 5 - i - 1; j++){
                        if(array[j] == 0){
                            int temp = array[j + 1];
                            array[j + 1] = array[j];
                            array[j] = temp;
                        }
                    }
                }
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};