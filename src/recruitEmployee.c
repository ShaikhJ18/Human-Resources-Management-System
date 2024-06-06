#include "../include/headerA3.h"
//this function creates a new employee
void recruitEmployee (struct employee ** headLL){
    //create the ptr to traverse the linked list
    a3Emp *ptr = *headLL;
    //this variable temporarily stores an employee
    a3Emp *temp = malloc(sizeof(a3Emp));
    //this variable stores the first name of the employee
    char* firstname = malloc(sizeof(char)*MAX_LENGTH);
    //this variable stores the last name of the employee
    char* lastname = malloc(sizeof(char)*MAX_LENGTH);

    //prompt the user to input the first name
    printf("Enter the first name of the employee: ");
    //scan the firstname
    scanf("%s", firstname);
    //copy the first name into the temp employee struct
    strcpy(temp->fname, firstname);

    //prompt the user to input the last name
    printf("Enter the last name of the employee: ");
    //scanf the lastname
    scanf("%s", lastname);
    //copy the last name into the temp employee struct 
    strcpy(temp->lname, lastname);

    //now this portion of the code builds the employee ID
    int sumOfAscii = 0;
    //sumOfAscii stores the sum of the ascii characters

    //this loop calculates the sum of the ascii characters
    for (int i = 0; i < strlen(firstname); i++){
        //this variable stores the letter
        char letter = firstname[i];
        //this variable stores the ascii value of the letter
        int asciiValue = letter;
        //add that value to the sumOfAscii variable
        sumOfAscii += asciiValue;
    }

    //this varibale stores the length of the last name
    int lengthOfLastName = strlen(lastname);
    //assign the empId to the temp struct by summing the lenght of the lastname and sum of the ascii characters
    temp->empId = lengthOfLastName + sumOfAscii;
    //assign the num of dependents intially to zero
    temp->numDependents = 0;
    //assign the dependets initially to zero
    temp->dependents = NULL;
    //assign the next employee member to zero
    temp->nextEmployee = NULL;
    //use this variable to traverse linked list
    a3Emp *currEmployee = *headLL;

    //this do while loop checks for duplicate employee iD's
do {
    currEmployee = *headLL;
    //thi loop traverses the linked list
    while(currEmployee != NULL) {
        //This condition checks for duplicate ID's
        if (currEmployee->empId == temp->empId) {
            // empId already exists, generate a new one
            temp->empId += (rand() % 999) + 1;
            //start again from the beginning 
            currEmployee = *headLL; 
        } else {
            //move to the next employee
            currEmployee = currEmployee->nextEmployee;
        }
    }
} while (currEmployee != NULL);

        //this variable decides if there are more dependents
        char hasMoreDependents = 'y';
        //this loop accounts for more dependents
        while (hasMoreDependents == 'y' || hasMoreDependents == 'Y') {
        //this varibale stores the name of the dependent
        char* dependentName = malloc(MAX_LENGTH * sizeof(char));
        //prompt the user and store it in the depdentname variable
        printf("Enter name of dependent# %d: ", temp->numDependents + 1);
        scanf("%s", dependentName);

        // Allocate space for new dependent in the temporary struct
        temp->dependents = realloc(temp->dependents, (temp->numDependents + 1) * sizeof(char*));
        // Assign new dependent to array in the temp struct
        temp->dependents[temp->numDependents] = dependentName;
        //increment the number of dependents
        temp->numDependents++;
        //prompt the user to ask if there are more employees
        printf("Do you have any more dependents? ");
        //scan the user input into the varibale that decides if the loop should continue
        //once the user inputs n the loop will stop looping
        scanf(" %c", &hasMoreDependents);
    }

    //print out the information for the number of dependents 
    printf("\n");
    printf("You have %d dependents.\n", temp->numDependents);

    //print out the inofrmation for the employee ID
    printf("Your computer-generated empId is %d\n",temp->empId);

    //this portion of the code makes sure to handle the case that the list is empty
    if (ptr == NULL) {
        // list is empty, set head to new employee
        *headLL = temp;
    } else {
        // traverse to the end of the list
        while(ptr->nextEmployee != NULL){
            ptr = ptr->nextEmployee;
        }
        // add new employee to the end
        ptr->nextEmployee = temp;
    }
}
