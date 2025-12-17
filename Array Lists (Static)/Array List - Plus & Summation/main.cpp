// The List ADT has the following operations already implemented in class:

// void add(int num): Inserts num into the list.
// int get(int pos): Returns the integer in the _pos_th position.
 

// Your task is to implement the following operations:

// void plus(int term): Adds term to each of the existing elements of the list.
// int summation(): Returns the sum of all the elements of the list.

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
            case '+':
                cin >> num;
                list->plus(num);
                break;
            case 'p':
                list->print();
                break;
            case 's':
                cout << "Sum: " << list->summation() << endl;
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