#include "../Stack.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    Stack s = StackNew();
    assert(StackIsEmpty(s));
    assert(StackSize(s) == 0);

    int a = 1, b = 2, c = 3;
    StackPush(s, &a);
    StackPush(s, &b);
    StackPush(s, &c);
    assert(StackSize(s) == 3);
    assert(!StackIsEmpty(s));

    assert(*(int *) StackPeek(s) == 3);
    assert(*(int *) StackPop(s) == 3); // LIFO
    assert(*(int *) StackPop(s) == 2);
    assert(StackSize(s) == 1);
    assert(*(int *) StackPop(s) == 1);
    assert(StackIsEmpty(s));

    // resize past initial capacity
    int values[20];
    for (int i = 0; i < 20; i++) {
        values[i] = i;
        StackPush(s, &values[i]);
    }
    assert(StackSize(s) == 20);
    for (int i = 19; i >= 0; i--) {
        assert(*(int *) StackPop(s) == i);
    }
    assert(StackIsEmpty(s));

    StackFree(s, NULL);
    printf("test_stack: all tests passed\n");
    return 0;
}
