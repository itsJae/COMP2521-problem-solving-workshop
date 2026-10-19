#include <stdio.h>
#include <stdlib.h>
#include "../../adt/HashTable.h"
#include "../../adt/Common.h"

int lengthOfLongestSubstring(char *s) {
    int chars[256];
    for (int i = 0; i < 256; i++) {
        chars[i] = i;
    }

    HashTable lastSeen = HashTableNew(HashInt, EqualsInt);
    int best = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int *c = &chars[(unsigned char) s[i]];
        int *prev = HashTableGet(lastSeen, c);

        if (prev == NULL) {
            prev = malloc(sizeof(int));
            HashTablePut(lastSeen, c, prev);
        } else if (*prev >= start) {
            start = *prev + 1;
        }
        *prev = i;

        if (i - start + 1 > best) {
            best = i - start + 1;
        }
    }

    HashTableFree(lastSeen, NULL, free);
    return best;
}

static void runTest(char *s, int expected) {
    int actual = lengthOfLongestSubstring(s);
    printf("%-4s lengthOfLongestSubstring(\"%s\") -> got %d, expected %d\n",
           actual == expected ? "PASS" : "FAIL", s, actual, expected);
}

int main(void) {
    runTest("abcabcbb", 3);
    runTest("bbbbb", 1);
    runTest("pwwkew", 3);
    runTest("", 0);
    runTest(" ", 1);
    runTest("dvdf", 3);
    runTest("abba", 2);
    return 0;
}
