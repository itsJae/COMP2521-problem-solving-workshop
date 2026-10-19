/**
 * Min-priority-queue: wraps Heap so callers pass an explicit int priority
 * instead of writing their own comparator. Lowest priority dequeues first.
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

typedef struct priorityQueue *PriorityQueue;

/**
 * Creates a new, empty priority queue
 */
PriorityQueue PQNew(void);

/**
 * Frees all memory associated with the given priority queue.
 * freeItem may be NULL if items shouldn't be freed
 */
void PQFree(PriorityQueue pq, void (*freeItem)(void *item));

/**
 * Inserts an item with the given priority
 */
void PQInsert(PriorityQueue pq, void *item, int priority);

/**
 * Removes and returns the item with the lowest priority
 */
void *PQExtractMin(PriorityQueue pq);

/**
 * Returns the item with the lowest priority, without removing it
 */
void *PQPeek(PriorityQueue pq);

/**
 * Returns true if the priority queue has no items
 */
bool PQIsEmpty(PriorityQueue pq);

/**
 * Returns the number of items in the priority queue
 */
int PQSize(PriorityQueue pq);

#endif
