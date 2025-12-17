#include <cstdlib>
#include <iostream>
#include <stdexcept>
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
        
    //     node* n = new node;
	   // n->elem = e;
	   // n->left = nullptr;
	   // n->right = nullptr;
	   // n->parent = p;
        
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

    int getSize() {
        return size;
    }

	node* getRoot() {
		return root;
	}
};