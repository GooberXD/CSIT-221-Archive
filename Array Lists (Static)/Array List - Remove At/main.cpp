// The List ADT has the following operations already implemented in class:

// void add(int num): Inserts num into the list.
// int get(int pos): Returns the integer in the _pos_th position.
 

// Your task is to implement the following operations:

// int removeAt(int pos): Removes the element at the _pos_th position. 
// For this problem, assume that there is an element in the _pos_th position. 
// This returns the removed element.

#include <iostream>
#include "arraylist.hpp"
using namespace std;

int main() {
    List* list = new ArrayList();
    char ch;
    int num, pos;
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'a':
                cin >> num;
                list->add(num);
                break;
            case 'r':
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');
    return 0;
}