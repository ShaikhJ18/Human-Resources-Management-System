#include "../include/headerA3.h"
//this void function sorts the linked list using BUBBBLE SORT
void sortEmployeesId(struct employee *headLL) {
    //this condition checks if the linked list is empty
    if (headLL == NULL) {
        printf("THERE ARE NO EMPLOYEES !!\n");
        return;
    }
    //the swappped variable is used in th ewhile loop to swap th employee information
    int swapped;
    //this pointer is pointing to the head of the linked list
    struct employee *ptr1 = headLL;
    //this pointer is pointing to NULL
    struct employee *ptr2 = NULL;

    //This do while loop changes the employees information based on a comparison
    do {
        swapped = 0;
        ptr1 = headLL;
        //this while loop traverses the linked list and compares employee ids
        while (ptr1->nextEmployee != ptr2) {
            //this condittion compares employee ids
            if (ptr1->empId > ptr1->nextEmployee->empId) {
                //the tempId variable temporarily stores the greater id
                int tempId = ptr1->empId;
                //then the current empid is set to the next ID
                ptr1->empId = ptr1->nextEmployee->empId;
                //then the next ID takes the previous id stored in the temp variable
                ptr1->nextEmployee->empId = tempId;
                //Now this variable temporarily stores the First name of current employee
                char *tempFname = malloc(sizeof(char)*MAX_LENGTH);
                //store the current employee first name in the temp string
                strcpy(tempFname, ptr1->fname);
                //copy the next first name into the current one
                strcpy(ptr1->fname, ptr1->nextEmployee->fname);
                //copy the current one stored in the temp variable into the next one
                strcpy(ptr1->nextEmployee->fname, tempFname);
                //this temp variable stores the current lastname 
                char *tempLname = malloc(sizeof(char)*MAX_LENGTH);
                //copy the current last name into the temp variable
                strcpy(tempLname, ptr1->lname);
                //copy the next last name into the current one
                strcpy(ptr1->lname, ptr1->nextEmployee->lname);
                //copy the current lastname into the next one
                strcpy(ptr1->nextEmployee->lname, tempLname);
                //now swapped is gonna be equal to one
                swapped = 1;
            }
            //move to the next employee
            ptr1 = ptr1->nextEmployee;
        }
        //now ptr2 is gonna take on the value of ptr1
        ptr2 = ptr1;
        //this keeps looping until swapped is 0
    } while (swapped);
}

