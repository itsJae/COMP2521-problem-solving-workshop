#include "Common.h"

#include <string.h>

unsigned long HashString(void *key) {
    char *s = key;
    unsigned long hash = 5381;
    int c;
    while ((c = *s++)) {
        hash = hash * 33 + (unsigned long) c;
    }
    return hash;
}

bool EqualsString(void *a, void *b) {
    return strcmp((char *) a, (char *) b) == 0;
}

unsigned long HashInt(void *key) {
    return (unsigned long) *(int *) key;
}

bool EqualsInt(void *a, void *b) {
    return *(int *) a == *(int *) b;
}
