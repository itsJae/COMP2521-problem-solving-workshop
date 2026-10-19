#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void dailyTemperatures(int temperatures[], int n, int answer[]);

static void runTest(char *name, int temperatures[], int n, int expected[]) {
    int *answer = malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        answer[i] = -1;
    }

    dailyTemperatures(temperatures, n, answer);

    bool pass = true;
    for (int i = 0; pass && i < n; i++) {
        pass = answer[i] == expected[i];
    }

    if (getenv("AUTOTEST") != NULL) {
        printf("%-4s %-10s -> got ", pass ? "PASS" : "FAIL", name);
        if (n > 20) {
            printf("%s answer (n = %d)\n", pass ? "correct" : "wrong", n);
        } else {
            printf("[");
            for (int i = 0; i < n; i++) {
                printf("%d%s", answer[i], i < n - 1 ? ", " : "");
            }
            printf("]\n");
        }
    }

    free(answer);
}

int main(void) {
    runTest("test1", (int[]){73, 74, 75, 71, 69, 72, 76, 73}, 8, (int[]){1, 1, 4, 2, 1, 1, 0, 0});
    runTest("test2", (int[]){30, 40, 50, 60}, 4, (int[]){1, 1, 1, 0});
    runTest("test3", (int[]){30, 60, 90}, 3, (int[]){1, 1, 0});
    runTest("test4", NULL, 0, NULL);
    runTest("test5", (int[]){50}, 1, (int[]){0});
    runTest("test6", (int[]){60, 50, 40, 30}, 4, (int[]){0, 0, 0, 0});
    runTest("test7", (int[]){70, 70, 71}, 3, (int[]){2, 1, 0});

    // An O(n^2) solution is too slow for this one
    int n = 200000;
    int *temperatures = malloc(n * sizeof(int));
    int *expected = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        temperatures[i] = n - i;
    }
    runTest("test8", temperatures, n, expected);
    free(temperatures);
    free(expected);

    return 0;
}
