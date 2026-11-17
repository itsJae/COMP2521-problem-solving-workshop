#include "Avl.h"

#include <assert.h>
#include <stdlib.h>

struct node {
    void *item;
    int height;
    struct node *left;
    struct node *right;
};

struct avl {
    struct node *root;
    int size;
    CompareFn cmp;
};

static int height(struct node *n) {
    return n == NULL ? 0 : n->height;
}

static void updateHeight(struct node *n) {
    int left = height(n->left);
    int right = height(n->right);
    n->height = 1 + (left > right ? left : right);
}

static struct node *rotateRight(struct node *n) {
    struct node *newRoot = n->left;
    n->left = newRoot->right;
    newRoot->right = n;
    updateHeight(n);
    updateHeight(newRoot);
    return newRoot;
}

static struct node *rotateLeft(struct node *n) {
    struct node *newRoot = n->right;
    n->right = newRoot->left;
    newRoot->left = n;
    updateHeight(n);
    updateHeight(newRoot);
    return newRoot;
}

static struct node *rebalance(struct node *n) {
    updateHeight(n);
    int balance = height(n->left) - height(n->right);
    if (balance > 1) {
        if (height(n->left->left) < height(n->left->right)) {
            n->left = rotateLeft(n->left);
        }
        return rotateRight(n);
    }
    if (balance < -1) {
        if (height(n->right->right) < height(n->right->left)) {
            n->right = rotateRight(n->right);
        }
        return rotateLeft(n);
    }
    return n;
}

static struct node *doInsert(struct node *n, void *item, CompareFn cmp) {
    if (n == NULL) {
        struct node *new = malloc(sizeof(*new));
        assert(new != NULL);
        new->item = item;
        new->height = 1;
        new->left = NULL;
        new->right = NULL;
        return new;
    }

    if (cmp(item, n->item) < 0) {
        n->left = doInsert(n->left, item, cmp);
    } else {
        n->right = doInsert(n->right, item, cmp);
    }
    return rebalance(n);
}

static struct node *doDeleteMin(struct node *n, void **item) {
    if (n->left == NULL) {
        struct node *right = n->right;
        *item = n->item;
        free(n);
        return right;
    }
    n->left = doDeleteMin(n->left, item);
    return rebalance(n);
}

static struct node *doDeleteMax(struct node *n, void **item) {
    if (n->right == NULL) {
        struct node *left = n->left;
        *item = n->item;
        free(n);
        return left;
    }
    n->right = doDeleteMax(n->right, item);
    return rebalance(n);
}

static void doFree(struct node *n, void (*freeItem)(void *item)) {
    if (n == NULL) return;
    doFree(n->left, freeItem);
    doFree(n->right, freeItem);
    if (freeItem != NULL) {
        freeItem(n->item);
    }
    free(n);
}

Avl AvlNew(CompareFn cmp) {
    Avl t = malloc(sizeof(*t));
    assert(t != NULL);
    t->root = NULL;
    t->size = 0;
    t->cmp = cmp;
    return t;
}

void AvlFree(Avl t, void (*freeItem)(void *item)) {
    doFree(t->root, freeItem);
    free(t);
}

void AvlInsert(Avl t, void *item) {
    t->root = doInsert(t->root, item, t->cmp);
    t->size++;
}

void *AvlMin(Avl t) {
    assert(t->root != NULL);
    struct node *n = t->root;
    while (n->left != NULL) {
        n = n->left;
    }
    return n->item;
}

void *AvlMax(Avl t) {
    assert(t->root != NULL);
    struct node *n = t->root;
    while (n->right != NULL) {
        n = n->right;
    }
    return n->item;
}

void *AvlDeleteMin(Avl t) {
    assert(t->root != NULL);
    void *item;
    t->root = doDeleteMin(t->root, &item);
    t->size--;
    return item;
}

void *AvlDeleteMax(Avl t) {
    assert(t->root != NULL);
    void *item;
    t->root = doDeleteMax(t->root, &item);
    t->size--;
    return item;
}

bool AvlIsEmpty(Avl t) {
    return t->size == 0;
}

int AvlSize(Avl t) {
    return t->size;
}
