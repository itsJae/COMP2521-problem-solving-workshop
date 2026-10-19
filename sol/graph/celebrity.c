#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Stack.h"

int celebrity(int n, int mat[n][n]) {
    int *people = malloc(n * sizeof(int));
    Stack s = StackNew();
    for (int i = 0; i < n; i++) {
        people[i] = i;
        StackPush(s, &people[i]);
    }

    while (StackSize(s) > 1) {
        int a = *(int *) StackPop(s);
        int b = *(int *) StackPop(s);
        if (mat[a][b]) {
            StackPush(s, &people[b]);
        } else {
            StackPush(s, &people[a]);
        }
    }

    int candidate = *(int *) StackPop(s);
    StackFree(s, NULL);
    free(people);

    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        if (mat[candidate][i] || !mat[i][candidate]) return -1;
    }
    return candidate;
}

static void runTest(char *name, int n, int mat[n][n], int expected) {
    int actual = celebrity(n, mat);
    printf("%-4s %-10s -> got %d, expected %d\n",
           actual == expected ? "PASS" : "FAIL", name, actual, expected);
}

int main(void) {
    runTest("test1", 3, (int[3][3]){{0, 1, 0}, {0, 0, 0}, {0, 1, 0}}, 1);
    runTest("test2", 2, (int[2][2]){{0, 1}, {1, 0}}, -1);
    runTest("test3", 1, (int[1][1]){{0}}, 0);
    runTest("test4", 3, (int[3][3]){{1, 1, 0}, {0, 1, 0}, {0, 1, 1}}, 1);
    runTest("test5", 3, (int[3][3]){{0, 1, 1}, {0, 0, 1}, {0, 1, 0}}, -1);
    runTest("test6", 4, (int[4][4]){{0, 0, 1, 1}, {1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 0, 0}}, 3);
    return 0;
}
