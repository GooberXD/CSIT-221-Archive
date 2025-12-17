#include <bits/stdc++.h>
// #include <algorithm.h>

using namespace std;

struct node {
	int elem;
	node* left;
	node* right;
	node* parent;

    // TODO implement this method
    int height() {
        // int ctr = 0;

        // return ctr;
        
        return help(this) - 1;
    }
    
    
    int help(node* parent){
        
        if(parent == nullptr){
            return 0;
        }
        
        int leftH = help(parent->left);
        int rightH = help(parent->right);
        
        return 1 + max(leftH, rightH);        
    }
    
    //  max(leftH, rightH)
    
};