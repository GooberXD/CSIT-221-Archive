#include <bits/stdc++.h>
#include "entry.hpp"
using namespace std;

class Scoreboard {
	Entry board[5];
	int size = 0;
	
	public: 
	void add(Entry e){
		board[size++] = e;
	
	}	
	
	void print(){
		
		for(int i = 0; i < 5; i++){
			cout << (i + 1) << ". ";
			
			if(i < size){
				entry* e = &board[i];
				cout << e->name << "(" << e->country << ")- " << e->score << endl; 
			}
			
			else{
				printf("None\n");
			}
		}
		
	}
	
};
