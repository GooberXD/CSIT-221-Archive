#include <cstdlib>
#include <iostream>
#include "binarytree.hpp"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;

	node* create_node(int e, node* parent) {
	    
	    node* n = new node;
	    n->elem = e;
	    n->left = nullptr;
	    n->right = nullptr;
	    n->parent = parent;
	    
	    return n;
	}

	public:
	node* addRoot(int e) {
        // TODO this method
        if(root) throw logic_error("Already has root");
        
        root = create_node(e, root);
        size++;
		return root;
	}

	node* addLeft(node* p, int e) {
        // TODO this method
        
        if(p->left) throw logic_error(to_string(p->elem) + " already has left child");
        
        node* child = create_node(e, p);
        child->left = nullptr;
        child->right = nullptr;
        child->parent = p;
        
        p->left = child;
        size++;
		return child;
	}

	node* addRight(node* p, int e) {
        // TODO this method
        if(p->right) throw logic_error(to_string(p->elem) + " already has right child");
        
        node* child = create_node(e, p);
        child->left = nullptr;
        child->right = nullptr;
        child->parent = p;
        
        p->right = child;
        size++;
		return child;
	}

	public:
	node* left(node* n) {
		return n->left;
	}

	node* right(node* n) {
		return n->right;
	}
	
	node* sibling(node* n){
	    if(!n || !n->parent){
	        return nullptr;
	    }
	    
	    if(n->parent->left == n){
	        return n->parent->right;
	    }
	    else return n->parent->left;
	    
	    //
	    
	}
	
	int remove(node* n){
	    
	    int old = n->elem;
	    
	    if(n->left && n->right) throw logic_error("Cannot remove " + to_string(n->elem) 
	                                            + " for it has 2 children");
	    
	    node* child = n->left ? n->left : n->right; //sets child
	    
	    //no parent
	    if(!n->parent){
	        root = child;
	        if(child) child->parent = nullptr; //sets parent again
	        
	    }
	    
	    
	    else{
	        
	        if(n->parent->left == n) 
	            n->parent->left = child;  //if node's parent left == n,
	                                                                    
	        else n->parent->right = child;  //else sets node's parent right to the child
	        
	        if(child) 
	            child->parent = n->parent; //sets child parent to node's parent
	        
	    }
	    
	    
	    size--;
	   // delete n;
	    free(n);
	    return old;
	}

    int getSize() {
        return size;
    }

	node* getRoot() {
		return root;
	}
};