#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool mollyTea(int prices[], int n, int k, int *i, int *j);

static void runTest(char *name, int prices[], int n, int k, bool expected) {
    int i = -1;
    int j = -1;
    bool found = mollyTea(prices, n, k, &i, &j);
    bool valid = !found || (i >= 0 && i < n && j >= 0 && j < n && i != j &&
                            prices[i] + prices[j] == k);
    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got %s (%d, %d), expected %s\n",
               found == expected && valid ? "PASS" : "FAIL", name,
               found ? "true" : "false", i, j, expected ? "true" : "false");
    }
}

int main(void) {
    runTest("test1", (int[]){3, 1, 4, 2}, 4, 6, true);
    runTest("test2", (int[]){2, 7, 11, 15}, 4, 9, true);
    runTest("test3", (int[]){1, 2, 3}, 3, 7, false);
    runTest("test4", (int[]){3, 4}, 2, 6, false);
    runTest("test5", (int[]){3, 3, 4}, 3, 6, true);
    runTest("test6", (int[]){5}, 1, 10, false);
    runTest("test7", NULL, 0, 1, false);
    return 0;
}
