# 🧠 DSA Journey

> Learning Data Structures & Algorithms by building them from scratch in **C++**.

![Language](https://img.shields.io/badge/language-C%2B%2B17-blue)
![Status](https://img.shields.io/badge/status-in%20progress-yellow)
![Focus](https://img.shields.io/badge/focus-DSA-green)

This repository is my running record of studying DSA as a Software Engineering student at IIT, University of Dhaka. It holds hand-written implementations, university coursework, complexity benchmarks, exam-style problem sets, and a few cheat sheets I made along the way.

Most code avoids STL containers on purpose, so the internals (pointers, rotations, heapify, partitioning) are written out by hand.

---

## 📑 Contents

- [Quick Start](#-quick-start)
- [Topic Index](#-topic-index)
- [Coursework & Practice](#-coursework--practice)
- [Algorithmic Analysis](#-algorithmic-analysis)
- [Resources](#-resources)
- [Repository Structure](#-repository-structure)
- [Roadmap](#-roadmap)
- [Contributing](#-contributing)

---

## ⚡ Quick Start

```bash
git clone https://github.com/shamsularefin707/dsa-journey.git
cd dsa-journey

# compile and run any file
g++ -std=c++17 Sorting/Merge_Sort.cpp -o merge_sort
./merge_sort
```

Each `.cpp` file is self-contained with its own `main()`, so there's no build system to set up.

---

## 🗂️ Topic Index

### Linear Data Structures

| Topic | Files | What's inside |
|---|---|---|
| 🔗 **Linked List** | [`LinkedList/`](LinkedList/) | Singly & doubly linked lists — insert/delete at head, tail, position; search; reverse; merge sort on a list |
| 📚 **Stack** | [`Stack/`](Stack/) | Array- and linked-list-based stacks; infix → postfix conversion; postfix evaluation |
| 🚶 **Queue** | [`Queue/`](Queue/) | Linear queue and circular queue (modular indexing) on arrays |

### Trees & Heaps

| Topic | Files | What's inside |
|---|---|---|
| 🌳 **Binary Tree** | [`Trees/General_Binary_Tree_*.cpp`](Trees/) | Manual construction, level-order construction (`-1` = null), sideways console visualizer |
| 🔍 **BST** | [`Trees/BST_*.cpp`](Trees/), `Traversal_BST.cpp`, `Deletion_BST.cpp` | Recursive & iterative BST, traversals, deletion (all three cases) |
| ⚖️ **AVL Tree** | [`Trees/AVL_1.cpp`](Trees/AVL_1.cpp) | Height-balanced insertion with LL / RR / LR / RL rotations |
| 🔴⚫ **Red-Black Tree** | [`Trees/Red_Black_Tree.cpp`](Trees/Red_Black_Tree.cpp) | Insertion fix-up, rotations, recoloring |
| 🏔️ **Heap** | [`Heap/`](Heap/) | Array-based max-heap and min-heap with `heapify` |

### Algorithms

| Topic | Files | What's inside |
|---|---|---|
| 🔄 **Sorting** | [`Sorting/`](Sorting/) | Selection, Insertion, Merge, Quick, Counting, Radix |
| 🧠 **Greedy** | [`Greedy/`](Greedy/) | Fractional Knapsack, Activity / Time Scheduling, Huffman Coding (plus an improved version that reads a file and packs real bits) |
| 🧮 **Dynamic Programming** | [`DP/LCS.cpp`](DP/LCS.cpp) | Longest Common Subsequence with `c`/`b` tables and path reconstruction (CLRS style) |
| 🗼 **Recursion** | [`TowerOfHanoi/`](TowerOfHanoi/) | Two Tower of Hanoi solutions — explicit auxiliary peg vs. computed auxiliary peg |

### Complexity Cheat Sheet

| Algorithm | Best | Average | Worst | Space |
|---|---|---|---|---|
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(n + k) |
| Radix Sort | O(d·(n + b)) | O(d·(n + b)) | O(d·(n + b)) | O(n + b) |
| BST search / insert | O(log n) | O(log n) | O(n) | O(h) |
| AVL / Red-Black ops | O(log n) | O(log n) | O(log n) | O(h) |
| Heapify (build heap) | O(n) | O(n) | O(n) | O(1) |
| Huffman Coding | — | O(n log n) | O(n log n) | O(n) |
| LCS | O(m·n) | O(m·n) | O(m·n) | O(m·n) |
| Tower of Hanoi | O(2ⁿ) | O(2ⁿ) | O(2ⁿ) | O(n) |

---

## 🎓 Coursework & Practice

### 🧪 Continuous Evaluation — [`Continuous_Evaluation/`](Continuous_Evaluation/)

Weekly lab tasks, most solved both **recursively and iteratively**:

| Week | Task |
|---|---|
| 1 | Merge two sorted arrays · Recursive binary search |
| 2 | Quick Sort & Merge Sort (recursive + iterative) |
| 3 | Bubble, Selection, Insertion Sort (loop + recursion) |
| 4 | Infix → Postfix · Postfix evaluation · Quick Sort & Merge Sort using an explicit stack |
| 5 | Linked list operations |
| 6 | Build a BST from an array, inorder traversal, search |
| 7 | BST deletion |
| Extra | Merge two binary trees (`merge2binaryTrees.cpp`) |

### 📝 Data Structures Lab — [`DS_Lab_Task_1/`](DS_Lab_Task_1/)

- Rebuild a binary tree from **preorder + inorder** and **postorder + inorder**
- Convert a binary tree (LCRS) into a general tree
- Balance a skewed BST with a **Red-Black Tree**, including insertions and deletion

### 🧩 Problem Sets — [`ProblemSets/`](ProblemSets/)

Scenario-based exam problems (from `CSE201_Data_Structures_Exam_Questions.pdf`), each applying a data structure to a real-world-style task:

| Problem | Scenario | Data structures / algorithms |
|---|---|---|
| 1.2 | Expression evaluator | Stack |
| 2.1 | Library catalogue sorting | Hybrid sort with comparison counting |
| 2.2 | Library range lookup | Binary search |
| 3.1 | Document editor | Doubly + singly linked lists |
| 3.2 | Undo / redo + formula evaluator | Stacks |
| 4.1 | ER triage queue | Min-heap priority queue, circular queue |
| 4.2 | Patient record sorting | Radix sort, Counting sort |
| 5.1 | File-system tree (size & height) | First-Child Next-Sibling tree |
| 5.2 | File index | BST, leaf counting |
| 6.1 | Balanced index | Red-Black Tree, level-order output |

---

## 📊 Algorithmic Analysis

[`Algorithmic_Analysis/`](Algorithmic_Analysis/) measures real running times with `<chrono>` to check theory against practice:

| Task | Growth rate | Algorithm used |
|---|---|---|
| Task 01 | O(n) | Counting Sort |
| Task 02 | O(2ⁿ) | Tower of Hanoi |
| Task 03 | O(n log n) | Merge Sort |
| Task 04 | O(n²) | Selection Sort |

Results for all runs are collected in [`algorithm_benchmark_results.csv`](Algorithmic_Analysis/algorithm_benchmark_results.csv) (columns: `Algorithm, Input Size, Time, Notes`).

---

## 📎 Resources

[`Random_Resources/`](Random_Resources/) has PDF cheat sheets I put together while studying:

- **DSA:** Lecture 1 overview, sorting algorithms (text + visual versions), Huffman / Scheduling / LCS
- **Statistics:** hypothesis testing, ANOVA, non-parametric tests, regression

---

## 📁 Repository Structure

```text
dsa-journey/
├── Algorithmic_Analysis/    # chrono-based benchmarks + CSV results
├── Continuous_Evaluation/   # weekly lab tasks (week-1 … week-7)
├── DP/                      # dynamic programming (LCS)
├── DS_Lab_Task_1/           # tree reconstruction, LCRS, Red-Black lab
├── Greedy/                  # knapsack, scheduling, Huffman
├── Heap/                    # max-heap, min-heap
├── LinkedList/              # singly & doubly linked lists
├── ProblemSets/             # scenario-based exam problems + question PDF
├── Queue/                   # linear & circular queues
├── Random_Resources/        # PDF cheat sheets (DSA + statistics)
├── Sorting/                 # six sorting algorithms
├── Stack/                   # stack implementations & applications
├── TowerOfHanoi/            # two recursive approaches
├── Trees/                   # binary tree, BST, AVL, Red-Black
└── Readme.md
```

Several folders have their own `Readme.md` with deeper notes on that topic.

---

## 🗺️ Roadmap

- [x] Linked Lists, Stacks, Queues
- [x] Sorting (comparison + non-comparison)
- [x] Binary Trees, BST, AVL, Red-Black Trees
- [x] Heaps
- [x] Greedy Algorithms
- [x] Recursion
- [x] Intro to Dynamic Programming (LCS)
- [x] Empirical complexity analysis
- [ ] Graphs — BFS, DFS, topological sort
- [ ] Shortest paths — Dijkstra, Bellman-Ford, Floyd-Warshall
- [ ] Minimum Spanning Trees — Kruskal, Prim
- [ ] More DP — 0/1 Knapsack, Matrix Chain Multiplication, Edit Distance
- [ ] Backtracking
- [ ] Hashing
- [ ] Competitive programming problems

---

## 🤝 Contributing

This is a personal learning repo, but corrections are welcome. If you find a bug, a wrong complexity claim, or a cleaner approach, feel free to open an **Issue** or a **Pull Request**.

If you're learning DSA yourself: read the concept first, try writing it on your own, and only then compare with the code here. Copying it won't teach you much.

---

## 👨‍💻 Author

**Md. Shamsul Arefin**
Software Engineering student · Institute of Information Technology, University of Dhaka

GitHub: [@shamsularefin707](https://github.com/shamsularefin707)

> **Learn → Implement → Analyze → Practice → Improve**
