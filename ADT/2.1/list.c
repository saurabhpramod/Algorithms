
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "list.h"

#define MAX_NAME_LEN 100




student_t* create_student(char *name, char *surname, char *id) {
    student_t* student = (student_t *)malloc(sizeof(student_t));

    if (student == NULL) {
        fprintf(stderr, "Error in allocating memory!");
       return NULL;
    }
    if (student->name == NULL) {
        free(student);
        return NULL;  // Return NULL if allocation fails for name
    }

    student->name = (char *)malloc(strlen(name) + 1);
    if (student->name != NULL) 
    strcpy(student->name, name);

    if (student->surname == NULL) {
        free(student);
        return NULL;  // Return NULL if allocation fails for surname
    }
    
    student->surname =(char *) malloc(strlen(surname) + 1);
    if (student->surname != NULL) 
    strcpy(student->surname, surname);
    
    student->id = (char *)malloc(strlen(id) + 1);
    if (student->id != NULL) 
    strcpy(student->id, id);
    
    student->slot = 0;
    student->next = NULL;
    student->prev = NULL;

    return student;
}
void load_data(char *filename, students_list_t *students) {
    student_t *new_student;
    char name[MAX_NAME_LEN], surname[MAX_NAME_LEN], id[MAX_NAME_LEN];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "The file cannot be opened!\n");
        return;
    }

    while (fscanf(fp, "%s %s %s", name, surname, id) != EOF) {
        new_student = create_student(name, surname, id);

        if (students->head == NULL)
            students->tail = new_student; // the first element to insert will be the tail..
        else
           { 
              students->head->prev = new_student; 
              new_student->next = students->head;
              students->head = new_student;
           }

        students->size++;
    }

    fclose(fp);
}



students_list_t* init_wrapper() {

     students_list_t * students = (students_list_t *)malloc(sizeof(students_list_t));

    if (students == NULL) {
        fprintf(stderr, "Error in allocating memory!\n");
        return NULL;
    }

    students->head = NULL;
    students->tail = NULL;
    students->size = 0;

    return students;
}

int assign_slots(students_list_t* students, int m) {
    int k = 1;

    for (student_t *s=students->head; s != NULL; s = s->next, k++)
        s->slot = (int) ceil((double ) k / m);

    return ((int) ceil((double)students->size/m));
}



void display(students_list_t* students, int slots) {
    student_t *temp = students->head;

    printf("The number of assigned slots is %d!\n", slots);

    for (int i = 1; i<=slots; i++) {
        printf("Slot %d:\n", i);

        for (student_t *s=temp; s != NULL; s = s->next) {
            if (s->slot != i) {
                temp = s;
                break;
            }

            printf("\t%s %s %s\n", s->name, s->surname, s->id);
        }
    }
}

/*void sort_list(struct students_list_s* students, char algorithm) {
    algorithm = toupper(algorithm);
    switch (algorithm) {
        case 'S':
            selection_sort(students);
            break;
        case 'I':
            insertion_sort(students);
            break;
        case 'B':
            bubble_sort(students);
            break;
        default:
            fprintf(stderr, "The sorting algorithm is undefined!\n");
            exit(EXIT_FAILURE);
    }
}*/