#include "entry.hpp"
#include <bits/stdc++.h>


class Scoreboard {
	entry board[5];
	int size;

	public:
	// TODO change this
	bool add(entry e) {
	    for(int i = 0; i < size; i++){
	        entry* exist = &board[i];
	        
	        if(e.score > exist->score){
	            for(int j = size ;j >= i + 1; j--){
	                if(j == 5){
	                    continue;
	                }
	                board[j] = board[j - 1];
	            }
	            board[i] = e;
	            if(size < 5){
	                size++;
	            }
	            return true;
	        }
	        
	    }
	    
	    
	    
	    
		if (size >= 5) {
			return false;
		}
		board[size++] = e;
		
		
		
// 		for(int i = 0; i < 5 - 1; i++){
// 		    entry c = board[i];
// 		    for(int j = 0; j < 5 - i - 1; j++){
// 		        if(board[j + 1] <= board[j]){
// 		            temp = board[j + 1];
// 		            board[j + 1] = board[j];
// 		            board[j] = temp;
// 		        } 
		        
		        
// 		    }
// 		}
		
		
		return true;
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            if (i >= size) {
                cout << i+1 << ". (none)" << endl;
            } else {
            	entry e = board[i];
                cout << i+1 << ". " << e.name << " (" << e.college << ")" << " - " << e.score << endl;
            }
        }
        cout << endl;
    }
};