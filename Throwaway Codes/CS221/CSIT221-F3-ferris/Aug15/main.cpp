#include <iostream>
#include <bits/stdc++.h>
#include "arraylist.hpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List* list = new ArrayList();
	char op;
	int num, pos;
	do {
		printf("Op: ");
		scanf(" %c", &op);
		switch (op) {
			case 'a':
				cin >> num;
				list->add(num);
				break;
			case 'p':
				list->print();
				break;
			case 'g':
				cin >> pos;
				cout << "Element " << pos << ": " << list->get(pos) << endl;
				break;
			case 'x':
				cout << "Exiting...";
				break;
			default:
				cout << "Invalid operation" << endl;
		}
	} while (op != 'x');
	return 0;
}
