//
// Created by lg on 11/22/23.
//

#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct list_s list_t;

list_t* list_new();
void list_free(list_t *, void (* data_free)(void *));
int list_size(list_t *);
int list_insert(list_t *, void *, int (* data_compare)(void *, void *));
void * list_search(list_t *, void *, int (* data_compare)(void *, void *));
void * list_remove(list_t *, void *, int (* data_compare)(void *, void *));
void list_print(list_t *, FILE *, void (* data_print)(void *, FILE *));
void * list_front(list_t *);

#endif //LAB7_E1_LIST_H
