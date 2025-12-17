#include <iostream>
#include <cstdlib>
#include <cmath>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    int* array;
    int size;
    int capacity = 5;

    //Helper for cap expansion
    void expand() {
         // Capacity * 1.5 logic
        int newCap = (capacity * 3 + 1) / 2;
        int* newArr = new int[newCap];

        for(int i = 0; i < size; i++){
            newArr[i] = array[i];
        }

        if (array) delete[] array;
        array = newArr;
        capacity = newCap;
    }

    // Helper for cap shrinkage
    void dynamic_deduce(){
        if(size <= floor((3.0 * capacity) / 4.0)){ // If size is 75% or less of cap
            int reduce = floor(capacity * 0.2); // Reduce by 20%
            int newCap = capacity - reduce; 
            
            if(newCap < 5){
                newCap = 5;
            }
            
            if(newCap < capacity){
                int* newArray = new int[newCap];
                for(int k = 0; k < size; k++){
                    newArray[k] = array[k];
                }
                
                if (array) delete[] array;
                array = newArray;
                capacity = newCap;
            }
        }
    }

    public:
    // Constructor
    ArrayList() {
        size = 0;
        capacity = 5;
        // Using new instead of calloc to match the delete[] used elsewhere
        array = new int[capacity]; 
    }

    // Destructor to prevent memory leaks
    ~ArrayList() {
        if (array) delete[] array;
    }

    void add(int num) {
        if(size == capacity){
            expand();
        }
        array[size++] = num;
    }

    void addAt(int num, int pos){
        // Check if pos is valid. 
        // We can only add at positions 1 through size + 1 (appending).
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position" << endl; // print error
            return; // Stop the function
        }

        if(size == capacity){
            expand();
        }
        
        // Shift elements to the right
        for(int i = size; i >= pos; i--){
            array[i] = array[i - 1];
        }
        
        array[pos - 1] = num;
        size++;
    }

    int remove(int num) {
        for (int i = 0; i < size; i++){
            if(array[i] == num){
                int posi = i;
                
                // Shift elements to the left
                for(int j = i; j < size - 1; j++){
                    array[j] = array[j + 1];
                }
                size--;
                
                // Check if we need to shrink
                dynamic_deduce();
                
                return posi + 1; // Return 1-based index
            }
        }
        return -1;
    }

    int removeAt(int pos) {
        if (pos < 1 || pos > size) return -1; // Basic bounds check

        int removeVal = array[pos - 1]; 
        
        // Shift elements to the left
        for(int i = pos - 1; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        size--;
        
        dynamic_deduce();
        return removeVal;
    }

    int removeAll(int num){
        int ctr = 0;
        int newSize = 0;
        
        // Filter array in-place
        for(int i = 0; i < size; i++){
            if(array[i] != num){
                array[newSize++] = array[i];   
            }
            else{
                ctr++;
            }
        }
        
        size = newSize;
        dynamic_deduce();
        return ctr;
    }

    int get(int pos) {
        if (pos < 1 || pos > size) return -1;
        return array[pos-1];
    }

    void print() {
        cout << "Size: " << size << "/" << capacity << endl;
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