/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// homework Q7



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
    static int studentCount = 201; // Initialize the count to 201 for the first student
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

// Function to find the student with the longest name
struct Student* findLongestName(struct Student* head) {
    struct Student* longestStudent = NULL;
    size_t maxLength = 0;

    while (head != NULL) {
        size_t nameLength = strlen(head->name);
        if (nameLength > maxLength) {
            maxLength = nameLength;
            longestStudent = head;
        }
        head = head->next;
    }

    return longestStudent;
}

int main() {
    struct Student* studentList = NULL;

    // Add students to the list
    addStudent(&studentList, "Abdulrahman", 27);
    addStudent(&studentList, "Anas", 23);
    addStudent(&studentList, "Ali", 34);
    addStudent(&studentList, "Reem", 28);
   

    // Find the student with the longest name
    struct Student* longestStudent = findLongestName(studentList);

    if (longestStudent != NULL) {
        printf("the longest name in the list: %s\n", longestStudent->name);
        printf("Length: %ld\n", (long)strlen(longestStudent->name));
    } else {
        printf("No students found in the list.\n");
    }

    // Free memory for the student list
    while (studentList != NULL) {
        struct Student* temp = studentList;
        studentList = studentList->next;
        free(temp);
    }

    return 0;
}



