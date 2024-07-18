#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node * insert (struct node **list, int index, int value) {
    struct node *to_insert;

    to_insert = malloc(sizeof(struct node));
    if (to_insert == NULL) {
        printf("Error: malloc failed in insert \n");
        exit(EXIT_FAILURE);
    }
    
    struct node *prev = NULL;
    struct node *curr = *list;

    for (int i = 0;i < index && curr != NULL; i++,  prev = curr, curr = curr->next);
    
    to_insert->data = value;
    to_insert->next = curr;

    if (prev == NULL) {
        *list = to_insert;
    } else {
        prev->next = to_insert;
    }
    return to_insert;
}

void print_list(struct node * list) {
    printf("[");
    for (int i = 0;list != NULL; list = list->next, i++) {
        
        printf("%s%d", i == 0? "":", ",list->data);
    }
    printf("]\n");
}

void free_list(struct node * list) {
    for (struct node * temp;list != NULL; ){
        temp = list->next;
        free(list); 
        list = temp;
    }
}

struct node *create_range(int start, int stop, int step) {
    struct node * range = NULL, *last = NULL;

    if (start < stop && step <= 0 || start > stop && step >= 0)
        return range;

    for (bool begin = true; start < stop; start += step, begin = false) {
        if (begin) {
            last = insert(&range, 0, start);
        } else {
            last = insert(&last, 1, start);
        }
    }

    return range;
}

int search(struct node * list, int value) {

    for (int i = 0;list != NULL; i++, list = list->next) {
        if (list->data == value)
            return i;
    }
    return -1;
}

int idx(struct node * list, int key) {

    for (int i = 0;list != NULL; i++, list = list->next) {
        if (i == key)
            return list->data;
    }
    printf("Error: Index out of range. \n");
    exit(EXIT_FAILURE);
}

