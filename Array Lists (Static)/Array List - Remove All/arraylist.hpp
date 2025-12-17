#include <iostream>
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

    // TODO implement method removeAll here
    int removeAll(int num) {
        int ctr = 0;
        for(int i = 0; i < 5; i++){
            if(array[i] == num){
                
                
                array[i] = 0;
                i--;
                ctr++;
            }
        }
        
        for(int i = 0; i < 5 - 1; i++){
                    for(int j = 0; j < 5 - i - 1; j++){
                        if(array[j] == 0){
                            int temp = array[j + 1];
                            array[j + 1] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                
        if(ctr == 0){
            return 0;
        }
        
        else{
            return ctr;
        }
        
        
        
        // for(int i = 0; i < size;i++){
        //     if (array[i] == pos){
        //         ctr++;
        //         for(int j = i; j < size-1;j++){
        //             array[j] = array[j+1];
        //         }
        //         array[size-1] = 0;
        //         size = size-1;
                
        //         return i + 1;
        //     }
        // }
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};