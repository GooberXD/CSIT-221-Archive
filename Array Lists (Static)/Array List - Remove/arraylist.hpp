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

    // TODO implement method remove here
    int remove(int num){
        for(int i = 0; i < size;i++){
            if (array[i] == num){ //if array is equivalent to num
                
                for(int j = i; j < size - 1;j++){
                    array[j] = array[j+1];       //shifts
                }
                array[size - 1] = 0;   //sets offending to zero
                size = size - 1;
                
                return i + 1;
            }
        }
        
        return -1; //-1 if not found
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};