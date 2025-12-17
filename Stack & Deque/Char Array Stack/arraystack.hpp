// TODO implement the stack using the operations of Array List
#include "stack.hpp"
#include <cmath>
using namespace std;
class ArrayStack : public Stack {
    public:
    
    // char *arr;
    int cap = 5;
    int elem = 0;
    char *arr = new char[cap];
    // ArrayStack(){
        
    //     cap = 5;
    //     elem = 0;
    //     arr = new char[cap];
        
    // }
    
    
    void push(char c){
        if(elem == cap){
            int newCap = (int)ceil(cap * 1.5);
            
            if(newCap <= cap){
                newCap = cap + 1;
            }
            
            char *newArr = new char[newCap];
            
            for(int i = 0; i < elem; i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            cap = newCap;
            
        }
        arr[elem++] = c;
        
    }
	char pop(){
	    
	    if(isEmpty() == true){
	        return ' ';
	    }
	    
	    char popped = arr[elem - 1];
	    
	    if(elem < cap * .60){
	        int newCap = (int)floor(cap * 0.8);
	        
	        if(newCap < 5){
	            newCap = 5;
	        }
	        
	        if(newCap >= elem && newCap != cap){
	            char *newArr = new char[newCap];
	            for(int i = 0; i < elem; i++){
                    newArr[i] = arr[i];
                    
                }
	            delete[] arr;
                arr = newArr;
                cap = newCap;
	        }
	        
	    }
	    
	    elem--;
	    
	    return popped;
	    
	}
	char top(){
	    return arr[elem - 1];
	    
	}
	
	
	int size(){
	    return elem;
	    
	}
	bool isEmpty(){
	    
	    if(elem == 0){
	        return true;
	    }
	    
	    else {
	        return false;
	    }
	}
};