#include "Heap.h"

#include <stdlib.h>
#include <assert.h>

struct heap {
    void **items;
    int size;
    int capacity;
    CompareFn cmp;
};

#define INITIAL_CAPACITY 8

static void swap(Heap h, int i, int j) {
    void *tmp = h->items[i];
    h->items[i] = h->items[j];
    h->items[j] = tmp;
}

static void siftUp(Heap h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->cmp(h->items[i], h->items[parent]) >= 0) break;
        swap(h, i, parent);
        i = parent;
    }
}

static void siftDown(Heap h, int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < h->size && h->cmp(h->items[left], h->items[smallest]) < 0) {
            smallest = left;
        }
        if (right < h->size && h->cmp(h->items[right], h->items[smallest]) < 0) {
            smallest = right;
        }
        if (smallest == i) break;

        swap(h, i, smallest);
        i = smallest;
    }
}

Heap HeapNew(CompareFn cmp) {
    Heap h = malloc(sizeof(*h));
    assert(h != NULL);
    h->items = malloc(INITIAL_CAPACITY * sizeof(void *));
    assert(h->items != NULL);
    h->size = 0;
    h->capacity = INITIAL_CAPACITY;
    h->cmp = cmp;
    return h;
}

void HeapFree(Heap h, void (*freeItem)(void *item)) {
    if (freeItem != NULL) {
        for (int i = 0; i < h->size; i++) {
            freeItem(h->items[i]);
        }
    }
    free(h->items);
    free(h);
}

void HeapInsert(Heap h, void *item) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->items = realloc(h->items, h->capacity * sizeof(void *));
        assert(h->items != NULL);
    }
    h->items[h->size] = item;
    h->size++;
    siftUp(h, h->size - 1);
}

void *HeapExtract(Heap h) {
    assert(h->size > 0);
    void *top = h->items[0];
    h->size--;
    h->items[0] = h->items[h->size];
    if (h->size > 0) siftDown(h, 0);
    return top;
}

void *HeapPeek(Heap h) {
    assert(h->size > 0);
    return h->items[0];
}

bool HeapIsEmpty(Heap h) {
    return h->size == 0;
}

int HeapSize(Heap h) {
    return h->size;
}
