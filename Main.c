#include "BinaryTree.h"

int main(){
    t_binary_tree *tree = create_tree();
    menu(tree);
    free(tree);
}