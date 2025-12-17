#include <stdio.h>

int main(){
    int age1, age2;

    printf("Input two ages: ");
    scanf("%d %d", &age1, &age2);

    int totalagefuck = age1 + age2; 

    printf("\nOutput\n");

    //age1
    printf("Age 1 = ");

    if(age1 < 18){
        printf("Minor\n");
    }

    else if(age1 > 18 && age1 < 60){
        printf("Adult\n");
    }

    else{
        printf("Senior Citizen\n");
    }

    //age2
    printf("Age 2 = ");

    if(age2 < 18){
        printf("Minor\n");
    }

    else if(age2 > 18 && age2 < 60){
        printf("Adult\n");
    }

    else{
        printf("Senior Citizen\n");
    }
    
    printf("%d + %d = %d\n", age1, age2, totalagefuck);

    printf("The sum is ");

    if(totalagefuck % 2 == 0){
        printf("EVEN");
    }

    else{
        printf("ODD");
    }

}