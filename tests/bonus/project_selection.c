#include <stdio.h>
#include <stdlib.h>

int projectSelection(int R[], int W[], int n, int s, int k);

static void runTest(char *name, int R[], int W[], int n, int s, int k, int expected) {
    int actual = projectSelection(R, W, n, s, k);
    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got %d, expected %d\n",
               actual == expected ? "PASS" : "FAIL", name, actual, expected);
    }
}

int main(void) {
    runTest("test1", (int[]){1, 2, 2, 3, 4}, (int[]){2, 3, 1, 4, 10}, 5, 2, 3, 19);
    runTest("test2", (int[]){0, 1, 2}, (int[]){1, 2, 3}, 3, 0, 2, 3);
    runTest("test3", (int[]){0, 0, 0}, (int[]){1, 2, 3}, 3, 0, 2, 5);
    runTest("test4", (int[]){0, 2, 5, 10}, (int[]){5, 1, 10, 2}, 4, 0, 3, 17);
    runTest("test5", (int[]){0, 0, 0}, (int[]){5, 100, 1}, 3, 0, 1, 100);
    runTest("test6", (int[]){0, 0, 0}, (int[]){3, 1, 2}, 3, 0, 3, 6);
    runTest("test7", (int[]){0, 1, 1, 5}, (int[]){1, 4, 3, 2}, 4, 0, 2, 5);
    runTest("test8", (int[]){0, 0, 0, 1}, (int[]){5, 1, 1, 100}, 4, 0, 2, 105);

    // Scanning every project before each pick is O(nk), which is too slow here.
    // Every project is affordable and W[i] = i % 100, so the best 100000
    // projects are the 2000 copies of each value from 50 to 99.
    int n = 200000;
    int *R = calloc(n, sizeof(int));
    int *W = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        W[i] = i % 100;
    }
    runTest("test9", R, W, n, 0, 100000, 2000 * (50 + 99) * 50 / 2);
    free(R);
    free(W);
    return 0;
}
