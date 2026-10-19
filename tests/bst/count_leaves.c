#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Bst.h"

int countLeaves(struct node *tree);

static struct node *buildTree(int values[], int size) {
    struct node *tree = bstNew();
    for (int i = 0; i < size; i++) {
        tree = bstInsert(tree, values[i]);
    }
    return tree;
}

static void runTest(char *name, int values[], int size, int expected) {
    struct node *tree = buildTree(values, size);
    int actual = countLeaves(tree);
    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got %d, expected %d\n",
               actual == expected ? "PASS" : "FAIL", name, actual, expected);
    }
    bstFree(tree);
}

int main(void) {
    runTest("test1", (int[]){4, 2, 6, 1, 3, 5}, 6, 3);
    runTest("test2", NULL, 0, 0);
    runTest("test3", (int[]){1}, 1, 1);
    runTest("test4", (int[]){1, 2, 3, 4}, 4, 1);
    runTest("test5", (int[]){5, 3, 8, 1, 4, 7, 9}, 7, 4);
    return 0;
}
