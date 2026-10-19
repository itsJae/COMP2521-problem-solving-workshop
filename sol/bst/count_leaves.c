#include <stdlib.h>
#include "../../adt/Bst.h"

int countLeaves(struct node *tree) {
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return countLeaves(tree->left) + countLeaves(tree->right);
}
