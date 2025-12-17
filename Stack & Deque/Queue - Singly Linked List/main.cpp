// Using the Singly Linked List implementation, create the SLLQueue class 
// inheriting the Queue class to implement the queue operations using a Singly Linked List.

// It is expected that the SLLQueue will have the same fields as a 
// regular Singly Linked List i.e. head, tail, and size, but the operations 
// are only limited to that of a queue's operation.

// When trying to return the first element when one does not exist, return 0 instead.

#include <iostream>
#include "sllqueue.hpp"
using namespace std;

int main() {
    Queue* queue = new SLLQueue();
    int input;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'e' :
		    	cin >> input;
		    	queue->enqueue(input);
		    	break;
		    case 'd':
		    	cout << "Removed " << queue->dequeue() << endl;
		    	break;
		    case 'f':
		    	cout << "First element: " << queue->first() << endl;
		    	break;
		    case 's':
		    	cout << "Size: " << queue->size() << endl;
		    	break;
		    case '?':
		    	cout << "Empty? " << queue->isEmpty() << endl;
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		    default:
		        cout << "Unknown operation" << endl;
		        break;
		}
	} while (op != 'x');
    return 0;
}