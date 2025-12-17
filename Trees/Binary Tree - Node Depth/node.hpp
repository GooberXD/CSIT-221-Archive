struct node {
	int elem;
	node* left;
	node* right;
	node* parent;

    // TODO implement this method
    int depth() {
        // int ctr = 0;
        
        // ctr = 1;
        
        // return ctr;
        
        if(!parent) return 0;
        
        else{
            return 1 + parent->depth();
        }
    }
    
    
    
    //     return help(this) - 1;
    // }
    
    
    // int help(node* parent){
        
    //     if(parent == nullptr){
    //         return 0;
    //     }
        
    //     int leftH = help(parent->left);
    //     int rightH = help(parent->right);
        
    //     return 1 + max(leftH, rightH);        
    // }
};