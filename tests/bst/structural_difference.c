#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Bst.h"

int structuralDifference(struct node *t1, struct node *t2);

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
    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got %d, expected %d\n",
               actual == expected ? "PASS" : "FAIL", name, actual, expected);
    }
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
