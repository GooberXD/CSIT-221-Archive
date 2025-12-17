#include "entry.hpp"
#include "hidden.hpp"
#include <bits/stdc++.h>
#include <cstring>
class Scoreboard {
	entry board[5];
	int size;

	public:
	bool add(entry e) {
		return hidden_add(e, board, &size);
    }

    // TODO add method removeLower here
    int removeLower(int score) {

        for(int i = 0; i < size; i++){
	        entry* exist = &board[i];
	        
	        if(exist->score < score){
	            int diff = size - i;
	            size = i;
	            return diff;
	            }
	            
	        }
	        return 0;
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