#include "../PriorityQueue.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    PriorityQueue pq = PQNew();
    assert(PQIsEmpty(pq));

    PQInsert(pq, "urgent",   1);
    PQInsert(pq, "low",      5);
    PQInsert(pq, "medium",   3);
    PQInsert(pq, "critical", 0);
    assert(PQSize(pq) == 4);

    assert(strcmp((char *) PQPeek(pq), "critical") == 0);
    assert(strcmp((char *) PQExtractMin(pq), "critical") == 0);
    assert(strcmp((char *) PQExtractMin(pq), "urgent") == 0);
    assert(strcmp((char *) PQExtractMin(pq), "medium") == 0);
    assert(strcmp((char *) PQExtractMin(pq), "low") == 0);
    assert(PQIsEmpty(pq));

    PQFree(pq, NULL);
    printf("test_pq: all tests passed\n");
    return 0;
}
