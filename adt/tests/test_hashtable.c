#include "../HashTable.h"
#include "../Common.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    HashTable t = HashTableNew(HashString, EqualsString);
    assert(HashTableSize(t) == 0);

    int one = 1, two = 2, three = 3;
    HashTablePut(t, "one", &one);
    HashTablePut(t, "two", &two);
    HashTablePut(t, "three", &three);
    assert(HashTableSize(t) == 3);

    assert(*(int *) HashTableGet(t, "two") == 2);
    assert(HashTableContains(t, "three"));
    assert(!HashTableContains(t, "four"));
    assert(HashTableGet(t, "four") == NULL);

    // overwrite existing key
    int newTwo = 22;
    HashTablePut(t, "two", &newTwo);
    assert(HashTableSize(t) == 3); // size unchanged, value overwritten
    assert(*(int *) HashTableGet(t, "two") == 22);

    assert(HashTableRemove(t, "one"));
    assert(!HashTableContains(t, "one"));
    assert(HashTableSize(t) == 2);
    assert(!HashTableRemove(t, "one")); // already removed

    // force a rehash by inserting enough keys to exceed the load factor
    int values[50];
    char keys[50][8];
    for (int i = 0; i < 50; i++) {
        values[i] = i;
        snprintf(keys[i], sizeof(keys[i]), "k%d", i);
        HashTablePut(t, keys[i], &values[i]);
    }
    for (int i = 0; i < 50; i++) {
        assert(*(int *) HashTableGet(t, keys[i]) == i);
    }

    HashTableFree(t, NULL, NULL);
    printf("test_hashtable: all tests passed\n");
    return 0;
}
