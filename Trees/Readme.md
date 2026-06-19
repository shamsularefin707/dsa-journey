# Binary Tree Implementations

A **Binary Tree** is a non-linear hierarchical data structure where each node can have at most two children, traditionally referred to as the **left child** and the **right child**.

This folder covers fundamentals of tree structures, manual tree mapping, and dynamic level-order parsing in C++.

---

## Files Included

| File Name | Description |
| :--- | :--- |
| `General_BinaryTree_1.cpp` | **Manual Construction:** Demonstrates manual object connection linking parent nodes to explicit left and right children. |
| `General_BinaryTree_2.cpp` | **Level-Order Construction:** Dynamically builds a binary tree from a level-order serialized array (where `-1` signifies a `nullptr` node) using a queue framework. |

---

## Technical Highlights

### Level-Order Construction Algorithm
To safely process incoming serialization structures, sequential array positions map onto nodes horizontally level-by-level:
1. Initialize the root with the first index and push it onto a `std::queue`.
2. While processing nodes out of the queue, sequentially bind the next two array indexes to the current node's left and right pointers respectively.
3. If an index values holds `-1`, it bypasses node creation and remains pinned to `nullptr`.

### Console Tree Visualization
Both files contain a reverse in-order recursive visualizer (`printTreeVisual`) that outputs the tree sideways in the terminal window for clean structure validation:

```text
     6
  3
1
     5
  2
     4
