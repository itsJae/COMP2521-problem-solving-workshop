/**
 * Generic hash table (separate chaining). Caller supplies hash/equals
 * function pointers - see Common.h for ready-made ones for char * and
 * int * keys.
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef unsigned long (*HashFn)(void *key);
typedef bool (*EqualsFn)(void *a, void *b);

typedef struct hashTable *HashTable;

/**
 * Creates a new, empty hash table that hashes and compares keys using
 * the given functions
 */
HashTable HashTableNew(HashFn hash, EqualsFn equals);

/**
 * Frees all memory associated with the given hash table.
 * freeKey/freeValue may be NULL if keys/values shouldn't be freed
 */
void HashTableFree(HashTable t, void (*freeKey)(void *key), void (*freeValue)(void *value));

/**
 * Inserts a key/value pair, overwriting the value if the key already exists
 */
void HashTablePut(HashTable t, void *key, void *value);

/**
 * Returns the value associated with the given key, or NULL if absent
 */
void *HashTableGet(HashTable t, void *key);

/**
 * Returns true if the given key is in the hash table
 */
bool HashTableContains(HashTable t, void *key);

/**
 * Removes the given key and its value, returning true if it was present
 */
bool HashTableRemove(HashTable t, void *key);

/**
 * Returns the number of key/value pairs in the hash table
 */
int HashTableSize(HashTable t);

#endif
