/**
 * Generic queue ADT (FIFO), backed by a singly linked list.
 * Stores void * items, so it works for any type.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue *Queue;

/**
 * Creates a new, empty queue
 */
Queue QueueNew(void);

/**
 * Frees all memory associated with the given queue.
 * freeItem may be NULL if items shouldn't be freed
 */
void QueueFree(Queue q, void (*freeItem)(void *item));

/**
 * Adds an item to the back of the queue
 */
void QueueEnqueue(Queue q, void *item);

/**
 * Removes and returns the item at the front of the queue
 */
void *QueueDequeue(Queue q);

/**
 * Returns the item at the front of the queue, without removing it
 */
void *QueuePeek(Queue q);

/**
 * Returns true if the queue has no items
 */
bool QueueIsEmpty(Queue q);

/**
 * Returns the number of items in the queue
 */
int QueueSize(Queue q);

#endif
