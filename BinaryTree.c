#include "BinaryTree.h"

t_binary_tree* create_tree(){
    t_binary_tree *tree =  malloc (sizeof (t_binary_tree));
    tree->root = NULL;
    return tree;
}

void menu(t_binary_tree *tree){
    char *operation = "";
    while(strcmp(operation, "exit") != 0){
        char input[100];
        fgets(input, sizeof(input), stdin);
        remove_newline(input);
        operation = get_operation(input);

        if(strcmp(operation,"create") == 0){ //Tentei fazer com switch mas ele nao deixou :(
            char *tree_code = get_tree_code(input);
            if(!sequence_validation(tree_code)){
                printf("invalid\n");
                continue;
            };
            tree->root = build_tree(&tree_code);
            continue;
        }

       if(strcmp(operation,"pre") == 0){
            pre_order(tree->root);
            printf("\n");
            continue;
        }

        if(strcmp(operation,"in") == 0){
            in_order(tree->root);
            printf("\n");
            continue;
        }
        if(strcmp(operation, "post") == 0){
            post_order(tree->root);
            printf("\n");
            continue;
        }
        if(strcmp(operation, "height") == 0){
            char* target = get_height_target(input);
            target = strupr(target);
            int height = node_height(tree->root, target);

            if(height < 0) printf("Tree Node %s not found.\n", target);

            else printf("Height node %s : %d\n", target, height);

            continue;
        }

        if(strcmp(operation, "print") == 0){
            print_tree(tree->root, 0);
            printf("\n");
        }
    }
}

void remove_newline(char* input){
    size_t length = strlen(input);
    if (input[length - 1] == '\n') input[length - 1] = '\0';
}

char* get_operation(char* input){
    char delimiters[] = " :(";
    char *token = strdup(input); // Fiz isso para a string input permanecer a mesma
    char *operation = strtok(token, delimiters);
    return operation;
}

char* get_tree_code(char* input){
    char *ptr_index = strpbrk(input,"(");
    char *tree_code = strdup(ptr_index);
    return tree_code;
}

int sequence_validation(char *tree_code){
    int open = 0;
    int close = 0;
    int letters = letters_counter(tree_code);
    while (*tree_code != '\0' ){
        if (*tree_code == '(') open++;
        if (*tree_code == ')') close++;
        tree_code++;
    }
    if (open != close) return 0;
    int parenthesis_required = (letters *2) +1;
    if ( open == parenthesis_required) return 1;
    return 0;
}

int letters_counter(char* tree_code) {
    int count = 0;
    while(*tree_code != '\0') {
        if (isalpha(*tree_code)) count++;
        tree_code++;
    }
    return count;
}

t_node* build_tree(char** tree_code) {
    if(**tree_code == ')') (*tree_code)++;

    if(**tree_code == ',') (*tree_code)++;

    if (**tree_code == '(') {
        (*tree_code)++;

        if (**tree_code == ')') {
            (*tree_code)++;
            return NULL;
        }

        t_node* node = create_node(**tree_code);
        (*tree_code)++;
        node->left = build_tree(tree_code);
        node->right = build_tree(tree_code);
        return node;
    }
    (*tree_code)++;
}

t_node* create_node(char item){
    t_node *node =  malloc (sizeof (t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
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

char* get_height_target (char* input){
    char *ptr_index = strpbrk(input," ");
    return ptr_index+1;
}

int node_height(t_node* node, char* target) {
    if (node == NULL) return -1;
    if (node->item == *target) return 0;

    int left_height = node_height(node->left, target);
    int right_height = node_height(node->right, target);
    if (left_height!= -1) return left_height + 1;
    if (right_height!= -1) return right_height + 1;
    return -1;
}

void print_tree(t_node *root, int height) {
    if (root == NULL) {
        return;
    }

    if (root->right != NULL) {
        print_tree(root->right, height + 1);
    }

    for (int i = 0; i < height; i++) {
        printf("   ");
    }

    printf("%c\n", root->item);
    if (root->left != NULL) {
        print_tree(root->left, height + 1);
    }
}

void free_tree(t_node* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}
