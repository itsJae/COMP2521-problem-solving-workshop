#include <stdlib.h>
#include "../../adt/Bst.h"

static int height(struct node *tree, int *diameter) {
    if (tree == NULL) return 0;

    int left = height(tree->left, diameter);
    int right = height(tree->right, diameter);
    if (left + right > *diameter) {
        *diameter = left + right;
    }
    return 1 + (left > right ? left : right);
}

int treeDiameter(struct node *tree) {
    int diameter = 0;
    height(tree, &diameter);
    return diameter;
}
