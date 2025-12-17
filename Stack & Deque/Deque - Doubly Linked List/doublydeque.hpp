// TODO implement DoublyDeque as a subclass of Deque
#include "Node.h"
#include "deque.h"
#include <bits/stdc++.h>
using namespace std;
class DoublyDeque : public Deque{
    node head;
    node tail;
    int ctr;
    
    public:
    DoublyDeque(){
        head.next = &tail;
        tail.prev = &head;
        int ctr = 0;
    };
    
    
    node* gen(int num, node* pred, node* succ){
        node* n = new node;
        n->data = num;
        n->prev = pred;
        n->next = succ;
        
        pred->next = n;
        succ->prev = n;
        
        ctr++;
        return n;
        
    }
    
    void addFirst(int n){
        gen(n, tail.prev, &tail);
    }
    
    void addLast(int n){
        gen(n, &head, head.next);
    }
    
    int remGen(node* n){
        
        node* pred = n->prev;
        node* succ = n->next;
        
        pred->next = succ;
        succ->prev = pred;
        
        ctr--;
        
        int res = n->data;
        delete n;
        return res;
        
    }
    
    int removeFirst(){
        if(isEmpty()){
            return -1;
        }
        
        return remGen(tail.prev);
    }
    
    int removeLast(){
        if(isEmpty()){
            return -1;
        }
        
        return remGen(head.next);
    }
    
    
    bool isEmpty(){
        if (ctr == 0){
            return true;
        }
        
        else{
            return false;
        }
    }
    
    int size(){
        return ctr;
    }
    
    void print(){
        if(isEmpty()){
            printf("Empty\n");
            return;
        }
        
        printf("From HEAD: ");
        
        node* curr = tail.prev;
        
        while(curr != &head){
            printf("%d ", curr->data);
            
            if(curr->prev != &head){
                printf("-> ");
            }
            
            curr = curr->prev;
        }
        
        cout << endl;
        
        printf("From TAIL: ");
        
        node* cur = head.next;
        
        while(cur != &tail){
            printf("%d ", cur->data);
            
            if(cur->next != &tail){
                printf("<- ");
            }
            
            cur = cur->next;
        }
        
        cout << endl;
        
    }
    
    
    // virtual void addFirst(int) = 0;
    // virtual void addLast(int) = 0;
    // virtual int removeFirst() = 0;
    // virtual int removeLast() = 0;
    // virtual bool isEmpty() = 0;
    // virtual int size() = 0;
    // virtual void print() = 0;
};