#include "mybinarytree.hpp"
// #include "binarytree.hpp"
#include <bits/stdc++.h>

using namespace std;

class BST {
	BinaryTree* tree = new MyBinaryTree();
    int i;
	public:
	// TODO convert bst to heap
// void print() {
// 		cout << "Size: " << size << endl;
// 		if (!root) {
// 			cout << "EMPTY" << endl;
// 			return;
// 		}
// 		node* curr = root;
// 		print_node("", root, false);
//         cout << "Status: " << check_parent(root, NULL) << endl;
// 	}

// 	void print_node(string prefix, node* n, bool isLeft) {
// 		cout << prefix;
//         cout << (isLeft ? "+--L: " : "+--R: " );
//         cout << n->elem << endl;
// 		if (n->left) {
// 			print_node(prefix + "|   ", n->left, true);
// 		}
// 		if (n->right) {
// 			print_node(prefix + "|   ", n->right, false);
// 		}
// 	}

void inOrd(node* n, int* arr){
    if(n == nullptr){
        return;
    }
    
    inOrd(n->left, arr);
    arr[i++] = n->elem;
    inOrd(n->right, arr);
}

void preOrd(node* n, int* arr){
    if(n == nullptr){
        return;
    }
    
    n->elem = arr[i++];
    
    preOrd(n->left, arr);
    preOrd(n->right, arr);
}
	
	
	void convertToHeap() {
        
        // int sz = getSize();
        
        // int arr[sz];
        
        // for(int i = 0; i < sz; i++){
            
        // }
        
        // node* rooter = getRoot();
        // int actSz = rooter->elem;
        
        
        // node* newN = create_node(getRoot()->elem, NULL)
        // int arr[sz];
        
        // for(int i = 0; i < size - 1; i++){
        //     for(int j = 0; j < size - i - 1; j++){
        //         int tmp = arr[j];
        //         arr[j] = arr[j+1];
        //         arr[j+1] = tmp;
                
        //     }
        // }
        
        // int size = tree->getSize();
        // int* arr = (int*)calloc(,4);
        
        int arr[tree->getSize()];
        i = 0;
        inOrd(tree->getRoot(), arr);
        i = 0;
        
        preOrd(tree->getRoot(), arr);
	}
	
	

	// WARNING! Do not modify the codes below!
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

	bool insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			tree->addRoot(num);
		}
		return insert_node(n, num);
	}

	bool insert_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return false;
		}
		if (num > n->elem) {
			if (!n->right) {
				tree->addRight(n, num);
				return true;
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				tree->addLeft(n, num);
				return true;
			} else {
				return insert_node(n->left, num);
			}
		}
	}
	
	

    // IGNORE for now
    bool remove(int num) {
        return false;
    }

	void print() {
		tree->print();
	}
};