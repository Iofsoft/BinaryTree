#include "BinaryTree.h"

t_stack* create(int size){
    t_stack *stack = (t_stack*) malloc (sizeof (t_stack));
    stack->top = -1;
    stack->items = (int*) malloc (sizeof(int)*size);
    return stack;
}

int push(t_stack *stack, int element){
    stack->top++;
    stack->items[stack->top] = element;
}

int pop(t_stack *stack){
    stack->top--;
    return stack->items[stack->top+1];
}

