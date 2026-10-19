#include <stdio.h>
#include "../../adt/Bst.h"

int treeDiameter(struct node *tree);

static struct node *buildTree(int values[], int size) {
    struct node *tree = bstNew();
    for (int i = 0; i < size; i++) {
        tree = bstInsert(tree, values[i]);
    }
    return tree;
}

static void runTest(char *name, int values[], int size, int expected) {
    struct node *tree = buildTree(values, size);
    int actual = treeDiameter(tree);
    printf("%-4s %-10s -> got %d, expected %d\n",
           actual == expected ? "PASS" : "FAIL", name, actual, expected);
    bstFree(tree);
}

int main(void) {
    runTest("test1", (int[]){7, 3, 2, 1, 6, 4, 5, 8}, 8, 5);
    runTest("test2", (int[]){5, 4, 2, 1, 3, 6, 7}, 7, 5);
    runTest("test3", NULL, 0, 0);
    runTest("test4", (int[]){1}, 1, 0);
    runTest("test5", (int[]){2, 1, 3}, 3, 2);
    runTest("test6", (int[]){1, 2, 3, 4}, 4, 3);
    return 0;
}
