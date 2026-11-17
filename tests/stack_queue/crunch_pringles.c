#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Stack.h"

void removeSoggy(Stack tube, Stack bowl);

static void runTest(char *name, int chips[], int n, int expected[], int m) {
    Stack tube = StackNew();
    Stack bowl = StackNew();
    for (int i = 0; i < n; i++) {
        StackPush(tube, &chips[i]);
    }

    removeSoggy(tube, bowl);

    int size = StackSize(tube);
    int result[size + 1];
    for (int i = size - 1; i >= 0; i--) {
        result[i] = *(int *) StackPop(tube);
    }

    bool pass = size == m && StackIsEmpty(bowl);
    for (int i = 0; pass && i < m; i++) {
        pass = result[i] == expected[i];
    }

    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got [", pass ? "PASS" : "FAIL", name);
        for (int i = 0; i < size; i++) {
            printf("%d%s", result[i], i < size - 1 ? ", " : "");
        }
        printf("]\n");
    }

    StackFree(tube, NULL);
    StackFree(bowl, NULL);
}

int main(void) {
    runTest("test1", (int[]){3, 0, 4, 0, 2}, 5, (int[]){3, 4, 2}, 3);
    runTest("test2", (int[]){0, 1, 0, 2, 0}, 5, (int[]){1, 2}, 2);
    runTest("test3", NULL, 0, NULL, 0);
    runTest("test4", (int[]){0}, 1, NULL, 0);
    runTest("test5", (int[]){0, 0, 0}, 3, NULL, 0);
    runTest("test6", (int[]){7, 1, 0}, 3, (int[]){7, 1}, 2);
    runTest("test7", (int[]){5, 5, 2}, 3, (int[]){5, 5, 2}, 3);
    return 0;
}
