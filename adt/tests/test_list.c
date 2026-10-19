#include "../List.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    assert(listFromArray(NULL, 0) == NULL);
    assert(listEquals(NULL, NULL, 0));

    int values[] = {1, 2, 3};
    struct node *list = listFromArray(values, 3);
    assert(list->value == 1);
    assert(list->next->value == 2);
    assert(list->next->next->value == 3);
    assert(list->next->next->next == NULL);

    assert(listEquals(list, values, 3));
    assert(!listEquals(list, values, 2));
    assert(!listEquals(list, (int[]){1, 2, 4}, 3));

    listFree(list);
    printf("test_list: all tests passed\n");
    return 0;
}
