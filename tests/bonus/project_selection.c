#include <stdio.h>

int projectSelection(int R[], int W[], int n, int s, int k);

static void runTest(char *name, int R[], int W[], int n, int s, int k, int expected) {
    int actual = projectSelection(R, W, n, s, k);
    printf("%-4s %-10s -> got %d, expected %d\n",
           actual == expected ? "PASS" : "FAIL", name, actual, expected);
}

int main(void) {
    runTest("test1", (int[]){1, 2, 2, 3, 4}, (int[]){2, 3, 1, 4, 10}, 5, 2, 3, 19);
    runTest("test2", (int[]){0, 1, 2}, (int[]){1, 2, 3}, 3, 0, 2, 3);
    runTest("test3", (int[]){0, 0, 0}, (int[]){1, 2, 3}, 3, 0, 2, 5);
    runTest("test4", (int[]){0, 2, 5, 10}, (int[]){5, 1, 10, 2}, 4, 0, 3, 17);
    runTest("test5", (int[]){0, 0, 0}, (int[]){5, 100, 1}, 3, 0, 1, 100);
    runTest("test6", (int[]){0, 0, 0}, (int[]){3, 1, 2}, 3, 0, 3, 6);
    return 0;
}
