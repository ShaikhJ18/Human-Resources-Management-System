#include "../include/headerA3.h"
int lookOnFullName (struct employee * headLL, char whichName [100]){
    // declare a pointer to traverse the linked list
    a3Emp *ptr = headLL;

    //this variable stores the fullName Concatenate in the while loop below
    char *fullName = malloc(sizeof(char)*(MAX_LENGTH*2));
    // loop traverses linked list until ptr is NULL

    //this loop stores the position of the employee
    int numEmp = 1;
    //this loop traverse the linked list
    while (ptr != NULL) {
        //concatenate the first and last name into the fullName variable
        strcat(strcat(fullName,ptr->fname),ptr->lname);
        //this condition checks if the fullName is the same as the one passed into the function
        if (strcmp(fullName,whichName) == 0){
            //return the position of the employee
            return numEmp;
        }
        //if the name is not found reassign the fullName to ""
        strcpy(fullName,"");
        //move to the next employee
        ptr = ptr->nextEmployee;
        //increment the position
        numEmp++;
    }
    //finallly return the position to main
    return numEmp;
}
