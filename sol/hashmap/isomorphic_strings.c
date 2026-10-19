#include <stdbool.h>
#include <stdio.h>
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

static void runTest(char *s, char *t, bool expected) {
    bool actual = isIsomorphic(s, t);
    printf("%-4s isIsomorphic(\"%s\", \"%s\") -> got %s, expected %s\n",
           actual == expected ? "PASS" : "FAIL", s, t,
           actual ? "true" : "false", expected ? "true" : "false");
}

int main(void) {
    runTest("egg",   "add",   true);
    runTest("foo",   "bar",   false);
    runTest("paper", "title", true);
    runTest("badc",  "baba",  false);
    runTest("",      "",      true);
    runTest("a",     "a",     true);
    return 0;
}
