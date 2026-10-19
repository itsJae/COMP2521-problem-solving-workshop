# Run `make test` to build and run all ADT self-tests.
#
# To compile a problem, link it against the whole library, e.g. from a
# topic folder (use ../../adt/*.c from inside sol/<topic>/):
#   gcc -Wall -std=c11 is_sorted.c ../adt/*.c -o is_sorted

CC = gcc
CFLAGS = -Wall -std=c11

TESTS = test_stack test_queue test_heap test_pq test_hashtable test_graph test_list test_bst

.PHONY: test clean

test:
	$(CC) $(CFLAGS) Stack.c tests/test_stack.c -o tests/test_stack && ./tests/test_stack
	$(CC) $(CFLAGS) Queue.c tests/test_queue.c -o tests/test_queue && ./tests/test_queue
	$(CC) $(CFLAGS) Heap.c tests/test_heap.c -o tests/test_heap && ./tests/test_heap
	$(CC) $(CFLAGS) Heap.c PriorityQueue.c tests/test_pq.c -o tests/test_pq && ./tests/test_pq
	$(CC) $(CFLAGS) HashTable.c Common.c tests/test_hashtable.c -o tests/test_hashtable && ./tests/test_hashtable
	$(CC) $(CFLAGS) Graph.c tests/test_graph.c -o tests/test_graph && ./tests/test_graph
	$(CC) $(CFLAGS) List.c tests/test_list.c -o tests/test_list && ./tests/test_list
	$(CC) $(CFLAGS) Bst.c tests/test_bst.c -o tests/test_bst && ./tests/test_bst

clean:
	rm -f $(addprefix tests/,$(TESTS))
