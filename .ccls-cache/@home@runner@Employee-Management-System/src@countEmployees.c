#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){
    //declare a pointer to traverse the linked lise
    a3Emp *ptr = NULL;
    //make it equal to the head
    ptr = headLL;
    //check if the linked list is empty
    if (headLL == NULL){
        printf("THERE ARE NO EMPLOYEES !!\n");
    };
    //loop variable to keep track of which employee we are on
    int numEmp = 0;
    //loop travereses linked list until ptr is NULL
    while(ptr!=NULL){
        numEmp++;
        ptr = ptr->nextEmployee;
    };
    //return the position of the employee
    return numEmp;
};