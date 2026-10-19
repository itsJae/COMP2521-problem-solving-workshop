/**
 * Isomorphic String
 * https://leetcode.com/problems/isomorphic-strings/
 */

#include <stdbool.h>
#include <stdio.h>
#include "../adt/HashTable.h"
#include "../adt/Common.h"

/**
 * Returns true if s and t are isomorphic
 */
bool isIsomorphic(char *s, char *t) {
    // TODO
    return false;
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
