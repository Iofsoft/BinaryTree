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
        t_node **items;
    }t_stack;

    void menu(t_binary_tree *tree);
    char* get_operation(char* input);
    char* get_tree_code(char* input);
    t_node* create_node(char item);
    t_binary_tree* create_tree();
    t_node* build_tree(char *tree_code);
    void print_tree(t_node *root, int height);
    void pre_order(t_node *node);
    void in_order(t_node *node);
    void post_order(t_node *node);


    t_stack* create(int size);
    void push(t_stack *stack, t_node* element);
    t_node* pop(t_stack *stack);





#endif //BINARYTREE_H
