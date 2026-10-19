#include "../Bst.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    struct node *tree = bstNew();
    assert(tree == NULL);

    int values[] = {4, 2, 6, 1, 3, 5, 4};
    for (int i = 0; i < 7; i++) {
        tree = bstInsert(tree, values[i]);
    }

    assert(tree->value == 4);
    assert(tree->left->value == 2);
    assert(tree->right->value == 6);
    assert(tree->left->left->value == 1);
    assert(tree->left->right->value == 3);
    assert(tree->right->left->value == 5);
    assert(tree->right->right == NULL);

    bstFree(tree);
    printf("test_bst: all tests passed\n");
    return 0;
}
