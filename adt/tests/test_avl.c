#include "../Avl.h"

#include <assert.h>
#include <stdio.h>

static int compareInt(void *a, void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    Avl t = AvlNew(compareInt);
    assert(AvlIsEmpty(t));

    int values[] = {5, 3, 8, 1, 9, 2, 7, 3};
    int n = 8;
    for (int i = 0; i < n; i++) {
        AvlInsert(t, &values[i]);
    }
    assert(AvlSize(t) == n);
    assert(*(int *) AvlMin(t) == 1);
    assert(*(int *) AvlMax(t) == 9);

    // Taking from both ends should give the sorted order from the outside in
    assert(*(int *) AvlDeleteMin(t) == 1);
    assert(*(int *) AvlDeleteMax(t) == 9);
    assert(*(int *) AvlDeleteMin(t) == 2);
    assert(*(int *) AvlDeleteMin(t) == 3);
    assert(*(int *) AvlDeleteMin(t) == 3);
    assert(*(int *) AvlDeleteMax(t) == 8);
    assert(AvlSize(t) == 2);

    // Sorted inserts would make an unbalanced BST very deep; AVL stays fast
    int many[100000];
    for (int i = 0; i < 100000; i++) {
        many[i] = i;
        AvlInsert(t, &many[i]);
    }
    for (int i = 0; i < 100000; i++) {
        int smallest = *(int *) AvlDeleteMin(t);
        assert(smallest <= *(int *) AvlMin(t));
    }
    assert(AvlSize(t) == 2);

    AvlFree(t, NULL);
    printf("test_avl: all tests passed\n");
    return 0;
}
