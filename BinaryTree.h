#ifndef BINARYTREE_H
#define BINARYTREE_H

    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>

    typedef struct _node {
        int item;
        struct _node *left;
        struct _node *right;
    } t_node;

    typedef struct {
        t_node *root;
        int n;
    } t_binary_tree;

    typedef struct {
        int top;
        int *items;
    }t_stack;

    char* get_operation(char* input);
    void pre_order(t_node *node);
    void in_order(t_node *node);
    void post_order(t_node *node);


    t_stack* create(int size);
    int push(t_stack *stack, int element);
    int pop(t_stack *stack);





#endif //BINARYTREE_H
