// One technique to compress files is to group together repetitive strings. 
// Example, when a file contains the string "aaaabcbcbc", 
// it can be compressed to "4[a]3[bc]" where it follows the syntax n[str] 
// where n defines the number of repetitions of str.
 
// A complex example is "3[a2[c]]" that is decoded as "accaccacc".

// Given an encoded string, output its decoded equivalent.
// Assume that the numbers are only single-digit numbers.

// You can use the built-in stack<T> class from the "stack.h" library as your stack. 
// T is a generic type that you are to specify for the data type of your stack e.g.,

// stack<string> strstack; 

// and use the dot notation to access its methods i.e., strstack.push(num), strstack.pop(), 
// strstack.top(), strstack.empty(), strstack.size(). 
// The only difference is the pop()method returns void, 
// so in order to get the last element, use the top() method first, before using pop()

#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Use stack<T> here to use a generic stack, replace T with your data type
    // e.g., stack<string> strstack;
    // use strstack.push(num), strstack.pop(), strstack.top(), strstack.empty(), strstack.size()
    
    string s;
    
    printf("Enter encoded string: ");
    cin >> s;
    
    stack<int> n;
    stack<string> strstack;
    
    string curr = "";
    
    for(char c : s){
        
        if(isdigit(c)){
            n.push(c - '0');  //we push it as number
        }
        
        else if(c == '['){
            strstack.push(curr);   // save curr string
            curr = "";            //res
        }
        
        else if(c == ']'){
            
            int rep = n.top();
            n.pop();
            
            string previous = strstack.top();
            strstack.pop();
           
            string temp = "";
            
            for(int i = 0; i < rep; i++){
                temp += curr;
            }
            
            curr = previous + temp;
        }
        
        else{
            curr += c;
        }
        
    }
        
    cout << "Result: " << curr;
    return 0;
}