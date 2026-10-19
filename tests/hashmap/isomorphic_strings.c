#include <stdbool.h>
#include <stdio.h>

bool isIsomorphic(char *s, char *t);

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
