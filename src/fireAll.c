#include "../include/headerA3.h"
void fireAll (a3Emp ** headLL){

    //check if the linked list is empty
     if (*headLL == NULL){
        printf("THERE ARE NO EMPLOYEES !!\n");
    };
    //create a pointer to traverse linkned list
    a3Emp *temp = *headLL;
    //this portion confirms iwth the user if they want to delelte every employee
    char option = 'n';
    //prompt the user for input
    printf("Are you sure you want to fire everyone: ");
    //store the ipnut into the option variable
    scanf(" %c",&option);
    //this condition handles the case that the user inputs yes
    if (option != 'n'){
        //this loop traverses the linked list and frees it
        while(temp != NULL){
            temp = temp->nextEmployee;
            free(*headLL);
            *headLL = temp;

        }
    }
}