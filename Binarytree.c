#include "BinaryTree.h"

void menu(t_binary_tree *tree){
    char *input = "";
    char *operation = "";
    char *tree_code;
    while(!strcmp(operation, "exit")){
        fgets(input, sizeof(input), stdin);
        operation = get_operation(input);
        switch(operation){
            case "create":

                break;

            case "pre":
                pre_order(tree->root);
                break;

            case "in":
                in_order(tree->root);
                break;

            case "post":
                post_order(tree->root);
                break;

            case "height":

                break;
            case "print":

                break;
        }
    }
}
char* get_tree_code(char* input){
    char *index = strpbrk(input,"(");
    (*index)--;
    char *tree_code = strdup(index);
    return tree_code;
}

char* get_operation(char* input){
    char delimiters[] = " :(";
    char *operation;
    operation = strtok(input, delimiters);
    return operation;
}


void pre_order(t_node *node) {
    if (node != NULL) {
        printf("%d\t", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%d\t", node->item);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d\t", node->item);
    }
}

