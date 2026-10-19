# COMP2521 Problem Solving Workshop

Practice problems for the CSESoc Education COMP2521 problem solving workshop, written in C.

## Structure

```
<topic>/       starter code (fill in the TODO)
sol/<topic>/   solutions
adt/           shared ADTs (Stack, Queue, Heap, PriorityQueue, HashTable, Graph, List, Bst)
```

## Problems

| Topic | Level 1 | Level 2 | Level 3 |
|---|---|---|---|
| `linked_list` | isSorted | copyAlternatingRange | deleteMid |
| `bst` | countLeaves | treeDiameter | structuralDifference |
| `graph` | reachDarlingSquare | findHappyComponent | celebrity |
| `hashmap` | geeseInATrenchcoat | isomorphicStrings | longestSubstring |
| `bonus` | | | projectSelection |

## Running

From a topic folder:

```sh
gcc -Wall -std=c11 is_sorted.c ../adt/*.c -o is_sorted && ./is_sorted
```

From `sol/<topic>/`, use `../../adt/*.c` instead. Each file prints `PASS`/`FAIL` for its test cases.

To test the ADTs themselves: `cd adt && make test`
