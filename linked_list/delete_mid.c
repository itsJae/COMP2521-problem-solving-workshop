/**
 * deleteMid
 */

#include <stdio.h>
#include <stdlib.h>
#include "../adt/List.h"

/**
 * Deletes the middle node (index n / 2) of a non-empty list and returns
 * the head of the updated list
 */
struct node *deleteMid(struct node *list) {
    // TODO
    return list;
}

static void runTest(char *name, int values[], int size,
                    int expected[], int expectedSize) {
    struct node *result = deleteMid(listFromArray(values, size));
    printf("%-4s %-10s -> got ",
           listEquals(result, expected, expectedSize) ? "PASS" : "FAIL", name);
    listPrint(result);
    printf("\n");
    listFree(result);
}

int main(void) {
    runTest("test1", (int[]){1, 3, 5, 7, 9}, 5, (int[]){1, 3, 7, 9}, 4);
    runTest("test2", (int[]){1, 2, 3, 4}, 4, (int[]){1, 2, 4}, 3);
    runTest("test3", (int[]){1, 2}, 2, (int[]){1}, 1);
    runTest("test4", (int[]){1}, 1, NULL, 0);
    runTest("test5", (int[]){1, 2, 3}, 3, (int[]){1, 3}, 2);
    return 0;
}
