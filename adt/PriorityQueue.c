#include "PriorityQueue.h"
#include "Heap.h"

#include <stdlib.h>
#include <assert.h>

typedef struct pqNode {
    void *item;
    int priority;
} *PQNode;

struct priorityQueue {
    Heap heap;
};

static int comparePriority(void *a, void *b) {
    PQNode na = a;
    PQNode nb = b;
    return na->priority - nb->priority;
}

PriorityQueue PQNew(void) {
    PriorityQueue pq = malloc(sizeof(*pq));
    assert(pq != NULL);
    pq->heap = HeapNew(comparePriority);
    return pq;
}

static void freePQNode(void *n) {
    free(n);
}

void PQFree(PriorityQueue pq, void (*freeItem)(void *item)) {
    while (!HeapIsEmpty(pq->heap)) {
        PQNode n = HeapExtract(pq->heap);
        if (freeItem != NULL) freeItem(n->item);
        freePQNode(n);
    }
    HeapFree(pq->heap, NULL);
    free(pq);
}

void PQInsert(PriorityQueue pq, void *item, int priority) {
    PQNode n = malloc(sizeof(*n));
    assert(n != NULL);
    n->item = item;
    n->priority = priority;
    HeapInsert(pq->heap, n);
}

void *PQExtractMin(PriorityQueue pq) {
    PQNode n = HeapExtract(pq->heap);
    void *item = n->item;
    freePQNode(n);
    return item;
}

void *PQPeek(PriorityQueue pq) {
    PQNode n = HeapPeek(pq->heap);
    return n->item;
}

bool PQIsEmpty(PriorityQueue pq) {
    return HeapIsEmpty(pq->heap);
}

int PQSize(PriorityQueue pq) {
    return HeapSize(pq->heap);
}
