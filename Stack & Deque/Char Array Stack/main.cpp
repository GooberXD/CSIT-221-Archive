// Using the Array List implementation, create the ArrayStack class 
// inheriting the Stack class to implement the stack operations
// using an Array List of characters.

// It is expected that the ArrayStack will have the same fields as a 
// regular Array List i.e. a dynamic array, cap (starting with 5), and size,
// but the operations are only limited to that of a stack's operation.

// When trying to return the top element when one does not exist, 
// return a space character instead.

// Make sure that the appropriate dynamic resizing is considered such 
// that when the array gets full, it will increase the capacity to 50% rounded up. 
// So when the array of capacity 5 gets full, it will resize the array to accommodate 8. 
// When the array also reaches 60% of its capacity or less, resize the capacity to 
// 80% rounded down of its original capacity, but maintain a minimum capacity of 5. 
// For example, if the array of capacity 12 has reached a size of 7, resize the array to 
// have a reduced capacity of 9.

#include <iostream>
#include "arraystack.hpp"
using namespace std;

int main() {
    Stack* stack = new ArrayStack();
    char input;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	stack->push(input);
		    	break;
		    case 'r':
		    	cout << "Removed " << stack->pop() << endl;
		    	break;
		    case 't':
		    	cout << "Last element: " << stack->top() << endl;
		    	break;
		    case 's':
		    	cout << "Size: " << stack->size() << endl;
		    	break;
		    case '?':
		    	cout << "Empty? " << stack->isEmpty() << endl;
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		    default:
		        cout << "Unknown operation." << endl;
		}
	} while (op != 'x');
    return 0;
}