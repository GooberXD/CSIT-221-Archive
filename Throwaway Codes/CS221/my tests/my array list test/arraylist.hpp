#include <bits/stdc++.h>
#include "list.hpp"

class ArrayList : public List{

    private: 
    int arr[5];
    int size;

    void add(int){

    }
    int getPosValue(int pos){
        return arr[pos-1];
    }
    virtual void print(){
        for(int i = 0; i < size ; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

};