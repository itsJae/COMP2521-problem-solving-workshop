/**
 * isSorted
 */

#include <stdbool.h>
#include <stdio.h>
#include "../adt/List.h"

/**
 * Returns true if the list is sorted in ascending order, false otherwise
 */
bool isSorted(struct node *list) {
    // TODO
    return false;
}

static void runTest(char *name, int values[], int size, bool expected) {
    struct node *list = listFromArray(values, size);
    bool actual = isSorted(list);
    printf("%-4s %-10s -> got %s, expected %s\n",
           actual == expected ? "PASS" : "FAIL", name,
           actual ? "true" : "false", expected ? "true" : "false");
    listFree(list);
}

int main(void) {
    runTest("test1", (int[]){1, 2, 3, 4}, 4, true);
    runTest("test2", (int[]){3, 1, 2, 4}, 4, false);
    runTest("test3", NULL, 0, true);
    runTest("test4", (int[]){5}, 1, true);
    runTest("test5", (int[]){1, 2, 2, 3}, 4, true);
    runTest("test6", (int[]){1, 2, 3, 0}, 4, false);
    return 0;
}
