#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Queue.h"

void reverseQueue(Queue q);

static void runTest(char *name, int values[], int n, int expected[]) {
    Queue q = QueueNew();
    for (int i = 0; i < n; i++) {
        QueueEnqueue(q, &values[i]);
    }

    reverseQueue(q);

    int size = QueueSize(q);
    int result[size + 1];
    for (int i = 0; i < size; i++) {
        result[i] = *(int *) QueueDequeue(q);
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

    QueueFree(q, NULL);
}

int main(void) {
    runTest("test1", (int[]){1, 2, 3, 4, 5}, 5, (int[]){5, 4, 3, 2, 1});
    runTest("test2", NULL, 0, NULL);
    runTest("test3", (int[]){7}, 1, (int[]){7});
    runTest("test4", (int[]){1, 2}, 2, (int[]){2, 1});
    runTest("test5", (int[]){3, 3, 1}, 3, (int[]){1, 3, 3});
    runTest("test6", (int[]){-1, 0, 1}, 3, (int[]){1, 0, -1});
    return 0;
}
