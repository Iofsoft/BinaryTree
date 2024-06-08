#include "BinaryTree.h"

void menu(t_binary_tree *tree){
    char *operation = "";
    while(strcmp(operation, "exit") != 1){
        char *input = "";
        fgets(input, sizeof(input), stdin);
        operation = get_operation(input);

        if(strcmp(operation,"create")){
            char *tree_code = get_tree_code(input);
            tree->root = build_tree(tree_code);
            continue;
        }

        if(strcmp(operation,"pre")){
            pre_order(tree->root);
            continue;
        }

        if(strcmp(operation,"in")){
            in_order(tree->root);
            continue;
        }
        if(strcmp(operation, "post")){
            post_order(tree->root);
            continue;
        }
        if(strcmp(operation, "height")){
            continue;
        }

        if(strcmp(operation, "print")){
            print_tree(tree->root, 0);
        }
    }
}

char* get_operation(char* input){
    char delimiters[] = " :(";
    char *operation;
    operation = strtok(input, delimiters);
    return operation;
}

char* get_tree_code(char* input){
    char *index = strpbrk(input,"(");
    (*index)--;
    char *tree_code = strdup(index);
    return tree_code;
}

t_node* build_tree(char *tree_code){
    t_stack *stack = create(50);
    t_node *root = NULL;
    t_node *present = NULL;

    while(*tree_code){

        if(*tree_code == '('){
            tree_code++;
            continue;
        }

        if(*tree_code == ')'){
            present = pop(stack);
            tree_code++;
            continue;
        }

        if(*tree_code == ','){
            tree_code++;
            continue;
        }

        t_node *node = create_node(*tree_code);

        if(root == NULL) root = node;
        else{
            if(present->left == NULL) present->left = node;
            else present->right = node;
        }
        push(stack, node);
        present = node;
        tree_code++;
    }
    return root;
}

t_binary_tree* create_tree(){
    t_binary_tree *tree =  malloc (sizeof (t_binary_tree));
    tree->root = NULL;
    return tree;
}

t_node* create_node(char item){
    t_node *node =  malloc (sizeof (t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_tree(t_node *root, int height){
    if(root == NULL) return;
    print_tree(root->right, height + 1);
    for(int i = 0; i < height; i++){
        printf("    ");
    }
    printf("%c\n", root->item);
    print_tree(root->left, height + 1);
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

