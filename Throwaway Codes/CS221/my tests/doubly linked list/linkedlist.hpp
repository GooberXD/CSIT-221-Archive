#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public List {
    node* head;
    node* tail;
    int size;

public:
 
    int get(int pos) override {
        if (pos < 1 || pos > size) return -1;

        node* curr = head;
        int index = 1;
        while (curr) {
            if (index == pos) return curr->elem;
            curr = curr->next;
            index++;
        }
        return -1;
    }

    int remove(int num) override {
        node* curr = head;
        int ctr = 1;

        while (curr) {
            if (curr->elem == num) {
                if (curr == head) {
                    head = head->next;
                    if (head) head->prev = NULL;
                }
                else if (curr == tail) {
                    tail = tail->prev;
                    if (tail) tail->next = NULL;
                }
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                delete curr;
                size--;
                return ctr;
            }
            curr = curr->next;
            ctr++;
        }
        return -1;
    }

    void addAt(int num, int pos) override {
        if (pos <= 1) {
            addHead(num);
            return;
        }

        if (pos > size) {
            addTail(num);
            return;
        }

        node* curr = head;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }

        node* n = new node;
        n->elem = num;

        n->next = curr->next;
        n->prev = curr;

        if (curr->next) curr->next->prev = n;
        curr->next = n;

        size++;
    }

    void addHead(int num) {
        node* n = new node;
        n->elem = num;
        n->prev = nullptr;
        n->next = head;

        if (head) head->prev = n;
        head = n;

        if (size == 0) tail = n;
        size++;
    }

    void addTail(int num) {
        node* n = new node;
        n->elem = num;
        n->next = nullptr;
        n->prev = tail;

        if (tail) tail->next = n;
        else head = n;

        tail = n;
        size++;
    }

    void print() override {
        node* curr = head;
        if (size == 0) {
            cout << "Empty" << endl;
        } else {
            while (curr) {
                cout << curr->elem;
                if (curr != tail) cout << " <-> ";
                curr = curr->next;
            }
            cout << endl;
        }


    }


    ~LinkedList(){
        while(head){
            node *curr = head;
            head = head->next;
            delete curr;
        }
    }
};
