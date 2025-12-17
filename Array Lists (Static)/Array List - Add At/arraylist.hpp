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

    // TODO implement method addAt here
    void addAt(int num, int pos){
        for(int j = size; j >= pos; j--){
            if(j == 5){
                continue;
            }
            array[j] = array [j - 1];
        }
        
        array[pos-1] = num;
        size = size + 1;
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};