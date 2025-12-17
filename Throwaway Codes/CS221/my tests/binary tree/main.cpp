#include <iostream>
#include "mygentree.hpp"
using namespace std;

int main() {
    GenTree* tree = new MyGenTree();

    node* thirteen = nullptr;
    try {
        thirteen = tree->addRoot(13);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        node* ten = tree->addRoot(10);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        tree->addChild(thirteen, 8);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    tree->print();
    return 0;
}
