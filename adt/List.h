/**
 * Singly linked list of ints
 */

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

/**
 * Creates a list containing the given values, in order
 */
struct node *listFromArray(int values[], int size);

/**
 * Frees all nodes in the list
 */
void listFree(struct node *list);

/**
 * Returns true if the list contains exactly the given values, in order
 */
bool listEquals(struct node *list, int values[], int size);

/**
 * Prints the list in the form [1, 2, 3]
 */
void listPrint(struct node *list);

#endif
