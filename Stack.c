#include "BinaryTree.h"

t_stack* create(int size){
    t_stack *stack = (t_stack*) malloc (sizeof (t_stack));
    stack->top = -1;
    stack->items = (t_node**) malloc (sizeof(t_node)*size);
    return stack;
}

void push(t_stack *stack, t_node* element){
    stack->top++;
    stack->items[stack->top] = element;
}

t_node* pop(t_stack *stack){
    return stack->items[stack->top--];
}

