/**
 * celebrity
 * https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
 */

#include <stdio.h>
#include <stdlib.h>
#include "../adt/Stack.h"

/**
 * mat[i][j] == 1 if person i knows person j. A celebrity is known by
 * everyone else and knows no one else. Returns the index of the
 * celebrity, or -1 if there is none.
 */
int celebrity(int n, int mat[n][n]) {
    // TODO
    return -2;
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
