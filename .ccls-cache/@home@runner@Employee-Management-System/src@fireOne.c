#include "../include/headerA3.h"
void fireOne (a3Emp ** headLL, int whichOne){
    a3Emp *current = *headLL;
    a3Emp *previous = *headLL;
    a3Emp *ptr = NULL;
    int index = 1;
    int firedEmployee;
    ptr = *headLL;
    while(ptr!=NULL){
        //this condition checks if the index of the linked list is equal to the input from the user
        if (index == whichOne){
            firedEmployee = ptr->empId;
        }
    //increment the index variable
    index++;
    //move to the next link
    ptr = ptr->nextEmployee;
    };
    //check if the linked list is empty
    if (*headLL == NULL){
        printf("THERE ARE NO EMPLOYEES !!\n");
    }
        else if (whichOne == 1){
            *headLL = current->nextEmployee;
            free(current);
            current = NULL;

        }
        else{
            while(whichOne != 1){
                previous = current;
                current = current->nextEmployee;
                whichOne--;

            }
            previous->nextEmployee = current->nextEmployee;
            free(current);
            current=NULL;
        }
        //recalculate the new number of employees using the countEmployees function
        int newNumEmployees = countEmployees(*headLL);
        //print the information to the terminal
        printf("Employee [Id: %d] fired\n",firedEmployee);
        printf("there are now %d employees\n",newNumEmployees);

}