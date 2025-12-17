// Array List
#include "list.hpp"
#include <iostream>
using namespace std;

class ArrayList : public List {
	private:
	int size = 0;
	int array[5];
	void add(int num) {
		if (size == 5) {
			cout << "Can't add anymore" << endl;
			return;
		}
		array[size++] = num;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " is index " << i << endl;
		}
	}
};
