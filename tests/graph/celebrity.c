#include <stdio.h>
#include <stdlib.h>

int celebrity(int n, int mat[n][n]);

static void runTest(char *name, int n, int mat[n][n], int expected) {
    int actual = celebrity(n, mat);
    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got %d, expected %d\n",
               actual == expected ? "PASS" : "FAIL", name, actual, expected);
    }
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
