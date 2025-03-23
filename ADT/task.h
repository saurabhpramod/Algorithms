//
// Created by lg on 11/22/23.
//

#ifndef TASK_H
#define TASK_H
#include <time.h>
#include <stdio.h>


typedef struct task_s task_t;

task_t * task_new();
void task_free(void *);
int task_compare(void *, void *);
int task_compare_priority(void *, void *);
void task_print(void *, FILE *);
void task_set_priority(task_t *, int);
void task_set_description(task_t *, char *);
int task_get_id(task_t *);
int task_get_priority(task_t *);
char * task_get_description(task_t *);
time_t task_get_duration(task_t *);

#endif //TASK_H
