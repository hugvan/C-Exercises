#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct stack_type { 
    struct node *top;
    int length;
};

struct stack_type stack_create();
void stack_push(struct stack_type *stack, int value);
int stack_pop(struct stack_type *stack);

int main() {
    struct stack_type s1 = stack_create();
    stack_push(&s1, 100);
    stack_push(&s1, 200);
    stack_push(&s1, 300);
    printf("%d\n", s1.length);
    printf("%d\n", stack_pop(&s1));
    printf("%d\n", stack_pop(&s1));
    printf("%d\n", stack_pop(&s1));

    return 0;
}

struct stack_type stack_create() {
    struct stack_type s = {.top = NULL, .length = 0};
    return s;
}

void stack_push(struct stack_type *stack, int value) {
    insert( &(stack->top), 0, value);
    (stack->length)++;
}

int stack_pop(struct stack_type *stack) {
    struct node *curr_top = stack->top;

    if (curr_top == NULL) {
        printf("Error: Stack Empty at pop\n");
        exit(EXIT_FAILURE);
    }
    
    int ret = curr_top->data;
    stack->top = stack->top->next;
    (stack->length)--;

    free(curr_top);
    return ret;
}

int stack_checktop(struct stack_type *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack Empty at checktop\n");
        exit(EXIT_FAILURE);
    }
    
    return stack->top->data;
}