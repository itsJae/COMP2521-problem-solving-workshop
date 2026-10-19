#include <stdbool.h>
#include <stdlib.h>
#include "../../adt/List.h"

static struct node *doCopy(struct node *list, int lo, int hi, bool take) {
    if (list == NULL) return NULL;

    if (list->value < lo || list->value > hi) {
        return doCopy(list->next, lo, hi, take);
    }
    if (!take) {
        return doCopy(list->next, lo, hi, true);
    }

    struct node *n = malloc(sizeof(*n));
    n->value = list->value;
    n->next = doCopy(list->next, lo, hi, false);
    return n;
}

struct node *copyAlternatingRange(struct node *list, int lo, int hi) {
    return doCopy(list, lo, hi, true);
}

/*
Iterative version:

struct node *copyAlternatingRange(struct node *list, int lo, int hi) {
    struct node *head = NULL;
    struct node *tail = NULL;
    bool take = true;

    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        if (curr->value < lo || curr->value > hi) continue;

        if (take) {
            struct node *n = malloc(sizeof(*n));
            n->value = curr->value;
            n->next = NULL;
            if (tail == NULL) {
                head = n;
            } else {
                tail->next = n;
            }
            tail = n;
        }
        take = !take;
    }

    return head;
}
*/
