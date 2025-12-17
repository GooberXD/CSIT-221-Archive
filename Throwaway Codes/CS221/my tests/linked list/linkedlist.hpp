#include "list.hpp"
#include "node.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class LinkedList : public List {
    node *head, *tail;  
    public:
    LinkedList() {  //initializes head and tail
        head = NULL;
        tail = NULL;
    }

    void add(int num) {
        node* newNode = new node{num, NULL}; // init
        if (!head) {  //if its not the head
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int get(int pos) {
        node* curr = head; //first index head curr
        int  index = 0; //init index
        while (curr) {
            if (index == pos) return curr->data;  //if index same as pos return curr data
            curr = curr->next;   // move next
            index++;  //increase index
        }
    }

    
    int removeElement(int num) {
        if (!head) return -1; // empty list

        int pos = 0;

        // Case 1: head contains the value
        if (head->data == num) {
            node* temp = head;
            head = head->next;
            if (temp == tail) tail = NULL; // if only one node
            delete temp;
            return pos; // removed at position 0
        }

        // Case 2: find node before the target
        node* curr = head;
        pos = 0;
        while (curr->next && curr->next->data != num) {
            curr = curr->next;
            pos++;
        }

        // Not found
        if (!curr->next) return -1;

        // Found: remove it
        node* temp = curr->next;
        curr->next = temp->next;
        if (temp == tail) tail = curr; // update tail if needed
        delete temp;

        return pos + 1; // removed at next position
}

    void removeAt(int pos){
        if (!head) return;  // empty list

        if (pos == 0) {  // remove head
            node* temp = head; 
            head = head->next; 
            if (temp == tail) tail = NULL; // if only one element
            delete temp;
            return;
        }

        node* curr = head;
        int index = 0;

        // find node before the one we want to remove
        while (curr && index < pos - 1) {
            curr = curr->next;
            index++;
        }

        // if pos is out of range or next is null, used for cases if its beyond / out of range
        if (!curr || !curr->next) return;

        node* temp = curr->next;
        curr->next = temp->next;
        if (temp == tail) tail = curr; // if removing tail
        delete temp;
    }

    void addAt(int pos){

    }

    void print() {
        node* curr = head;  //initializes list first index
        while (curr) {
            cout << curr->data << " ";  // prints
            curr = curr->next;  //moves next
        }
        cout << endl;
    }

};