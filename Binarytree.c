#include "BinaryTree.h"

void menu(t_binary_tree *tree){
    char *operation = "";
    while(strcmp(operation, "exit") != 0){
        printf("\n");
        char input[100];
        fgets(input, sizeof(input), stdin);
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        operation = get_operation(input);
        if(strcmp(operation,"create") == 0){
            char *tree_code = get_tree_code(input);
            int index = 0;
            tree->root = build_tree(tree_code, &index);
            continue;
        }

        if(strcmp(operation,"pre") == 0){
            pre_order(tree->root);
            continue;
        }

        if(strcmp(operation,"in") == 0){
            in_order(tree->root);
            continue;
        }
        if(strcmp(operation, "post") == 0){
            post_order(tree->root);
            continue;
        }
        if(strcmp(operation, "height") == 0){
            continue;
        }

        if(strcmp(operation, "print") == 0){
            print_tree(tree->root, 0);
        }
    }
}

char* get_operation(char* input){
    char delimiters[] = " :(";
    char *operation;
    char *token = strdup(input); // Fiz isso para a string input permanecer a mesma
    operation = strtok(token, delimiters);
    return operation;
}

char* get_tree_code(char* input){
    char *index = strpbrk(input,"(");
    char *tree_code = strdup(index);
    return tree_code;
}
t_node* build_tree(char* tree_code, int* index) {
    t_node* node = NULL;
    if (tree_code[*index] == '(') {
        *index += 1;
        node = build_tree(tree_code, index);
    } else if (tree_code[*index] >= 'A' && tree_code[*index] <= 'Z') {
        node = create_node(tree_code[*index]);
        *index += 1;
    }
    if (tree_code[*index] == ',') {
        *index += 1;
        if (node!= NULL) {
            node->left = build_tree(tree_code, index);
        }
    }
    if (tree_code[*index] == ')') {
        *index += 1;
        return node;
    }
    if (node!= NULL) {
        node->right = build_tree(tree_code, index);
    }
    return node;
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
        printf("%c ", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%c ", node->item);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->item);
    }
}

