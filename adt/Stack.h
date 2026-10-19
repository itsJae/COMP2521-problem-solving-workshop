/**
 * Generic stack ADT (LIFO), backed by a dynamic array.
 * Stores void * items, so it works for any type.
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack *Stack;

/**
 * Creates a new, empty stack
 */
Stack StackNew(void);

/**
 * Frees all memory associated with the given stack.
 * freeItem may be NULL if items shouldn't be freed
 */
void StackFree(Stack s, void (*freeItem)(void *item));

/**
 * Pushes an item onto the top of the stack
 */
void StackPush(Stack s, void *item);

/**
 * Removes and returns the item on top of the stack
 */
void *StackPop(Stack s);

/**
 * Returns the item on top of the stack, without removing it
 */
void *StackPeek(Stack s);

/**
 * Returns true if the stack has no items
 */
bool StackIsEmpty(Stack s);

/**
 * Returns the number of items in the stack
 */
int StackSize(Stack s);

#endif
