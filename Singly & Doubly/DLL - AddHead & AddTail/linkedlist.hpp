#include "list.hpp"
#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;

public:
	void addFirst(int num) {
	    
	    node* n = (node*) calloc (1, sizeof(node));
	    n->elem = num;
	    n->next = head;
	    
	    if(head){
	        head->prev = n;
	    }
	    
	    head = n;
	    
	    if(!tail){
	        tail = n;
	    }
	    size++;
	    
	    
	    
	}
	void addLast(int num) {
	    
	   //node* n = (node*) calloc (1, sizeof(node));
	   // n->elem = num;
	    
	   // if(size == 0){
	   //     head = n;
	   //     tail = n;
	   // }
	    
	   // else{
	   //     tail->next = n;
	   //     tail = n;
	   // }
	   // size++;
	    
	    node* n = (node*) calloc (1, sizeof(node));
	    n->elem = num;
	    n->prev = tail;
	    
	    if(tail){
	        tail->next = n;
	    }
	    
	    tail = n;
	    
	    if(!head){
	        head = n;
	    }
	    size++;
	    
	    
	}

	void add(int num) {
		addLast(num);
	}

	int remove(int num) {
        // IGNORE for now
    	return 0;
	}

    // TODO implement method get here
	int get(int pos) {
        return 0;
	}

    void print() {
    	node* curr;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
			cout << "From HEAD: ";
    		curr = head;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != tail) {
	    			cout << " -> ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->next;
			}
			cout << "From TAIL: ";
    		curr = tail;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != head) {
	    			cout << " <- ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->prev;
			}
		}
    }
};