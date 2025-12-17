// TODO implement the queue using the operations of Singly Linked List
#include <cstdlib>
#include "node.hpp"
#include "queue.hpp"


class SLLQueue : public Queue {
    
    Node* head = NULL;
    Node* tail = NULL;
    int ctr = 0;

    void enqueue(int num){
        Node* newNode = new Node;
        newNode->elem = num;
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        
        else{
            tail->next = newNode;
            tail = newNode;
        }
        
        ctr++;
        
    }
    
    
	int dequeue(){
	    if(head == NULL){
	        return 0;
	    }
	    
	    Node* removeHead = head;
	    int val = removeHead->elem;
	    
	    head = head->next;
	    delete removeHead;
        
        ctr--;
        
        if(head == NULL){
            tail = NULL;
        }
        
        return val;
	    
	}
	
	
	int first(){
	    
	    if(isEmpty() == true){
	        return 0;
	    }
	    
	    return head->elem;
	    
	}
	int size(){
	    return ctr;
	}
	bool isEmpty(){
	    if(ctr == 0){
	        return true;
	    }
	    
	    else{
	        return false;
	    }
	    
	}


};