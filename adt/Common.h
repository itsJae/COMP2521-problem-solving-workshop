/**
 * Ready-made hash/equals functions for the common key types, so problem
 * code using HashTable doesn't need to write its own for strings or ints.
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

/**
 * Hashes a char * key
 */
unsigned long HashString(void *key);

/**
 * Returns true if two char * keys are equal
 */
bool EqualsString(void *a, void *b);

/**
 * Hashes a boxed int * key
 */
unsigned long HashInt(void *key);

/**
 * Returns true if two boxed int * keys are equal
 */
bool EqualsInt(void *a, void *b);

#endif
