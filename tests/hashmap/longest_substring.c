#include <stdio.h>

int lengthOfLongestSubstring(char *s);

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
