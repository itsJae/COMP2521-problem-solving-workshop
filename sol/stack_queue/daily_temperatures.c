#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Stack.h"

void dailyTemperatures(int temperatures[], int n, int answer[]) {
    int *days = malloc(n * sizeof(int));
    Stack s = StackNew();

    for (int i = 0; i < n; i++) {
        days[i] = i;
        answer[i] = 0;

        while (!StackIsEmpty(s) && temperatures[*(int *) StackPeek(s)] < temperatures[i]) {
            int prev = *(int *) StackPop(s);
            answer[prev] = i - prev;
        }
        StackPush(s, &days[i]);
    }

    StackFree(s, NULL);
    free(days);
}
