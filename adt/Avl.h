/**
 * Generic AVL tree (a self-balancing binary search tree).
 * Caller supplies a comparator: cmp(a, b) < 0 means 'a' is smaller than
 * 'b'. Duplicate items are allowed.
 */

#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

typedef int (*CompareFn)(void *a, void *b);

typedef struct avl *Avl;

/**
 * Creates a new, empty AVL tree that orders items using cmp
 */
Avl AvlNew(CompareFn cmp);

/**
 * Frees all memory associated with the given tree.
 * freeItem may be NULL if items shouldn't be freed
 */
void AvlFree(Avl t, void (*freeItem)(void *item));

/**
 * Inserts an item into the tree in O(log n) time
 */
void AvlInsert(Avl t, void *item);

/**
 * Returns the smallest item in the tree, without removing it
 */
void *AvlMin(Avl t);

/**
 * Returns the largest item in the tree, without removing it
 */
void *AvlMax(Avl t);

/**
 * Removes and returns the smallest item in O(log n) time
 */
void *AvlDeleteMin(Avl t);

/**
 * Removes and returns the largest item in O(log n) time
 */
void *AvlDeleteMax(Avl t);

/**
 * Returns true if the tree has no items
 */
bool AvlIsEmpty(Avl t);

/**
 * Returns the number of items in the tree
 */
int AvlSize(Avl t);

#endif
