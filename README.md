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

## Setup

1. Install [VS Code](https://code.visualstudio.com/), Git, and a C compiler:
   - macOS: `xcode-select --install`
   - Linux: `sudo apt install build-essential git`
   - Windows: install WSL (`wsl --install`), run `sudo apt install build-essential git` inside it, and add the **WSL** extension to VS Code
2. In VS Code, install the **C/C++** extension (Microsoft).
3. Open the Command Palette (`Cmd/Ctrl + Shift + P`), run **Git: Clone**, and paste:
   ```
   https://github.com/itsJae/COMP2521-problem-solving-workshop.git
   ```
   Choose a folder, then click **Open** when prompted.

## Running

Open a terminal in VS Code (``Ctrl + ` ``), `cd` into a topic folder, then:

```sh
gcc -Wall -std=c11 is_sorted.c ../adt/*.c -o is_sorted && ./is_sorted
```

From `sol/<topic>/`, use `../../adt/*.c` instead. Each file prints `PASS`/`FAIL` for its test cases.

To test the ADTs themselves: `cd adt && make test`
