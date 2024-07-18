#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {int data; struct node *next;};

struct node * insert (struct node **list, int index, int value);
void print_list(struct node * list);
void free_list(struct node * list);
struct node * create_range(int start, int stop, int step);
int search(struct node * list, int key);
int idx(struct node * list, int key);

#endif