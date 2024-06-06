#include "../include/headerA3.h"
int lookOnId (struct employee * headLL, int whichEmpId){
    //Declare pointer to traverse linked list
    a3Emp *ptr = NULL;
    ptr = headLL;
    //this condition checks if the list is empty
    if (headLL == NULL){
        printf("THERE ARE NO EMPLOYEES !!\n");
    };
    //this variable keeps track of which employee we are on
    int i = 1;
    //this variable returns to main the position at which the employee ID was found
    int index = 0;
    //traverse the linked list until the end is reached
    while(ptr!=NULL){
        //condition to check if the ID's are equal
        if(whichEmpId == ptr->empId){
            //if the same Id is found assign it to the index variable
            index = i;
        }
        //increment the i variable to indicate we have moved ot the next employee
        i++;
        //go to the next employee
        ptr = ptr->nextEmployee;
    };
    //return the index at which a comparison was found
    return index;
}
