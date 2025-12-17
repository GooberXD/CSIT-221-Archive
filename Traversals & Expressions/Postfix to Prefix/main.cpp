#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "arraystack.h"
using namespace std;

int main() {
	Stack* stack = new ArrayStack();
	string input;
	while(true){
	    printf("Enter: ");
	    cin >> input;
	    
	    if(input == "x") break;
	    
	    if(input == "+" || input == "-" || input == "*" || input == "/"){
	        string a = stack->pop();
	        
	        string b = stack->pop();
	        
	        string fin = input + " " + b + " " + a;
	        
	        stack->push(fin);
	    }   
	    
	    else{
	        stack->push(input);
	    }
	}
	
	cout << "Prefix: " << stack->pop() << endl;
	

    return 0;
}