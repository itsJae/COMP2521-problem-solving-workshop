/**
 * Binary search tree of ints
 */

#ifndef BST_H
#define BST_H

struct node {
    int value;
    struct node *left;
    struct node *right;
};

/**
 * Returns a new empty BST
 */
struct node *bstNew(void);

/**
 * Frees all memory associated with the given BST
 */
void bstFree(struct node *tree);

/**
 * Inserts a value into the BST and returns the root of the updated BST
 */
struct node *bstInsert(struct node *tree, int val);

#endif
