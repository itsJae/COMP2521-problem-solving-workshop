/**
 * Generic binary heap, backed by a dynamic array.
 * Caller supplies a comparator: cmp(a, b) < 0 means 'a' comes out before
 * 'b' (so a "less than" comparator gives a min-heap, a "greater than"
 * comparator gives a max-heap).
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef int (*CompareFn)(void *a, void *b);

typedef struct heap *Heap;

/**
 * Creates a new, empty heap that orders items using cmp
 */
Heap HeapNew(CompareFn cmp);

/**
 * Frees all memory associated with the given heap.
 * freeItem may be NULL if items shouldn't be freed
 */
void HeapFree(Heap h, void (*freeItem)(void *item));

/**
 * Inserts an item into the heap
 */
void HeapInsert(Heap h, void *item);

/**
 * Removes and returns the item at the top of the heap
 */
void *HeapExtract(Heap h);

/**
 * Returns the item at the top of the heap, without removing it
 */
void *HeapPeek(Heap h);

/**
 * Returns true if the heap has no items
 */
bool HeapIsEmpty(Heap h);

/**
 * Returns the number of items in the heap
 */
int HeapSize(Heap h);

#endif
