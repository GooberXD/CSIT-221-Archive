#pragma once
#include <cstdlib>
#include <stdexcept>

using namespace std;

struct node {
	node **children;
	node *parent;
	int num_child;
	int elem;

    int depth() {
		// TODO implementation [+10 pts]
		if (parent == nullptr){
		    return 0;
		}
		
        return 1 + parent->depth();
	}
	


    int height() {
		// TODO implementation [+15 pts]
		if(num_child == 0){
		    return 0;
		}
		
		int maxChildHeight = 0;
		
		for(int i = 0; i < num_child; i++){
		    
		    int tmp = children[i]->height();
		    
		    if(tmp > maxChildHeight){
		        maxChildHeight = tmp;
		    }

		}
		
		return 1 + maxChildHeight;
    }
};