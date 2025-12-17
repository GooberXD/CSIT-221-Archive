#include "node.hpp"
#include "arrayqueue.hpp"
#include <bits/stdc++.h>
using namespace std;
class BinaryTree {
	public:
	virtual node* left(node*) = 0;
	virtual node* right(node*) = 0;
	virtual node* addRoot(int e) = 0;
	virtual node* addLeft(node* p, int e) = 0;
	virtual node* addRight(node* p, int e) = 0;
	virtual node* getRoot() = 0;
	virtual void print() = 0;

	// TODO traversals using the above virtual methods already implemented, though hidden
	void preorder() {
        node* r = getRoot();
        function<void(node*)> visit = [&](node* n){
            if(n == nullptr){
                return;
            }
            
            cout<< n->elem << " ";
            visit(left(n));
            visit(right(n));
        };
        
        visit(r);
        // cout << endl;
        
	}
	void inorder() {
        node* r = getRoot();
        function<void(node*)> visit = [&](node* n){
            if(n == nullptr){
                return;
            }
            
            visit(left(n));
            cout<< n->elem << " ";
            visit(right(n));
        };
        
        visit(r);
        // cout << endl;
	}
	void postorder() {
        node* r = getRoot();
        function<void(node*)> visit = [&](node* n){
            if(n == nullptr){
                return;
            }
            
            visit(left(n));
            visit(right(n));
            cout<< n->elem << " ";
            
        };
        
        visit(r);
        // cout << endl;
	}
	void breadthfirst() {
        Queue* queue = new ArrayQueue();
        
        node* r = getRoot();
        
        queue->enqueue(r);
        
        while(!queue->isEmpty()){
            node* n = queue->dequeue();
            cout<< n->elem << " ";
            
            if(left(n) != nullptr){
                queue->enqueue(left(n));
            }
            if(right(n) != nullptr){
                queue->enqueue(right(n));
            }
        }
        // cout << endl;
        delete queue;
	}
};