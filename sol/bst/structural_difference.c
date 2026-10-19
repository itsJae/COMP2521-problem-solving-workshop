#include <stdio.h>
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

static struct node *buildTree(int values[], int size) {
    struct node *tree = bstNew();
    for (int i = 0; i < size; i++) {
        tree = bstInsert(tree, values[i]);
    }
    return tree;
}

static void runTest(char *name, int values1[], int size1,
                    int values2[], int size2, int expected) {
    struct node *t1 = buildTree(values1, size1);
    struct node *t2 = buildTree(values2, size2);
    int actual = structuralDifference(t1, t2);
    printf("%-4s %-10s -> got %d, expected %d\n",
           actual == expected ? "PASS" : "FAIL", name, actual, expected);
    bstFree(t1);
    bstFree(t2);
}

int main(void) {
    runTest("test1", (int[]){8, 3, 10, 14}, 4, (int[]){8, 4, 10, 1}, 4, 5);
    runTest("test2", (int[]){2, 1, 3}, 3, (int[]){2, 1, 3}, 3, 0);
    runTest("test3", NULL, 0, NULL, 0, 0);
    runTest("test4", NULL, 0, (int[]){2, 1, 3}, 3, 6);
    runTest("test5", (int[]){2, 1, 3}, 3, (int[]){5, 4, 6}, 3, 3);
    return 0;
}
