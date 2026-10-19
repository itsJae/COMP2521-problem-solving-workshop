#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../adt/HashTable.h"
#include "../../adt/Common.h"

bool mollyTea(int prices[], int n, int k, int *i, int *j) {
    HashTable seen = HashTableNew(HashInt, EqualsInt);
    int *indices = malloc(n * sizeof(int));
    bool found = false;

    for (int curr = 0; curr < n && !found; curr++) {
        int need = k - prices[curr];
        int *other = HashTableGet(seen, &need);
        if (other != NULL) {
            *i = *other;
            *j = curr;
            found = true;
        } else {
            indices[curr] = curr;
            HashTablePut(seen, &prices[curr], &indices[curr]);
        }
    }

    HashTableFree(seen, NULL, NULL);
    free(indices);
    return found;
}
