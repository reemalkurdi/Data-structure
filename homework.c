/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// homework Q4-5



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a structure to represent a student
struct Student {
    int student_number;
    char name[100];
    int age;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int number, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent != NULL) {
        newStudent->student_number = number;
        snprintf(newStudent->name, sizeof(newStudent->name), "%s", name);
        newStudent->age = age;
        newStudent->next = NULL;
    }
    return newStudent;
}



// Function to add a student to the end of the list
void addStudent(struct Student** head, const char* name, int age) {
    static int studentCount = 1; // Initialize the count to 1 for the first student
    struct Student* newStudent = createStudent(studentCount, name, age);
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    studentCount++; // Increment the count for the next student
}



// Function to traverse and display the list
void displayStudents(struct Student* head) {
    int count = 201; // Initialize the count to 1
    while (head != NULL) {
        printf("%d- %s %d %d\n", head->student_number, head->name, head->age, count);
        head = head->next;
        count++; // Increment the count for the next student
    }
    printf("Total number of students: %d\n", count - 201); // Subtract 1 to get the correct count
}

// Function to search and print records by student name
void searchByName(struct Student* head, const char* targetName) {
    while (head != NULL) {
        if (strcmp(head->name, targetName) == 0) {
            printf("Student Number: %d\n", head->student_number);
            printf("Name: %s\n", head->name);
            printf("Age: %d\n", head->age);
            
        }
        head = head->next;
    }
}


int main() {
    struct Student* studentList = NULL;

    // Add students to the list
    addStudent(&studentList, "Abdulrahman", 27);
    addStudent(&studentList, "Anas", 23);
    addStudent(&studentList, "Ali", 34);
    addStudent(&studentList, "Reem", 28);

    // Display the student information and count
    displayStudents(studentList);


 // Search for records by student name
char searchName[100];
printf("Enter a student name to search: ");
scanf("%s", searchName);
printf("Records for %s:\n", searchName);
searchByName(studentList, searchName);

    
    
    
    
    // Free memory for the student list
    while (studentList != NULL) {
        struct Student* temp = studentList;
        studentList = studentList->next;
        free(temp);
    }

return 0;
}



