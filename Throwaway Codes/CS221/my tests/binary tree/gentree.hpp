#include "node.hpp"
#include <iostream>
using namespace std;
class GenTree {
	void print_node(string prefix, node* n) {
	cout << prefix << "+--> " << n->elem << endl;
	if (n->left) print_node(prefix + "|   ", n->left);
    
	if (n->right) print_node(prefix + "|   ", n->right);
    }
	
	public:
	virtual node* addRoot(int) = 0;
	virtual node* addChild(node*, int) = 0;
	virtual int remove(node*) = 0;
	virtual int getSize() = 0;
	virtual node* getRoot() = 0;
	
	void print() {
		cout << "SIZE: " << getSize() << endl;
		if (!getRoot()) {
			cout << "EMPTY" << endl;
			return;
		}
		print_node("", getRoot());
	}
};