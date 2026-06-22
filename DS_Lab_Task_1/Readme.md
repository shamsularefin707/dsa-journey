# Data Structures Coding Assignment Solutions

This repository contains clean, complete C++ implementations for questions 1, 2, and 4 from the assignment curriculum. The solutions cover recursive binary tree reconstructions, tree structure conversion mapping, and self-balancing binary search trees using Red-Black Tree validation mechanics.

---

## 📂 Repository Contents

| File Name | Assignment Section | Concept Covered |
| :--- | :--- | :--- |
| `DS_Task_1_a.cpp` | **Question 1 (i)** | Reconstruct Binary Tree from **Preorder & Inorder** |
| `DS_Task_1_b.cpp` | **Question 1 (ii)** | Reconstruct Binary Tree from **Postorder & Inorder** |
| `DS_Task_2.cpp` | **Question 2** | Converting a **Binary Tree** to a **General Tree** |
| `Red-Black-Tree.cpp` | **Question 4 (i & ii)** | Imbalanced Tree Construction & Balancing via **Red-Black Trees** |

---

## 🛠️ Detailed Task Descriptions & Implementations

### 1. Tree Reconstruction from Traversals (Question 1)
Reconstructs unique Binary Trees recursively using combinations of traversal arrays, keeping track of root positions to cleanly partition subtrees.

* **Preorder + Inorder (`DS_Task_1_a.cpp`):** Uses a forward moving tracking index on the preorder array to pick the root node sequentially, splitting left and right bounds across the inorder array.
* **Postorder + Inorder (`DS_Task_1_b.cpp`):** Processes elements backwards from the end of the postorder array to dynamically determine roots, resolving the right subtree bound transitions before handling the left subtrees.

### 2. Binary Tree to General Tree Conversion (Question 2)
Converts standard Left-Child Right-Sibling (LCRS) structured representations or standard binary boundaries into generalized structural trees (`DS_Task_2.cpp`).
* **Logic Framework:** Iterates through structural layers where the left pointer of a node marks its first true child, and the right pointer sequentially traverses all immediate siblings within that scope level.

### 3. Red-Black Balancing Operations (Question 4)
This task demonstrates tree imbalance scenarios and details structural recovery using strict Red-Black Tree validation loops (`Red-Black-Tree.cpp`).

An input string sequentially fed as `10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 11` initially constructs a severely right-skewed, degraded un-balanced BST branch structure.


The program addresses both assignment sub-components:
* **Part i:** Runs a bottom-up parsing check over the un-balanced structural tree nodes. If consecutive `RED` properties are identified among parent-child layers, it fires structural `insertFixup()` configurations to re-balance the layout.
* **Part ii:** Executes continuous additions and standard item deletions (e.g., removing item `7`) while preserving a tree height of $O(\log n)$ using local left/right pointer rotations and standard node recoloring loops.

---

## 🚀 Compilation & Running Guide

Ensure you have a modern C++ compiler configured (such as `g++` via GCC).

To compile and run any task module file, execute the following commands in your preferred terminal workspace:

```bash
# Compile a specific solution module (e.g., Red-Black Tree)
g++ -std=c++17 Red-Black-Tree.cpp -o rbt_solution

# Run the compiled program binary executable
./rbt_solution
