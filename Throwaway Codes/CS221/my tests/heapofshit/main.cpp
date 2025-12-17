#include <bits/stdc++.h>
#include "heap.hpp"
using namespace std;


int main() {
    Heap* heap = new Heap();
    int n;
    char op;

    do {
        cout << "Options (a-add, r-remove, p-print, x-exit)\nEnter option: ";
        cin >> op;

        switch (op) {
            case 'a':
                cout << "Add Element: ";
                cin >> n;
                heap->add(n);
                break;
            case 'r': {
                int removed = heap->remove();
                if (removed == -1) {
                    cout << "Heap is empty" << endl;
                } else {
                    cout << "Removed Element: " << removed << endl;
                }
                break;
            }
            case 'p':
                cout << "Heap: ";
                heap->print();
                break;
            case 'x':
                cout << "Terminate Program!" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    } while (op != 'x');

    delete heap;
    return 0;
}