#include "gentree.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

class MyGenTree : public GenTree {
	int size;
	node* root;

public:
	MyGenTree() {
		size = 0;
		root = nullptr;
	}

	//accessors
	node* left(node* p) {
		if (!p) return nullptr;
		return p->left;
	}

	node* right(node* p) {
		if (!p) return nullptr;
		return p->right;
	}

	node* sibling(node* p) {  //returns p sibling
		if (!p || !p->parent) return nullptr;
		if (p->parent->left == p)
			return p->parent->right;
		else
			return p->parent->left;
	}

	int set(node* p, int e){   //replace the existing node p value, pluh
		if(!p) throw invalid_argument("not a node pluh brrttt");

		int setted = p->elem;
		p->elem = e;
		return setted;
	}

	void attach(node* p, MyGenTree& T1, MyGenTree& T2){  //p is parent, t1 first tree, t2 second tree

		if(!p) throw invalid_argument("parent is null");

		if(p->left || p->right) throw logic_error("uhh it has children");

		if(T1.root){
			p->left = T1.root;
			T1.root->parent = p;
			size += T1.size;
			T1.root = nullptr;
			T1.size = 0;
		}

		if(T2.root){
			p->right = T2.root;
			T2.root->parent = p;
			size += T2.size;
			T2.root = nullptr;
			T2.size = 0;
		}

	}


	node* addRoot(int num) override {
		if (root)
			throw logic_error("Tree already has a root");
		
		root = new node;
		root->elem = num;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
		size++;
		return root;
	}

	node* addChild(node* p, int num) override {
		if (!p)
			throw invalid_argument("Parent is null");

		// follow binary tree rule: must have at most 2 children
		if (p->left && p->right)
			throw logic_error("Node already has two children");

		node* child = new node;
        
		child->elem = num;
		child->left = nullptr;
		child->right = nullptr;
		child->parent = p;

		// add to left first, then right
		if (!p->left)
			p->left = child;
		else
			p->right = child;

		size++;
		return child;
	}

	int remove(node* p) override {
		if (!p)
			throw invalid_argument("Node is null");

		// case: node has two children → cannot remove
		if (p->left && p->right)
			throw logic_error("Cannot remove node with two children");

		node* child;
			if (p->left)
				child = p->left;
			else
				child = p->right;

		if (p == root) {
			root = child;
			if (child) child->parent = nullptr;
		} 
		
		else {
			node* parent = p->parent;
			if (parent->left == p)
				parent->left = child;
			else
				parent->right = child;

			if (child)
				child->parent = parent;
		}

		int oldElem = p->elem;
		delete p;
		size--;
		return oldElem;
	}

	int getSize() override {
		return size;
	}

	node* getRoot() override {
		return root;
	}
};
