// ArrayList
#include "list.hpp"
#include <iostream>
using namespace std;

class ArrayList : public List {
	private:
	int array[5];
	int size;
	
	void add(int num) {
		if (size < 5) {
			array[size++] = num;
		} else {
			cout << "Array full" << endl;
		}
	}
	
	int get(int pos) {
		return array[pos-1];
	}
	
	void print() {
		for (int i = 0; i < 5; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
