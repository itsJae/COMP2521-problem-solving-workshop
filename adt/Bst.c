#include "Bst.h"

#include <assert.h>
#include <stdlib.h>

static struct node *newNode(int val) {
    struct node *n = malloc(sizeof(*n));
    assert(n != NULL);
    n->value = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *bstNew(void) {
    return NULL;
}

void bstFree(struct node *tree) {
    if (tree == NULL) return;
    bstFree(tree->left);
    bstFree(tree->right);
    free(tree);
}

struct node *bstInsert(struct node *tree, int val) {
    if (tree == NULL) {
        return newNode(val);
    } else if (val < tree->value) {
        tree->left = bstInsert(tree->left, val);
    } else if (val > tree->value) {
        tree->right = bstInsert(tree->right, val);
    }
    return tree;
}
