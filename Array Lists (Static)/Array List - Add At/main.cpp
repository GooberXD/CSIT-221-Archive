// The List ADT has the following operations already implemented in class:

// void add(int num): Inserts num into the list.
// int get(int pos): Returns the integer in the _pos_th position. 
 

// Your task is to implement the following operations:

// void addAt(int num, int pos): Inserts num as the _pos_th position in the list. 
// For this problem, assume that the value of pos will always be valid

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
            case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
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
