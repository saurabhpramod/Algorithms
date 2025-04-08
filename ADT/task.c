#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"

#define MAX_DESCR 100
#define MIN_PRIORITY 139
#define MAX_PRIORITY 0
#define MAX_DURATION 120



typedef struct task_s{
int id;
int priority;
char *description;
time_t duration;
}task_t;

task_t * task_new() {
    static int id = 1000;
    task_t *t = (task_t *)malloc(sizeof(task_t));
    
    if(t == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    } else {
        t->id = id++;
        t->priority = MIN_PRIORITY;
        t->duration = 1 + rand() % MAX_DURATION;

        // Allocate memory for description string (MAX_DESCR characters)
        t->description = (char *)malloc(MAX_DESCR * sizeof(char));
        if (t->description == NULL) {
            fprintf(stderr, "Memory allocation error for description.\n");
            free(t);
            return NULL;
        }
    }
    return t;
}


void task_free(void *t){
    if(t != NULL){
        free(t);
    }
    t = NULL;
}

int task_compare(void *t1, void *t2){
    return (((task_t *)t2)->id - ((task_t *)t1)->id);
}

int task_compare_priority(void *t1, void *t2) {
   if (t1 == NULL || t2 == NULL) {
        fprintf(stderr, "Error: One of the task pointers is NULL.\n");
      return 0;  // Return 0 or some other error value
   }

    return (((task_t *)t2)->priority - ((task_t *)t1)->priority);
}

void task_print(void * t, FILE * fp)
{
    if(t != NULL)
    {
        task_t * tt = (task_t *)t;

        fprintf(fp, "ID: %d \tPriority: %d \tDescription: %s \tDuration: %ld s\n", tt->id, tt->priority, tt->description, tt->duration);
    }
   
}

    void task_set_priority(task_t *t, int priority)
    {
        if(priority > MIN_PRIORITY || priority < MAX_PRIORITY)
        {
            fprintf(stderr, "Priority must be in the range [0-139]\n");  // Use stderr for error messages
            return;
        }
        else
        t->priority = priority;
        return;
    }
    

void task_set_description(task_t *t, char *description) {
    // If the description is not NULL
    if (description != NULL) {
        // Check if t->description is already allocated
       //if (t->description == NULL) {
            // Allocate memory for the description (if it was not previously allocated)
            t->description = (char *)malloc(MAX_DESCR * sizeof(char));
            if (t->description == NULL) {
                printf("Memory allocation failed!\n");
                return;
            }
      //  }

        // Copy the provided description string to the allocated memory
        strncpy(t->description, description, MAX_DESCR);
        // Ensure null termination
        t->description[MAX_DESCR - 1] = '\0';
    } else {
        // If the provided description is NULL, handle it (optional)
        printf("Provided description is NULL.\n");
        // You can choose to either leave the description as is or free it if it was allocated earlier
        // For example, you might want to free the memory if it's already allocated
        if (t->description != NULL) {
            free(t->description);
            t->description = NULL;
        }
    }
}

int task_get_id(task_t *t){
    if(t == NULL) return -1;
    return t->id;
}

int task_get_priority(task_t *t){
    if(t == NULL) return -1;
    return t->priority;
}

char* task_get_description(task_t *t){
    if(t == NULL) return NULL;
    return t->description;
}

time_t task_get_duration(task_t *t){
    if(t == NULL) return -1;
    return t->duration;
}
