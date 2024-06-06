#include "../include/headerA3.h"

int main(int argc, char *argv[]){
    //declare file pointer
    FILE *filePtr;
    //set head to NULL
    a3Emp *head = NULL;

    //open the file for reading
    filePtr = fopen("proFile.txt", "r");

    //if the file pointer is NULL return error message
    if (filePtr == NULL)
    {
        printf("Error opening file.\n");
    }
    //Call the load function to populate linked list
    loadEmpData(&head, "proFile.txt");
    int option;
    int employee;
    int enteredId;
    int employeeToFire;
    char *firstHalfOfName = malloc(sizeof(char)*MAX_LENGTH);
    char *secondHalfOfName = malloc(sizeof(char)*MAX_LENGTH);
    char *fullName = malloc(sizeof(char)*(MAX_LENGTH*2));
    //this do while loop prints the menu and calls the functions based on the input
    //inputting 10 exits the loop
    do {
        printf("\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");
        printf("\n"); 
        printf("Enter an option number (1-10): ");
        scanf("%d",&option);
        switch(option) {
            case 1:
                recruitEmployee(&head);
                break;
            case 2:
                printAll(head);
                break;
            case 3:
                printf("Enter the employee position: ");
                scanf("%d",&employee);
                printOne(head,employee);
                break;
            case 4:
                printf("Enter the employee ID: ");
                scanf("%d",&enteredId);
                printOne(head,lookOnId(head,enteredId));
                break;
            case 5:
                printf("Enter the full name of the employee: ");
                scanf("%s",firstHalfOfName);
                scanf("%s",secondHalfOfName);
                fullName = strcat(firstHalfOfName,secondHalfOfName);
                printOne(head,lookOnFullName(head,fullName));            
                break;
            case 6:
                printf("\n");
                printf("Total number of employees = %d\n",countEmployees(head));
                break;
            case 7:
                printf("After sorting on empId, the employees are as follows:\n");
                sortEmployeesId(head);
                printAll(head);
                break;
            case 8:
                printf("Currently there are %d employees\n",countEmployees(head));
                printf("Enter the employee position to fire (1 to %d): ",countEmployees(head));
                scanf("%d",&employeeToFire);
                fireOne(&head,employeeToFire);
                break;
            case 9:
                fireAll(&head); 
                break;
            case 10:
                printf("Exiting menu...\n");
                break;
            default:
                printf("Invalid option selected. Please enter a number between 1 and 10.\n");
                break;
        }
}
while (option != 10);
}