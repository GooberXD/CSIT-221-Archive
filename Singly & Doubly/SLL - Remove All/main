#include <iostream>
#include "linkedlist.hpp"

int main() {
	List* list = new LinkedList();
    int input, num;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
		    case 'R':
                cin >> num;
                cout << "Removed " << list->removeAll(num) << " element/s" << endl;
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