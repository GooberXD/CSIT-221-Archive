// The List ADT has the following operations already implemented in class:

// void add(int num): Inserts num into the list.
// int get(int pos): Returns the integer in the _pos_th position.
 

// Your task is to implement the following operations:

// int remove(int num): Removes the first occurence of the given 
// element num and returns its position to where it was removed from. 
// If the number to be removed does not exist, returns -1 instead.

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
                cin >> num;
                pos = list->remove(num);
                if (pos == -1) {
                    cout << "Number " << num << " does not exist." << endl;
                } else {
                    cout << "Removed element " << pos << endl;
                }

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