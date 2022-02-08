/******************************************************************************

                            AIU Students Addmission System
            Staff Only are allowed to use this program for registartion purposes

*******************************************************************************/

// We First Include All the packages that we need to use differnet data types, variables, constants, subprograms, cursors, and exceptions etc..
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Structure user built to store student name, ID, CGPA, and course
struct Student
{
    char student_id[100];
    char firstname[100];
    char lastname[100];
    char course[100];
    char CGPA[100];
    struct Student *next;

} * head;
void insert(char *firstname, char *lastname, char *student_id, char *course, char *CGPA) // The function that saves students data to the structure
{

    struct Student *student = (struct Student *)malloc(sizeof(struct Student)); // making a call to the structure
    strcpy(student->student_id, student_id);                                           // stores data
    strcpy(student->firstname, firstname);                                      // stores data
    strcpy(student->lastname, lastname);                                        // stores data
    strcpy(student->course, course);                                            // stores data
    strcpy(student->CGPA, CGPA);                                                 // stores data
    student->next = NULL;                                                       // stores data

    if (head == NULL)
    {
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else
    {
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    printf("Student was Successfully Added\n\n"); // Confirmation
}

void search(char *student_id)
{
    struct Student *temp = head; // calls student data
    while (temp != NULL)
    {
        if ((strcmp(temp->student_id, student_id) == 0 ))
        {
            printf("First Name of Student: %s\n", temp->firstname);  // printing out data
            printf("Last Name of Student: %s\n", temp->lastname);    // printing out data
            printf("Student ID of Student: %s\n", temp->student_id); // printing out data
            printf("course of Student: %s\n", temp->course);         // printing out data
            printf("CGPA of Student: %s\n", temp->CGPA);          // printing out data
            return;
        }
        temp = temp->next;
    }
    printf("Student with Student ID %s is not found !!!\n", student_id); // Error Handling
}
void check_id(char *student_id)
{
    struct Student *temp = head; // calls student data

    while (temp != NULL)
    {
        if ((strcmp(temp->student_id, student_id) == 0 ))
        {
            printf("Record with Student ID %s Already exist !!!\n", student_id); // Checks if student ID already exist
                printf("\n\nThank You for using AIU Student System\n");
                exit(0); // Exits program
            return;
        }
        temp = temp->next;
    }
    printf("Student Got a Unique Student ID (%s) \n\n", student_id); // Error Handling
}
void update(char *student_id)
{
    struct Student *temp = head; // calls student data

    while (temp != NULL)
    {
        if ((strcmp(temp->student_id, student_id) == 0 ))
        {
            printf("Record with Student ID %s Found !!!\n", student_id);
            printf("Enter new First name: ");
            scanf("%s", temp->firstname); // Getting Student New Data
            printf("Enter new Last name: ");
            scanf("%s", temp->lastname); // Getting Student New Data
            printf("Enter new Course Name: ");
            scanf("%s", temp->course); // Getting Student New Data
            printf("Enter new CGPA: ");
            scanf("%s", temp->CGPA);                           // Getting Student New Data
            printf("Student Data was Updated Successfully!\n"); // Confirmation
            return;
        }
        temp = temp->next;
    }
    printf("Student with Student ID %s is not found !!!\n", student_id); // Error Handling
}

void Delete(char *student_id)
{
    struct Student *temp1 = head;
    struct Student *temp2 = head;
    while (temp1 != NULL)
    {

        if ((strcmp(temp1->student_id, student_id) == 0 ))
        {

            printf("Record with Student ID %s Found !!!\n", student_id);

            if (temp1 == temp2)
            { // This condition will run if the record that we need to delete is the first node of the linked list
                head = head->next;
                free(temp1);
            }
            else
            {
                // temp1 is the node we need to delete
                // While temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n"); // Confirmation
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student with Student ID %s is not found !!!\n", student_id); // Error Handling
}
void display()
{
    struct Student *temp = head;                                                                                                                   // calls student data from structure
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AIU Students List \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n"); // Starting Table

    printf("========================================================================================================================\n");

    printf("First Name \t\t Last Name\t\t Student ID \t\t Course \t\t CGPA \n"); // Table Titles

    printf("========================================================================================================================\n\n");

    while (temp != NULL)
    {                                                                                                                                            // to print the next student if data exists
        printf("%s \t\t\t %s \t\t\t %s \t\t\t %s \t\t %s \n\n", temp->firstname, temp->lastname, temp->student_id, temp->course, temp->CGPA); // Print from structure to compiler
        temp = temp->next;
    }
    printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n"); // Ending Table
}


int start_system(){
    head = NULL;         // Declaration
    int choice;          // Declaration
    char firstname[100]; // Declaration
    char lastname[100];  // Declaration
    char course[100];    // Declaration
    char student_id[100];      // Declaration
    char cgpa[100];          // Declaration
    struct Student *temp = head; // calls student data

        printf("\n\n\t\t\t     *  *  *  *  *  *  *  * *  *  *  *  *  *  *");
        printf("\n\n\t\t\t     *                                        *");
        printf("\n\n\t\t\t     *             Welcome AIU Staff          *");
        printf("\n\n\t\t\t     *                                        *");
        printf("\n\n\t\t\t     *  *  *  *  *  *  *  * *  *  *  *  *  *  *\n\n");

        do
        {

            printf("Choose one of the following Options\n");
            printf("\t\t1 - Add a New Student Details\n");
            printf("\t\t2 - Find a Student Details by Student ID  \n");
            printf("\t\t3 - Delete a Student by Student ID \n");
            printf("\t\t4 - Update a Student by Student ID \n");
            printf("\t\t5 - Display and List AIU Stored Students \n");
            printf("\t\t6 - To Exit\n");
            // The above are all options

            printf("\tEnter the operation of your choice:\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\tEnter the Student's First Name: \n");
                scanf("%s", firstname);
                printf("\tEnter the Student's Last Name: \n");
                scanf("%s", lastname);
                printf("\tEnter the Student's ID :  \n");
                scanf("%s", student_id);
                check_id(student_id);
                printf("\tEnter the Student's Enrolled Course Name: \n");
                scanf("%s", course);
                printf("\tEnter the Student's CGPA:  \n");
                scanf("%s", cgpa);
                insert(firstname, lastname, student_id, course, cgpa);
                break;
            case 2:
                printf("Enter Student ID to search: ");
                scanf("%s", student_id);
                search(student_id);
                break;
            case 3:
                printf("Enter Student ID to delete: ");
                scanf("%s", student_id);
                Delete(student_id);
                break;
            case 4:
                printf("Enter Student ID to update: ");
                scanf("%s", student_id);
                update(student_id);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nThank You for using AIU Student System\n");
                exit(0); // Exits program
                break;
            default:
                printf("\nYou Have Entered a Wrong Operation  \nTry Again or Type 8 to Exit\n\n\n");
                exit(0);
                break;
            }

        } while (choice != 0);
            return (0);


}
int main()
{
    char username[100]; // Declaration
    char password[100];        // Declaration

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|                    |\n\t\t\t\t\t| AIU Student System |\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|\t\t     |\n\n\n");
    printf("\n\n\t\t\t\t\t This is Confidential Data \n\t\t\t You are only allowed to enter Confidential's one time \n\n");
     
     
    for ( int attempts_times = 1; attempts_times <= 3; attempts_times++) { //Attempt is 1 be default as its the first time
    printf("What is The Addamission Username: \n\n");
    scanf("%s", username); // Getting Username
    printf("What is The Addamission Staff Password \n\n");
    scanf("%s", password); // Getting Password

    if (((strcmp(username, "Saif") == 0) || (strcmp(username, "Admin") == 0 ) )  && (strcmp(password, "Saif") == 0 )) {
        start_system();
    } else
    {
        printf("You have entered the wrong Confidential's for the %d attempt" , attempts_times);
        if (attempts_times <= 3){
        printf("\n\n\nTry again \n\n\n");
        }
        else{
        printf("\n\n\nSorry, Access Denied!!");
        exit(0); 
    }   
    }}
}
