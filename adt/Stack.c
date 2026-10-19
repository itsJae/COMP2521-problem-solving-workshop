#include "Stack.h"

#include <stdlib.h>
#include <assert.h>

struct stack {
    void **items;
    int size;
    int capacity;
};

#define INITIAL_CAPACITY 8

Stack StackNew(void) {
    Stack s = malloc(sizeof(*s));
    assert(s != NULL);
    s->items = malloc(INITIAL_CAPACITY * sizeof(void *));
    assert(s->items != NULL);
    s->size = 0;
    s->capacity = INITIAL_CAPACITY;
    return s;
}

void StackFree(Stack s, void (*freeItem)(void *item)) {
    if (freeItem != NULL) {
        for (int i = 0; i < s->size; i++) {
            freeItem(s->items[i]);
        }
    }
    free(s->items);
    free(s);
}

void StackPush(Stack s, void *item) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->items = realloc(s->items, s->capacity * sizeof(void *));
        assert(s->items != NULL);
    }
    s->items[s->size] = item;
    s->size++;
}

void *StackPop(Stack s) {
    assert(s->size > 0);
    s->size--;
    return s->items[s->size];
}

void *StackPeek(Stack s) {
    assert(s->size > 0);
    return s->items[s->size - 1];
}

bool StackIsEmpty(Stack s) {
    return s->size == 0;
}

int StackSize(Stack s) {
    return s->size;
}
