# COMP2521 Problem Solving Workshop

Practice problems for the CSESoc Education COMP2521 problem solving workshop, written in C.

## Structure

```
<topic>/       starter code (fill in the TODO)
tests/<topic>/ test cases used by ./autotest
sol/<topic>/   solutions
adt/           shared ADTs (Stack, Queue, Heap, PriorityQueue, HashTable, Graph, List, Bst)
```

## Problems

| Topic | Level 1 | Level 2 | Level 3 |
|---|---|---|---|
| `linked_list` | isSorted | copyAlternatingRange | deleteMid |
| `bst` | countLeaves | treeDiameter | structuralDifference |
| `graph` | reachDarlingSquare | findHappyComponent | celebrity |
| `hashmap` | mollyTea | isomorphicStrings | longestSubstring |
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

## Autotest

Open a terminal in VS Code (``Ctrl + ` ``) at the repo root, then:

```sh
./autotest is_sorted    # test one problem
./autotest              # test every problem
```

It compiles your file, runs the test cases, and prints how many passed (e.g. `Result: 5/6 passed`).
From inside a topic folder, use `../autotest is_sorted`.
