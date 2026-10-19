#include "Queue.h"

#include <stdlib.h>
#include <assert.h>

typedef struct node {
    void *item;
    struct node *next;
} *Node;

struct queue {
    Node head;
    Node tail;
    int size;
};

Queue QueueNew(void) {
    Queue q = malloc(sizeof(*q));
    assert(q != NULL);
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void QueueFree(Queue q, void (*freeItem)(void *item)) {
    Node curr = q->head;
    while (curr != NULL) {
        Node next = curr->next;
        if (freeItem != NULL) freeItem(curr->item);
        free(curr);
        curr = next;
    }
    free(q);
}

void QueueEnqueue(Queue q, void *item) {
    Node n = malloc(sizeof(*n));
    assert(n != NULL);
    n->item = item;
    n->next = NULL;

    if (q->tail == NULL) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    q->size++;
}

void *QueueDequeue(Queue q) {
    assert(q->head != NULL);
    Node n = q->head;
    void *item = n->item;

    q->head = n->next;
    if (q->head == NULL) q->tail = NULL;
    free(n);
    q->size--;
    return item;
}

void *QueuePeek(Queue q) {
    assert(q->head != NULL);
    return q->head->item;
}

bool QueueIsEmpty(Queue q) {
    return q->size == 0;
}

int QueueSize(Queue q) {
    return q->size;
}
