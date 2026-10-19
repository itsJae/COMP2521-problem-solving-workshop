#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Stack.h"

void sortTube(Stack tube, Stack bowl);

static void runTest(char *name, int chips[], int n, int expected[]) {
    Stack tube = StackNew();
    Stack bowl = StackNew();
    for (int i = 0; i < n; i++) {
        StackPush(tube, &chips[i]);
    }

    sortTube(tube, bowl);

    int size = StackSize(tube);
    int result[size + 1];
    for (int i = size - 1; i >= 0; i--) {
        result[i] = *(int *) StackPop(tube);
    }

    bool pass = size == n;
    for (int i = 0; pass && i < n; i++) {
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
    runTest("test1", (int[]){3, 1, 4, 2}, 4, (int[]){1, 2, 3, 4});
    runTest("test2", (int[]){5, 5, 2}, 3, (int[]){2, 5, 5});
    runTest("test3", NULL, 0, NULL);
    runTest("test4", (int[]){7}, 1, (int[]){7});
    runTest("test5", (int[]){1, 2, 3, 4}, 4, (int[]){1, 2, 3, 4});
    runTest("test6", (int[]){4, 3, 2, 1}, 4, (int[]){1, 2, 3, 4});
    runTest("test7", (int[]){-1, 3, -5, 0}, 4, (int[]){-5, -1, 0, 3});
    return 0;
}
