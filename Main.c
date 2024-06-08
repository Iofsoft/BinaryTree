#include "BinaryTree.h"

int main(){
    t_binary_tree *tree = create_tree();
    menu(tree);
    free_tree(tree->root);
    free(tree);
}