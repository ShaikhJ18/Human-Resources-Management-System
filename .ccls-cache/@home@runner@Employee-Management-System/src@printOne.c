#include "../include/headerA3.h"
void printOne (struct employee * headLL, int whichOne){
    //declare a pointer to traverese linked list
    a3Emp *ptr = NULL;
    //Check if the linked list is empty
    if (headLL == NULL){
        printf("THERE ARE NO EMPLOYEES !!\n");
    };
    //make the ptr equal to the head of the linked list
    ptr = headLL;
    //this variable keeps track of the index of the linked list 
    int index = 1;
    //this loop traverses the linked list
    while(ptr!=NULL){
        //this condition checks if the index of the linked list is equal to the input from the user
        if (index == whichOne){
            //print the employee's information using arrow notation
            printf("Employee # %d:\n",index);
            printf("      Employee id: %d\n",ptr->empId);
            printf("      First name: %s\n",ptr->fname);
            printf("      last name: %s\n",ptr->lname);
            printf("      Dependents[%d]: ",ptr->numDependents);
            //print the dependents by looping through the array
            for (int j = 0; j < ptr->numDependents; j++){
                printf("%s, ",ptr->dependents[j]);
            }
        }
    printf("\n");
    //increment the index variable
    index++;
    //move to the next link
    ptr = ptr->nextEmployee;
    };
}