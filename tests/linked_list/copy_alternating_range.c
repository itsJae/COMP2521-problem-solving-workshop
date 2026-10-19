#include <stdio.h>
#include <stdlib.h>
#include "../../adt/List.h"

struct node *copyAlternatingRange(struct node *list, int lo, int hi);

static void runTest(char *name, int values[], int size, int lo, int hi,
                    int expected[], int expectedSize) {
    struct node *list = listFromArray(values, size);
    struct node *result = copyAlternatingRange(list, lo, hi);
    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got ",
               listEquals(result, expected, expectedSize) ? "PASS" : "FAIL", name);
        listPrint(result);
        printf("\n");
    }
    listFree(list);
    listFree(result);
}

int main(void) {
    runTest("test1", (int[]){8, 3, 6, 2, 7, 5, 9, 4}, 8, 3, 8, (int[]){8, 6, 5}, 3);
    runTest("test2", (int[]){1, 2, 3, 4, 5}, 5, 1, 5, (int[]){1, 3, 5}, 3);
    runTest("test3", (int[]){1, 2, 3}, 3, 10, 20, NULL, 0);
    runTest("test4", NULL, 0, 0, 10, NULL, 0);
    runTest("test5", (int[]){10, 4, 20, 6}, 4, 4, 6, (int[]){4}, 1);
    return 0;
}
