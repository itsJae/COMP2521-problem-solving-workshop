#include "../Queue.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    Queue q = QueueNew();
    assert(QueueIsEmpty(q));
    assert(QueueSize(q) == 0);

    int a = 1, b = 2, c = 3;
    QueueEnqueue(q, &a);
    QueueEnqueue(q, &b);
    QueueEnqueue(q, &c);
    assert(QueueSize(q) == 3);

    assert(*(int *) QueuePeek(q) == 1);
    assert(*(int *) QueueDequeue(q) == 1); // FIFO
    assert(*(int *) QueueDequeue(q) == 2);
    assert(QueueSize(q) == 1);
    assert(*(int *) QueueDequeue(q) == 3);
    assert(QueueIsEmpty(q));

    // re-fill after draining, to check head/tail reset correctly
    int values[10];
    for (int i = 0; i < 10; i++) {
        values[i] = i;
        QueueEnqueue(q, &values[i]);
    }
    assert(QueueSize(q) == 10);
    for (int i = 0; i < 10; i++) {
        assert(*(int *) QueueDequeue(q) == i);
    }
    assert(QueueIsEmpty(q));

    QueueFree(q, NULL);
    printf("test_queue: all tests passed\n");
    return 0;
}
