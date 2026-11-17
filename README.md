# COMP2521 Problem Solving Workshop

Practice problems for the CSESoc Education COMP2521 problem solving workshop, written in C.

## Structure

```
<topic>/       starter code (fill in the TODO)
tests/<topic>/ test cases used by ./autotest
adt/           shared ADTs (Stack, Queue, Heap, PriorityQueue, HashTable, Graph, List, Bst, Avl)
```

## Problems

| Topic | Level 1 | Level 2 | Level 3 |
|---|---|---|---|
| `linked_list` | Is Sorted | Delete Mid | Copy Alternating Range |
| `bst` | Count Leaves | Tree Diameter | Structural Difference |
| `graph` | Reach Darling Square | Find Happy Squad | Legends Never Die |
| `hashmap` | Molly Tea | Isomorphic Strings | Longest Substring Without Repeating Characters |
| `stack_queue` | Crunch Pringles | Reverse Queue | Daily Temperatures |
| `bonus` | | | Project Selection |

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

Open a terminal in VS Code (``Ctrl + ` ``), `cd` into a topic folder, then:

```sh
cd linked_list
./autotest is_sorted    # test one problem
./autotest              # test every problem in this folder
```

It compiles your file, runs the test cases, and prints how many passed (e.g. `Result: 5/6 passed`).
Running `./autotest` from the repo root tests every problem.

To debug with your own `printf`s, build with `make` inside a topic folder and run the problem directly.
This calls your function on the test inputs but only shows your own output, not the test results:

```sh
cd linked_list
make
./is_sorted
```
