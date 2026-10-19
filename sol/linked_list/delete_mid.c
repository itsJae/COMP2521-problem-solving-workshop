#include <stdio.h>
#include <stdlib.h>
#include "../../adt/List.h"

static int length(struct node *list) {
    if (list == NULL) return 0;
    return 1 + length(list->next);
}

static struct node *deleteAt(struct node *list, int index) {
    if (index == 0) {
        struct node *next = list->next;
        free(list);
        return next;
    }
    list->next = deleteAt(list->next, index - 1);
    return list;
}

struct node *deleteMid(struct node *list) {
    return deleteAt(list, length(list) / 2);
}

/*
Iterative version (slow/fast pointers):

struct node *deleteMid(struct node *list) {
    if (list->next == NULL) {
        free(list);
        return NULL;
    }

    struct node *slow = list;
    struct node *fast = list->next->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *mid = slow->next;
    slow->next = mid->next;
    free(mid);
    return list;
}
*/
