#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../adt/HashTable.h"
#include "../../adt/Common.h"

bool isIsomorphic(char *s, char *t) {
    int chars[256];
    for (int i = 0; i < 256; i++) {
        chars[i] = i;
    }

    HashTable sToT = HashTableNew(HashInt, EqualsInt);
    HashTable tToS = HashTableNew(HashInt, EqualsInt);
    bool result = true;

    for (int i = 0; s[i] != '\0' && result; i++) {
        int *a = &chars[(unsigned char) s[i]];
        int *b = &chars[(unsigned char) t[i]];
        int *mappedA = HashTableGet(sToT, a);
        int *mappedB = HashTableGet(tToS, b);

        if (mappedA == NULL && mappedB == NULL) {
            HashTablePut(sToT, a, b);
            HashTablePut(tToS, b, a);
        } else if (mappedA != b || mappedB != a) {
            result = false;
        }
    }

    HashTableFree(sToT, NULL, NULL);
    HashTableFree(tToS, NULL, NULL);
    return result;
}
