#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
// #include <algorithm.h>
#include "minheap.hpp"
using namespace std;

class ArrayMinHeap : public MinHeap {
    int* array;
    int size;
    int capacity = 5;
    
    int parent(int n){
        return ceil(n / 2.0) - 1;
    }

	int left(int n) {
        // TODO return the index of the left child of n
        return (2 * n) + 1;
        
	}

	int right(int n) {
        // TODO return the index of the right child of n
        return (2 * n) + 2;
        
	}

    public:
    ArrayMinHeap() {
    	// TODO perform memory allocation for array with initial capacity 5
    	size = 0;
    	array = (int*) calloc(capacity, sizeof(int));
    	
	}

    // TODO insert the num into the heap
	void insert(int num) {

        if(size >= capacity){
            capacity = ceil(capacity * 1.5);
            array = (int*) realloc(array, capacity * sizeof(int));
        }
        array[size++] = num;
        heapUp(size - 1);
        
        
        return;
	}
	
	void heapUp(int n){
	    while(n > 0 && array[n] < array[parent(n)]){
	        
	        swap(array[n], array[parent(n)]);
	        
	        n = parent(n);
	    }
	    
	}
	
    // TODO remove the minimum value, -1 if empty
	int removeMin() {
	    if(size == 0) return -1;
	    int min = array[0];
	    array[0] = array[--size];
	    
	    int oneforth = ceil(capacity * (3.0 / 4));
	    
	    
	    if(size < oneforth){
	      
	        int newCap = ceil(capacity * 0.8);
	        
	        if(newCap <= 5){
	            newCap = 5;
	        }
	        
	        capacity = newCap;
	        array = (int*) realloc(array, capacity * sizeof(int));
	    }
	    
	    if(size != 0){
	        heapDowner(0);
	    }

		return min;
		
	}
	
	void heapDowner(int n){
	   while(true){
	       int s = n;
	       int l = left(n);
	       int r = right(n);
	       
	       if(l < size && array[l] < array[s])
	            s = l;
	       if(r < size && array[r] < array[s])
	            s = r;
	            
	       if(s != n){
	           swap(array[n], array[s]);
	           n = s; 
	           //free(n);
	       }
	       
	       else{
	           break;
	       }
	   }                                      
	}

    // DO NOT modify the code below
	void print() {
		if (size == 0) {
			cout << "EMPTY" << endl;
			return;
		}
			cout << "Size: " << size << "/" << capacity << endl;
			cout << "TREE: " << endl;
			print_tree("", 0, false);

		cout << "ARRAY: ";
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void print_tree(string prefix, int n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << array[n] << endl;
		if (left(n) < size) {
			print_tree(prefix + "|   ", left(n), true);
		}
		if (right(n) < size) {
			print_tree(prefix + "|   ", right(n), false);
		}
	}
};