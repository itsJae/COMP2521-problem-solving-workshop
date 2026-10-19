#include <stdbool.h>
#include <stdlib.h>
#include "../../adt/List.h"

bool isSorted(struct node *list) {
    if (list == NULL || list->next == NULL) return true;
    if (list->value > list->next->value) return false;
    return isSorted(list->next);
}

/*
Iterative version:

bool isSorted(struct node *list) {
    for (struct node *curr = list; curr != NULL && curr->next != NULL; curr = curr->next) {
        if (curr->value > curr->next->value) return false;
    }
    return true;
}
*/
