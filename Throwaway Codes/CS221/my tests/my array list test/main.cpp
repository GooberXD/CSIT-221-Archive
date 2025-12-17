#include <bits/stdc++.h>
#include "arraylist.hpp"

int main(){
    List* list = new ArrayList();

    char operation;
    int pos;

    do{
        printf("Op (add, print, posvalue): ");
        scanf(" %c", &operation);

        switch(operation){

            case 'a':
            case 'A':


                break;

            case 'g':
            case 'G':
                scanf("%d", &pos);
                printf("Value is %d\n", list->getPosValue(pos));

                break;


            case 'p':
            case 'P':
                list->print();
                break;

            

        }
    }while(operation != 'x' || operation != 'X');

}