#include <stdlib.h>
#include "../../adt/Bst.h"

static int countNodes(struct node *tree) {
    if (tree == NULL) return 0;
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int structuralDifference(struct node *t1, struct node *t2) {
    if (t1 == NULL && t2 == NULL) return 0;
    if (t1 == NULL) return 2 * countNodes(t2);
    if (t2 == NULL) return 2 * countNodes(t1);

    int diff = t1->value == t2->value ? 0 : 1;
    return diff + structuralDifference(t1->left, t2->left)
                + structuralDifference(t1->right, t2->right);
}
