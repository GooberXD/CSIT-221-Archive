#include <bits/stdc++.h>
#include <iostream>
#include "linkedlist.hpp"

using namespace std;

int main(){
    List* list = new LinkedList();

    list->addHead(10);
    list->addHead(20);
    list->addHead(30);
    list->addHead(600);
    list->print();
    // cout << "List: ";
    // list->removeAt(2);
    // list->print();

    // cout << "Element at index 1: " << list->get(1) << endl;











    
    // int op;

    // do{
    //     printf("What op: ");
    //     scanf("%d", &op);

    //     switch(op){
    //         int num, pos;
    //         case 1:
    //             scanf("%d", &num);
    //             list->add(num);
    //             break;
            
    //         case 2:
    //             scanf("%d", &pos);
    //             printf("%d at %d\n", list->get(pos), pos);
    //             break;
    //     }
    // }while(op != 0);

    // list->print();

}