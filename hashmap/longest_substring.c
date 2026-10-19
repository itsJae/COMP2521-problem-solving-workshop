/**
 * Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <stdio.h>
#include <stdlib.h>
#include "../adt/HashTable.h"
#include "../adt/Common.h"

/**
 * Returns the length of the longest substring of s without repeating
 * characters
 */
int lengthOfLongestSubstring(char *s) {
    // TODO
    return -1;
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
