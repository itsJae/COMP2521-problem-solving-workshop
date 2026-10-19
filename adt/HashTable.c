#include "HashTable.h"

#include <stdlib.h>
#include <assert.h>

typedef struct entry {
    void *key;
    void *value;
    struct entry *next;
} *Entry;

struct hashTable {
    Entry *buckets;
    int numBuckets;
    int size;
    HashFn hash;
    EqualsFn equals;
};

#define INITIAL_BUCKETS 16
#define MAX_LOAD_FACTOR 0.75

static void rehash(HashTable t);

HashTable HashTableNew(HashFn hash, EqualsFn equals) {
    HashTable t = malloc(sizeof(*t));
    assert(t != NULL);
    t->numBuckets = INITIAL_BUCKETS;
    t->buckets = calloc(t->numBuckets, sizeof(Entry));
    assert(t->buckets != NULL);
    t->size = 0;
    t->hash = hash;
    t->equals = equals;
    return t;
}

void HashTableFree(HashTable t, void (*freeKey)(void *key), void (*freeValue)(void *value)) {
    for (int i = 0; i < t->numBuckets; i++) {
        Entry curr = t->buckets[i];
        while (curr != NULL) {
            Entry next = curr->next;
            if (freeKey != NULL) freeKey(curr->key);
            if (freeValue != NULL) freeValue(curr->value);
            free(curr);
            curr = next;
        }
    }
    free(t->buckets);
    free(t);
}

static Entry findEntry(HashTable t, void *key) {
    int idx = t->hash(key) % t->numBuckets;
    Entry curr = t->buckets[idx];
    while (curr != NULL) {
        if (t->equals(curr->key, key)) return curr;
        curr = curr->next;
    }
    return NULL;
}

void HashTablePut(HashTable t, void *key, void *value) {
    Entry existing = findEntry(t, key);
    if (existing != NULL) {
        existing->value = value;
        return;
    }

    if ((double) (t->size + 1) / t->numBuckets > MAX_LOAD_FACTOR) {
        rehash(t);
    }

    Entry e = malloc(sizeof(*e));
    assert(e != NULL);
    e->key = key;
    e->value = value;

    int idx = t->hash(key) % t->numBuckets;
    e->next = t->buckets[idx];
    t->buckets[idx] = e;
    t->size++;
}

static void rehash(HashTable t) {
    int oldNumBuckets = t->numBuckets;
    Entry *oldBuckets = t->buckets;

    t->numBuckets *= 2;
    t->buckets = calloc(t->numBuckets, sizeof(Entry));
    assert(t->buckets != NULL);

    for (int i = 0; i < oldNumBuckets; i++) {
        Entry curr = oldBuckets[i];
        while (curr != NULL) {
            Entry next = curr->next;
            int idx = t->hash(curr->key) % t->numBuckets;
            curr->next = t->buckets[idx];
            t->buckets[idx] = curr;
            curr = next;
        }
    }
    free(oldBuckets);
}

void *HashTableGet(HashTable t, void *key) {
    Entry e = findEntry(t, key);
    return e != NULL ? e->value : NULL;
}

bool HashTableContains(HashTable t, void *key) {
    return findEntry(t, key) != NULL;
}

bool HashTableRemove(HashTable t, void *key) {
    int idx = t->hash(key) % t->numBuckets;
    Entry curr = t->buckets[idx];
    Entry prev = NULL;

    while (curr != NULL) {
        if (t->equals(curr->key, key)) {
            if (prev == NULL) {
                t->buckets[idx] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            t->size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

int HashTableSize(HashTable t) {
    return t->size;
}
