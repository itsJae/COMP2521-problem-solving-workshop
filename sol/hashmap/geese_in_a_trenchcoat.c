#include <stdbool.h>
#include <stdio.h>
#include "../../adt/HashTable.h"
#include "../../adt/Common.h"

bool geeseInATrenchcoat(int heights[], int n, int H) {
    HashTable seen = HashTableNew(HashInt, EqualsInt);
    bool found = false;

    for (int i = 0; i < n && !found; i++) {
        int need = H - heights[i];
        if (HashTableContains(seen, &need)) {
            found = true;
        } else {
            HashTablePut(seen, &heights[i], &heights[i]);
        }
    }

    HashTableFree(seen, NULL, NULL);
    return found;
}

static void runTest(char *name, int heights[], int n, int H, bool expected) {
    bool actual = geeseInATrenchcoat(heights, n, H);
    printf("%-4s %-10s -> got %s, expected %s\n",
           actual == expected ? "PASS" : "FAIL", name,
           actual ? "true" : "false", expected ? "true" : "false");
}

int main(void) {
    runTest("test1", (int[]){3, 1, 4, 2}, 4, 6, true);
    runTest("test2", (int[]){2, 7, 11, 15}, 4, 9, true);
    runTest("test3", (int[]){1, 2, 3}, 3, 7, false);
    runTest("test4", (int[]){3, 4}, 2, 6, false);
    runTest("test5", (int[]){3, 3, 4}, 3, 6, true);
    runTest("test6", (int[]){5}, 1, 10, false);
    runTest("test7", NULL, 0, 1, false);
    return 0;
}
