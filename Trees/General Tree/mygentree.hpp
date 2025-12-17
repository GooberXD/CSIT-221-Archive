// Create a class MyGenTree, a subclass of GenTree
#include <bits/stdc++.h>
#include <stdexcept>
#include "gentree.hpp"
#include "node.hpp"

class MyGenTree : public GenTree {
    private:
        node* root;
        int size;
        
    public: 
    MyGenTree(){
        size = 0;
        root = nullptr;
    };
    
    
    node* addRoot(int n){
        if(root != nullptr){
            throw logic_error("Already has root");
        }
        
        root = new node();
        root->elem = n;
        root->parent = nullptr;
        root->num_child = 0;
        root->children = (node**)malloc(10 * sizeof(node*));
 
             for(int i = 0; i < 10; i++){
                root->children[i] = nullptr;
            }
            
        size++;
        return root;
    }
    
    node* addChild(node* parent, int chi){
        
        node* child = (node*)malloc(sizeof(node));
        
        child->elem = chi;
        child->parent = parent;
        child->num_child = 0;
        child->children = (node**)malloc(10 * sizeof(node*));
        
            for(int i = 0; i < 10; i++){
                child->children[i] = nullptr;
            }
        
        parent->children[parent->num_child++] = child;
        
        size++;
        
        return child;
        
    }
    
    void remove(node* n){
        
        if(n == NULL){
            return;
        }
        
        if(n->num_child > 0){
            printf("%d has children\n", n->elem);
            return;
        }
        
        if(n == root){
            free(n->children);
            free(n);
            root = nullptr;
            size = 0;
            return;
        }
        
        node* sh = n->parent;
        
        if(sh != nullptr){
            //for shifting por
            for(int i = 0; i < sh->num_child; i++){
                
                if(sh->children[i] == n){
                    
                    for(int j = i; j < sh->num_child; j++){
                        sh->children[j] = sh->children[j + 1];  //4 das shift ja, ze thin
                    }
                    sh->children[sh->num_child - 1] = nullptr;
                    sh->num_child--;
                    break;
                    
                }
                
            }
        }
        
        //to free
        free(n->children);
        free(n);
        size--;
        
    }
    
    int getSize(){
        return size;
    }
    
	node* getRoot(){
	    return root;
	}
	
	
	void preorder(node* n) {
        if (!n) return;
        
        cout << n->elem << " ";
        for (int i = 0; i < n->num_child; i++)
        preorder(n->children[i]);
    }

    void postorder(node* n) {
        if (!n) return;
        
        for (int i = 0; i < n->num_child; i++)
        postorder(n->children[i]);
        cout << n->elem << " ";
    }

    node* DFS(node* n, int target) {
        if (!n) return nullptr;
        if (n->elem == target) return n;
        for (int i = 0; i < n->num_child; i++) {
            node* found = DFS(n->children[i], target);
            if (found) return found;
        }
        return nullptr;
    }
    
    
    
};