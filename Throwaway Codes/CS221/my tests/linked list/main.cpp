#include <bits/stdc++.h>
#include <iostream>
#include "linkedlist.hpp"

using namespace std;

int main(){
    List* list = new LinkedList();

    list->add(10);
    list->add(20);
    list->add(30);
    list->add(600);

    // cout << "List: ";
    // list->removeAt(2);
    // list->print();

    // cout << "Element at index 1: " << list->get(1) << endl;

    int op;

    do{
        printf("What op: ");
        scanf("%d", &op);

        switch(op){
            int num, pos;
            case 1:
                scanf("%d", &num);
                list->add(num);
                break;
            
            case 2:
                scanf("%d", &pos);
                printf("%d at %d\n", list->get(pos), pos);
                break;
        }
    }while(op != 0);

    list->print();

}