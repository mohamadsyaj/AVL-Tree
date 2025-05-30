# AVL-Tree Demonstration (C++)

A single-file program that builds, balances, and prints an **AVL tree**—a binary search tree that guarantees `O(log n)` search, insertion, and deletion by performing rotations when necessary.  
The code inserts a sequence of `(key, value)` pairs, reports the tree after every operation, then deletes three keys to illustrate rebalancing on removal.

---

## Features

| Capability | Implementation Notes |
|------------|----------------------|
| Self-balancing BST | Four standard AVL rotation cases (LL, RR, LR, RL). |
| Insert / Update | `insert()` creates or updates nodes and rebalances on the way up. |
| Delete | `deleteNode()` removes a key, replaces with in-order successor if needed, then rebalances. |
| Height tracking | Each node stores its subtree height; updated after every structural change. |
| Diagnostics | `printTree()` outputs an in-order traversal and the current tree height so re-balancing can be observed step-by-step. |

---

## File Layout

avl_demo.cpp // all structs, functions, and main()

yaml
Copy

---

## Building

Compile with any C++17-capable compiler:

```bash
g++ -O2 -std=c++17 avl_demo.cpp -o avl_demo
Running
bash
Copy
./avl_demo
Console output shows each insertion, the tree contents, and its height, followed by deletions and the final root.

Customizing the Demo
Change the data set – Edit insertions[][2] in main() to try different key orders or sizes.

Silence verbose output – Comment out the printTree calls inside the insertion/deletion loops.

Pretty printing – Replace printTree with a Graphviz dump or level-order printer for easier visualization.

Possible Extensions
Encapsulate functionality in an AVLTree class template.

Add search and iterator methods.

Provide unit tests (GoogleTest or Catch2).

Visualize rotations in real time with an SDL or Qt front end.

License
© 2025 Mohamad Syaj. All Rights Reserved.
This code is released for personal or educational study only.
It may not be sold, published, or redistributed in commercial products without the author’s explicit written consent.

Author
Mohamad Syaj
For questions or feedback, please open an issue or contact the author directly.
