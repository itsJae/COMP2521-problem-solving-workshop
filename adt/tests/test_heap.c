#include "../Heap.h"

#include <assert.h>
#include <stdio.h>

static int compareInt(void *a, void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    Heap h = HeapNew(compareInt);
    assert(HeapIsEmpty(h));

    int values[] = {5, 3, 8, 1, 9, 2, 7};
    int n = 7;
    for (int i = 0; i < n; i++) {
        HeapInsert(h, &values[i]);
    }
    assert(HeapSize(h) == n);

    // min-heap: extraction order should be sorted ascending
    int expected[] = {1, 2, 3, 5, 7, 8, 9};
    for (int i = 0; i < n; i++) {
        int got = *(int *) HeapExtract(h);
        assert(got == expected[i]);
    }
    assert(HeapIsEmpty(h));

    HeapFree(h, NULL);
    printf("test_heap: all tests passed\n");
    return 0;
}
