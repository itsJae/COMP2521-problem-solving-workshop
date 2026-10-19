#include "List.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static struct node *newNode(int value) {
    struct node *n = malloc(sizeof(*n));
    assert(n != NULL);
    n->value = value;
    n->next = NULL;
    return n;
}

struct node *listFromArray(int values[], int size) {
    struct node *head = NULL;
    struct node *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct node *n = newNode(values[i]);
        if (tail == NULL) {
            head = n;
        } else {
            tail->next = n;
        }
        tail = n;
    }
    return head;
}

void listFree(struct node *list) {
    while (list != NULL) {
        struct node *next = list->next;
        free(list);
        list = next;
    }
}

bool listEquals(struct node *list, int values[], int size) {
    for (int i = 0; i < size; i++) {
        if (list == NULL || list->value != values[i]) return false;
        list = list->next;
    }
    return list == NULL;
}

void listPrint(struct node *list) {
    printf("[");
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        printf("%d%s", curr->value, curr->next != NULL ? ", " : "");
    }
    printf("]");
}
