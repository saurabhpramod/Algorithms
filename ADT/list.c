#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"
#include "task.h"

#define MAX_DESCR 100
#define MIN_PRIORITY 139
#define MAX_PRIORITY 0
#define MAX_DURATION 120


typedef struct node_s{
    void * data; 
    struct node_s * next;
    struct node_s * prev;
}node_t;

typedef struct list_s{
    node_t * head;
    node_t * tail;
    int size;
}list_t;

node_t* node_new()
{
    node_t* n = (node_t *)malloc(sizeof(node_t));
    if(n == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void node_free(node_t* n, void (* data_free)(void *))
{
    if(data_free != NULL){
        data_free(n->data);
    }
    free(n);
    n = NULL;
}


list_t* list_new()
{
    list_t* l = (list_t *)malloc(sizeof(list_t));
    if(l == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}

void list_free(list_t *l, void (* data_free)(void *))
{
    if(l == NULL) return;
    while(l->head)
    {
        node_t * tmp = l->head;
        l->head = l->head->next;
        node_free(tmp, data_free);
    }
    free(l);
    l = NULL;
}

int list_size(list_t *l)
{
    return l->size;
}

int list_insert(list_t *l, void * data, int (* data_compare)(void *,void *))
{   
    if (l==NULL || data==NULL)
    {
        return -1;
    }
    node_t *n =node_new();
    n->data=data;

    if(l->head==NULL)
    {
        l->head= l->tail=n;
        l->size+=1;
        return 0;
    }

    if(data_compare==NULL)
    {
        n->next=NULL;
        n->prev=l->tail;
        l->tail->next=n;
        l->tail=n;
        l->size++;
        return 0;
    }
    
        node_t *curr= l->head;

            // Insert at the head (if smaller than the first element)
        if (data_compare(n->data, curr->data) < 0) 
        {
          n->next = l->head;
          n->prev = NULL;
          l->head->prev = n;
          l->head = n;
          l->size++;
          return 0;
        }

       while (curr != NULL && curr->next != NULL && data_compare(n->data, curr->next->data) >= 0)
        {
             curr = curr->next;
        }
        
    if (curr->next == NULL)
    {
        n->next = NULL;
        n->prev = l->tail;
        l->tail->next = n;
        l->tail = n;
        l->size++;
        return 0;
    }

    n->next = curr->next;
    n->prev = curr;
    curr->next->prev = n;
    curr->next = n;
    l->size++;
       
    return 0;
}

void * list_remove(list_t * l, void * key, int (* data_compare)(void *, void *)){
    if(l == NULL || l->head == NULL) return NULL;
    node_t * curr;
    for(curr = l->head; curr != NULL && data_compare(key, curr->data) != 0; curr = curr->next);
    if(curr == NULL) return NULL;
    void * data = curr->data;

    if(curr == l->head){
        l->head = curr->next;
        if(l->head != NULL) l->head->prev = NULL;
    }
    else if(curr == l->tail){
        l->tail = curr->prev;
        if(l->tail != NULL) l->tail->next = NULL;
    }
    else{
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    free(curr);
    return data;
}


void list_print(list_t * l, FILE * fp, void (* data_print)(void *, FILE *)){
    if(l == NULL || l->head == NULL){
        printf("List is empty.\n");
        return;
    }
    int i = 0;
    for(node_t * curr = l->head; curr != NULL; curr = curr->next){
        fprintf(fp, "List element #%d:\n\t", ++i);
        data_print(curr->data, fp);
    }
}

void *list_search(list_t *l, void *key, int (*data_compare)(void *, void *)) {
    node_t *current = l->head;

    while (current != NULL) {
        if (data_compare(current->data, key) == 0) {
            return current->data;  
        }
        current = current->next;
    }
    return NULL;
}


void * list_front(list_t * l)
{
    if(l == NULL || l->head == NULL) return NULL;


    return (l->head->data);
}