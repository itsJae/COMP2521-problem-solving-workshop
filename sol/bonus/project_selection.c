#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Heap.h"

static int compareDesc(void *a, void *b) {
    return *(int *) b - *(int *) a;
}

int projectSelection(int R[], int W[], int n, int s, int k) {
    Heap h = HeapNew(compareDesc);
    int idx = 0;

    for (int picked = 0; picked < k; picked++) {
        while (idx < n && R[idx] <= s) {
            HeapInsert(h, &W[idx]);
            idx++;
        }
        s += *(int *) HeapExtract(h);
    }

    HeapFree(h, NULL);
    return s;
}
