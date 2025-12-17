// Given a string containing only parentheses ('(', ')', '{', '}', '[', ']'), 
// write a program to determine if the input string has balanced parentheses. 
// You may only use the stack operations push, pop, top, size, and isEmpty to solve this problem.

// There are three reasons why a string is not considered as balanced:

// Mismatch. If the closing parenthesis does not match the most recent opening parenthesis, 
// then there is a mismatch and the string is not balanced. One such example is the string 
// "(]" to which the expected closing parenthesis after ( is ), not ].

// Lacks Closing. If the string ends abruptly when the opening parentheses are not closed yet,
// then the string lacks closing parentheses and the string is not balanced. 
// One such example is the string "([]" to which the opening parenthesis 
// ( has not been paired up to its closing parenthesis ).

// Lacks Opening. If the string encounters a closing parenthesis without an opening parenthesis, 
// then the string lacks opening parentheses and the string is not balanced. 
// One such example is the string "[]}" to which it encounters the parenthesis } 
// but without its prior opening parenthesis {.
 

// In the main.cpp file, implement the is_balanced_parentheses(string str), 
// given the str as the input string, and return the following values:

// Return 0 if the string has balanced parentheses.
// Return 1 if the string has mismatched parentheses.
// Return 2 if the string lacks closing parentheses.
// Return 3 if the string lacks opening parentheses.

#include<iostream>
#include<string>
// #include "arraystack.hpp" // Already implemented! Do not recreate!
using namespace std;

// TODO implement this method.
// Use the ArrayStack to perform the stack operations needed.
int is_balanced_parentheses(string str){
   Stack* stack = new ArrayStack();
    
   for(char c : str){
       
       if(c == '(' || c == '[' || c == '{'){
           stack->push(c); //to add as head
       }
       
       else if(c == ')' || c == ']' || c == '}'){
           
           if(stack->isEmpty()){
               delete stack;
               return 3; // no openings found
           }
           
           char top = stack->top(); //comp top to the added head
           
           if(c == ')' && top == '(' || c == ']' && top == '[' || 
              c == '}' && top == '{'){
               stack->pop(); //meaning they matched
           }
           
           else{
               delete stack;
               return 1; // mismatching as recent parant doesnt match prev
           }
       }
       
   } 
    
   
    
    
    if(stack->isEmpty() == false){
        delete stack;
        return 2; //no closing
    }
    
    return 0;
}

// WARNING! Do not modify this method.
// Doing so will nullify your score for this problem.

int main(){
    string str;
    cout << "Enter a string with parentheses: ";
    cin >> str;
    int res = is_balanced_parentheses(str);
    switch(res) {
        case 0:
            cout << "The parentheses are balanced!" << endl;
            break;
        case 1:
            cout << "The parentheses are not balanced due to mismatch!" << endl;
            break;
        case 2:
            cout << "The parentheses are not balanced due to missing closing parentheses!" << endl;
            break;
        case 3:
            cout << "The parentheses are not balanced due to missing opening parentheses!" << endl;
            break;
    }
    return 0;
}