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
            case 'a': // Add
                cin >> num;
                list->add(num);
                break;
            case '@': // Add At Position
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 'r': // Remove (First occurrence of value)
                cin >> num;
                cout << "Removed " << num << " at pos " << list->remove(num) << endl;
                break;
            case '-': // Remove At (Index) - using '-' as the command char
                cin >> pos;
                cout << "Removed val " << list->removeAt(pos) << " at pos " << pos << endl;
                break;
            case 'R': // Remove All (All occurrences of value)
                cin >> num;
                cout << "Removed " << list->removeAll(num) << " element/s" << endl;
                break;
            case 'g': // Get
                cin >> pos;
                cout << "Value: " << list->get(pos) << endl;
                break;
            case 'p': // Print
                list->print();
                break;
            case 'x': // Exit
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');
    
    delete list; // Cleanup
    return 0;
}