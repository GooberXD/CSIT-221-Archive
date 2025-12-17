#include <iostream>
#include "linkedlist.hpp"

int main() {
	LinkedList* list = new LinkedList();
    int input, res;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'f' :
		    	cin >> input;
		    	list->addFirst(input);
		    	break;
    		case 'l' :
		    	cin >> input;
		    	list->addLast(input);
		    	break;
    		case 'F' :
		    	res = list->removeFirst();
		    	if (res == -1) {
		    	    cout << "Nothing was removed." << endl;
		    	} else {
		    	    cout << "Removed " << res << endl;
		    	}
		    	break;
    		case 'L' :
		    	res = list->removeLast();
		    	if (res == -1) {
		    	    cout << "Nothing was removed." << endl;
		    	} else {
		    	    cout << "Removed " << res << endl;
		    	}
		    	break;
		    case 'p':
		    	list->print();
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		}
	} while (op != 'x');
    return 0;
}