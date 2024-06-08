#ifndef BINARYTREE_H
#define BINARYTREE_H

    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>

    typedef struct _node {
        char item;
        struct _node *left;
        struct _node *right;
    } t_node;

    typedef struct {
        t_node *root;
        int height;
    } t_binary_tree;

    typedef struct {
        int top;
        int* items;
    }t_stack;

    t_binary_tree* create_tree();
    void menu(t_binary_tree *tree);
    void remove_newline(char* input);
    char* get_operation(char* input);
    char* get_tree_code(char* input);

    int sequence_validation(char *tree_code);
    int letters_counter(char* tree_code);

    t_node* build_tree(char** tree_code);
    t_node* create_node(char item);

    void pre_order(t_node *node);
    void in_order(t_node *node);
    void post_order(t_node *node);

    char* get_height_target(char* input);
    int node_height(t_node* node, char* target);

    void print_tree(t_node *root, int height);
    void free_tree(t_node* node);

#endif //BINARYTREE_H