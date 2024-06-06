#include "../include/headerA3.h"
void printAll (struct employee * headLL){
    //declare a pointer to traverse the linked lise
    a3Emp *ptr = NULL;
    //make it equal to the head
    ptr = headLL;
    //check if the linked list is empty
    if (headLL == NULL){
        printf("THERE ARE NO EMPLOYEES !!\n");
    };
    //loop variable to keep track of which employee we are on
    int i = 1;
    //loop travereses linked list until ptr is NULL
    while(ptr!=NULL){
        //print employee information using arrow arrow notation
        printf("\n");
        printf("Employee # %d:\n",i);
        printf("      Employee id: %d\n",ptr->empId);
        printf("      First name: %s\n",ptr->fname);
        printf("      last name: %s\n",ptr->lname);
        printf("      Dependents[%d]: ",ptr->numDependents);
        //print all the dependents by looping through the array
        for (int j = 0; j < ptr->numDependents; j++){
            printf("%s, ",ptr->dependents[j]);
        }
        printf("\n");
        i++;
        //go to the next link
        ptr = ptr->nextEmployee;
    };

};