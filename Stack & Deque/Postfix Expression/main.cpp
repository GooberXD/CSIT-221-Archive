// Postfix expressions are mathematical expressions derived from 
// expression trees that is obtained using the post-order traversal.

// In order to evaluate a postfix expression, we perform the following:

// Read the expression one character at a time.
// If the current symbol is an operand (e.g. numerical), push it onto a stack.
// If the current symbol is an operator (+,-,*,/), pop two operands from the stack. 
// Call the operands a and b respectively.
// Evaluate the operation b op a.
// Push the result back onto the stack.
// Repeat the above steps until the end of the expression is reached.
// At the end, the stack should have only one number, 
// which is the result of the entire postfix expression. 
// This will be printed when the user exits the program via the 'x' input.

// In the main.cpp file, the code to handle the numerical inputs and the 
// case of addition has been done. Your task is to complete the 
// other operations namely subtraction (-), multiplication (*), and division (/).

// TIP: To convert a string s to an integer, we use the function stoi(s) 
// (or string to int) from cstdlib library and it will return the integer 
// value of that string s.

#include <iostream>
#include <string>
#include <bits/stdc++.h>
// #include "arraystack.hpp" // ALREADY IMPLEMENTED
using namespace std;

int main() {
	Stack* stack = new ArrayStack();
    string input;
    do {
    	cout << "Enter: ";
    	cin >> input;

    	// TODO classify whether input is
    	// operator i.e. + * / -
    	// numeric
    	// or x to output "Answer is " + answer
    	
    	if(input == "+"){
    	    int a = stack->pop();
    	    int b = stack->pop();
    	    stack->push(b + a);
    	}
    	
    	else if(input == "-"){
    	    int a = stack->pop();
    	    int b = stack->pop();
    	    stack->push(b - a);
    	}
    	
    	else if(input == "*"){
    	    int a = stack->pop();
    	    int b = stack->pop();
    	    stack->push(b * a);
    	}
    	else if(input == "/"){
    	    int a = stack->pop();
    	    int b = stack->pop();
    	    stack->push(b / a);
    	}
    	
    	else if(input != "x"){
    	    int n = stoi(input);
    	    stack->push(n);
    	}
    	

	} while (input != "x");
	
	int res = stack->pop();
	
	printf("Answer is %d", res);
	
    return 0;
}