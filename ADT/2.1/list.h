// list_utils.h
#ifndef LIST_H
#define LIST_H
#include <ctype.h>
#include <math.h>
//#include "sort_util.h"
typedef struct student_s student_t; // Forward declaration of student_t type

typedef struct student_s {
    char *name;          // Student's first name
    char *surname;       // Student's surname
    char *id;            // Student's unique alphanumeric ID
    int slot;            // Slot number assigned to the student
    student_t *next;     // Pointer to the next student in the list
    student_t *prev;     // Pointer to the previous student in the list
} student_t;


typedef struct {
    student_t *head;  // Head of the doubly linked list
    student_t *tail;  // Tail of the doubly linked list
    int size;         // Size of the list (number of students)
} students_list_t;

void display(students_list_t* students, int slots);
student_t* create_student(char *name, char *surname, char *id);
students_list_t* init_wrapper();
int assign_slots(students_list_t* students, int m);
void load_data(char *filename, students_list_t* students);
//void sort_list(struct students_list_s* students, char algorithm);


#endif // LIST_UTILS_H