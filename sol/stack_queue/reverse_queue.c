#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Queue.h"
#include "../../adt/Stack.h"

void reverseQueue(Queue q) {
    Stack s = StackNew();
    while (!QueueIsEmpty(q)) {
        StackPush(s, QueueDequeue(q));
    }
    while (!StackIsEmpty(s)) {
        QueueEnqueue(q, StackPop(s));
    }
    StackFree(s, NULL);
}
