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
