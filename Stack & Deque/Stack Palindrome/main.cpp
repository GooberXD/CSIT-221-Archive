#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "arraystack.hpp"
using namespace std;

// TODO implement this method.
// Use the ArrayStack to perform the stack operations needed.
//only part i modified in this entire thing
bool is_palindrome(string str){
    
    stack <char> s;
    
    for(char c : str){
        s.push(c);
    }
    
    for(char c: str){
        if(c != s.top()){
            return false;
        }
        s.pop();
    }
    
    
    
    return true;
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if(is_palindrome(str)) {
        cout << "The string is a palindrome!" << endl;
    } else {
        cout << "The string is not a palindrome!" << endl;
    }
    return 0;
}