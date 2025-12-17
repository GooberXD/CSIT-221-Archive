#include <cstdlib>
#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public List {
	node* head;
	node* tail;
	int size;

	public:
	void add(int num) {
		node* n = new node;
		n->elem = num;
		if (size == 0) {
			head = n;
		} else {
			tail->next = n;
		}
		tail = n;
		size++;
	}

    int get(int pos) {
        // IGNORE for now
        return 0;
    }

    int remove(int num) {
        // IGNORE
	}

    // TODO add the removeAt method
    int removeAt(int pos){
        

		
		if(pos > size) return -1;
		
		node* curr = head;
		node* prev;
		
		for(int i = 1; i < pos; i++){
		    prev = curr;
		    curr = curr-> next;
		}
		
		int num = curr->elem;
		
		if(curr == head){
		    head = head->next;
		}
		
		else{
		    if(curr == tail){
		        tail = prev;
		    }
		    prev->next = curr->next;
		}
		
		size--;
		return num;
    }
		
		
		
		
		
		
        
    
    
    
    		
// 		if(pos == size-1){
// 		    ret = curr-> elem;
// 		    delete tail;
// 		    return ret;
// 		}
		
// 		if(pos == 1){
// 		    ret = curr->elem;
// 		    delete head;
// 		    return ret;
// 		}
    

    // DO NOT modify the code below.
    void print() {
    	node* curr = head;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
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
		}
    }
};