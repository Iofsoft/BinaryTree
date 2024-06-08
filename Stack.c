#include "BinaryTree.h"

t_stack* create_stack(int size){
    t_stack *stack = malloc (sizeof (t_stack));
    stack->top = -1;
    stack->items =  malloc (sizeof(int)*size);
    return stack;
}

void push(t_stack *stack, int element){
    stack->top++;
    stack->items[stack->top] = element;
}

int pop(t_stack* stack){
    stack->top--;
    return stack->items[stack->top+1];
}

void destroy_stack(t_stack* stack){
    free(stack->items);
    free(stack);
}

int is_empty(t_stack* stack) {
    return stack->top == -1;
}

