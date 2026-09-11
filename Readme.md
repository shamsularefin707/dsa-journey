# 🧠 DSA Journey

> A personal repository documenting my journey of learning, implementing, and practicing **Data Structures and Algorithms using C++**.

This repository contains implementations, academic coursework, algorithmic analysis, problem sets, and practice programs developed throughout my study of **Data Structures & Algorithms**.

The goal of this repository is not simply to collect code, but to build a strong understanding of how data structures and algorithms work internally, analyze their efficiency, and improve problem-solving skills through consistent implementation.

---

## 📌 About This Repository

This repository is a continuously evolving record of my DSA learning journey.

It includes:

- Fundamental data structure implementations
- Algorithm implementations
- Recursive problem solving
- Tree-based data structures
- Heap implementations
- Greedy algorithms
- Sorting algorithms
- Stack and queue applications
- Algorithmic analysis and benchmarking
- University DSA coursework
- Exam and problem-set solutions
- Continuous evaluation tasks

Most implementations are written from scratch in **C++** to focus on understanding the underlying logic rather than relying heavily on built-in data structures or algorithms.

---

## 🛠️ Language & Tools

| Tool | Purpose |
|---|---|
| **C++** | Primary programming language |
| **G++ / GCC** | Compilation |
| **Git** | Version control |
| **GitHub** | Repository and progress tracking |

### C++ Standard

The implementations are generally intended to work with modern C++ compilers, with **C++17** used where required.

Example:

```bash
g++ -std=c++17 filename.cpp -o program
./program
```

---

# 📚 Topics Covered

## 🔗 Linked Lists

The `LinkedList` directory contains implementations of fundamental linked-list operations.

### Singly Linked List

- Node creation
- Insert at head
- Insert at tail
- Insert at a specific position
- Delete from head
- Delete from tail
- Delete from a specific position
- Searching
- Reversing a linked list
- Merge Sort on Linked List
- Binary Search

### Doubly Linked List

- Insert at head
- Insert at tail
- Insert at a specific position
- Insert after a value
- Delete from head
- Delete from tail
- Delete from a specific position
- Delete by value
- Binary Search

📁 **Directory:** `LinkedList/`

---

## 📚 Stack

The `Stack` directory contains both implementation and application-based problems involving stacks.

### Implementations

- Stack using Array
- Stack using Linked List
- Push
- Pop
- Peek
- Empty-state checking
- Dynamic memory allocation

### Applications

- Infix to Postfix conversion
- Postfix expression evaluation

📁 **Directory:** `Stack/`

---

## 🚶 Queue

Queue implementations are based on the **FIFO (First In, First Out)** principle.

### Implementations

- Linear Queue using Array
- Enqueue
- Dequeue
- Peek
- Traversal
- Circular Queue using Array
- Modular arithmetic for circular indexing

📁 **Directory:** `Queue/`

---

## 🌳 Trees

The `Trees` directory contains implementations ranging from fundamental binary trees to self-balancing search trees.

### Binary Trees

- Binary Tree construction
- Manual structural tree generation
- Level-order traversal
- Dynamic level-order parsing
- Console-based tree representation

### Binary Search Trees

- BST construction
- BST operations
- BST traversal
- BST deletion

### AVL Trees

- AVL Tree implementation
- Self-balancing operations

### Red-Black Trees

- Red-Black Tree implementation
- Insertion balancing
- Rotations
- Recoloring
- Tree balancing concepts

📁 **Directory:** `Trees/`

---

## 🏔️ Heap

The `Heap` directory contains implementations of heap-based data structures.

### Implementations

- Max Heap
- Min Heap

These implementations provide practical understanding of heap structure, ordering properties, and priority-based data organization.

📁 **Directory:** `Heap/`

---

## 🔄 Sorting Algorithms

The `Sorting` directory contains implementations of several fundamental sorting algorithms.

| Algorithm | File |
|---|---|
| Selection Sort | `Selection_Sort.cpp` |
| Insertion Sort | `Insertion_Sort.cpp` |
| Merge Sort | `Merge_Sort.cpp` |
| Quick Sort | `Quick_Sort.cpp` |
| Counting Sort | `Counting_Sort.cpp` |
| Radix Sort | `Radix_Sort.cpp` |

The implementations are intended to help understand the logic, behavior, and complexity of different sorting techniques.

📁 **Directory:** `Sorting/`

---

## 🧠 Greedy Algorithms

The `Greedy` directory contains problems that demonstrate greedy problem-solving strategies.

### Implementations

- Fractional Knapsack
- Huffman Coding
- Time Scheduling

📁 **Directory:** `Greedy/`

---

## 🗼 Tower of Hanoi

The `TowerOfHanoi` directory contains recursive implementations of the classic **Tower of Hanoi** problem.

The problem demonstrates:

- Recursion
- Divide-and-conquer thinking
- Recursive state transitions
- Mathematical growth of operations

Two different recursive implementations are included for comparison and practice.

📁 **Directory:** `TowerOfHanoi/`

---

# 📊 Algorithmic Analysis

The `Algorithmic_Analysis` directory contains coursework and experiments related to analyzing algorithm performance.

It currently includes:

- Algorithmic analysis tasks
- Multiple C++ task implementations
- Benchmarking experiments
- Algorithm benchmark results

📁 **Directory:** `Algorithmic_Analysis/`

The benchmark results are stored in:

```text
algorithm_benchmark_results.csv
```

This section focuses on understanding how algorithm performance changes with input size and implementation strategy.

---

# 🧪 Continuous Evaluation

The `Continuous_Evaluation` directory contains weekly and continuous-assessment programming tasks.

It includes:

- Week-based C++ implementations
- Binary tree problems
- Binary tree merging
- Additional tree-related exercises

📁 **Directory:** `Continuous_Evaluation/`

---

# 📝 Data Structures Lab

The `DS_Lab_Task_1` directory contains solutions for university Data Structures laboratory assignments.

Topics include:

- Binary tree reconstruction
- Preorder + Inorder reconstruction
- Postorder + Inorder reconstruction
- Binary Tree to General Tree conversion
- Red-Black Tree concepts
- Tree balancing
- Rotations
- Recoloring

📁 **Directory:** `DS_Lab_Task_1/`

---

# 🧩 Problem Sets

The `ProblemSets` directory contains additional DSA problems and practice solutions.

It includes:

- C++ problem-solving exercises
- Numbered problem sets
- University examination-related problems
- A collection of Data Structures exam questions

📁 **Directory:** `ProblemSets/`

---

# 📁 Repository Structure

```text
dsa-journey/
│
├── Algorithmic_Analysis/
│   ├── Task_01/
│   ├── Task_02.cpp
│   ├── Task_03.cpp
│   ├── Task_04.cpp
│   └── algorithm_benchmark_results.csv
│
├── Continuous_Evaluation/
│   ├── merge2binaryTrees.cpp
│   ├── mergeBT/
│   ├── week-1_1.cpp
│   ├── week-1_2.cpp
│   ├── week-2_1.cpp
│   ├── week-2_2.cpp
│   ├── week-3_1.cpp
│   ├── week-3_2.cpp
│   ├── week-3_3.cpp
│   ├── week-4_1.cpp
│   ├── week-4_2.cpp
│   ├── week-4_3.cpp
│   ├── week-4_4.cpp
│   ├── week-5.cpp
│   ├── week-6.cpp
│   └── week-7.cpp
│
├── DS_Lab_Task_1/
│   ├── DS_Task_1_a.cpp
│   ├── DS_Task_1_b.cpp
│   ├── DS_Task_2.cpp
│   ├── DS_Task_3a.cpp
│   ├── DS_Task_3b.cpp
│   ├── DS_Task_4.cpp
│   └── Readme.md
│
├── Greedy/
│   ├── Fractional_Knapsack.cpp
│   ├── Huffman_Coding.cpp
│   ├── Time_Scheduling.cpp
│   └── Time_Scheduling_1.cpp
│
├── Heap/
│   ├── Max_Heap.cpp
│   └── Min_Heap.cpp
│
├── LinkedList/
│   ├── SinglyLinkedList.cpp
│   ├── DoublyLinkedList.cpp
│   └── Readme.md
│
├── ProblemSets/
│   ├── CSE201_Data_Structures_Exam_Questions.pdf
│   ├── Problem_1_2.cpp
│   ├── Problem_2_1.cpp
│   ├── Problem_2_2.cpp
│   ├── Problem_3_1.cpp
│   ├── Problem_3_2.cpp
│   ├── Problem_4_1.cpp
│   ├── Problem_4_2.cpp
│   ├── Problem_5_1.cpp
│   ├── Problem_5_2.cpp
│   ├── Problem_6_1.cpp
│   └── Readme.md
│
├── Queue/
│   ├── LinearQueue_Array.cpp
│   ├── CircularQueue_Array.cpp
│   └── Readme.md
│
├── Sorting/
│   ├── Selection_Sort.cpp
│   ├── Insertion_Sort.cpp
│   ├── Merge_Sort.cpp
│   ├── Quick_Sort.cpp
│   ├── Counting_Sort.cpp
│   └── Radix_Sort.cpp
│
├── Stack/
│   ├── StackUsingArray.cpp
│   ├── StackUsingLinkedList.cpp
│   ├── InfixToPostfix.cpp
│   ├── PostfixEvaluation.cpp
│   └── Readme.md
│
├── TowerOfHanoi/
│   ├── TowerOfHanoi_1.cpp
│   ├── TowerOfHanoi_2.cpp
│   └── README.md
│
├── Trees/
│   ├── General_Binary_Tree_1.cpp
│   ├── General_Binary_Tree_2.cpp
│   ├── BST_1.cpp
│   ├── BST_2.cpp
│   ├── BST_3.cpp
│   ├── Traversal_BST.cpp
│   ├── Deletion_BST.cpp
│   ├── AVL_1.cpp
│   ├── Red_Black_Tree.cpp
│   └── Readme.md
│
└── Readme.md
```

---

# 🎯 Learning Objectives

Through this repository, I am working toward developing a stronger understanding of:

- Data structure fundamentals
- Algorithm design
- Recursion
- Pointer manipulation
- Dynamic memory allocation
- Tree structures
- Searching and sorting
- Algorithmic complexity
- Problem-solving techniques
- Competitive programming fundamentals
- Writing clean and understandable C++ implementations

---

# 📈 Progress

This repository is a **work in progress**.

New implementations, coursework, problems, and experiments will continue to be added as I progress through Data Structures & Algorithms.

### Current Areas

- [x] Linked Lists
- [x] Stacks
- [x] Queues
- [x] Sorting Algorithms
- [x] Binary Trees
- [x] Binary Search Trees
- [x] AVL Trees
- [x] Red-Black Trees
- [x] Heaps
- [x] Greedy Algorithms
- [x] Recursion / Tower of Hanoi
- [x] Algorithmic Analysis
- [x] DSA Coursework
- [x] Problem Sets
- [ ] Graph Algorithms
- [ ] Advanced Dynamic Programming
- [ ] More Competitive Programming Problems

> The checklist represents the current state of the repository and will evolve as new topics are studied and implemented.

---

# 💡 Philosophy

The purpose of this repository is to **learn by implementing**.

Instead of only reading about a data structure or algorithm, I try to understand its internal mechanics by writing the implementation myself.

The general workflow is:

```text
Learn the concept
      ↓
Understand the underlying logic
      ↓
Implement from scratch
      ↓
Test the implementation
      ↓
Analyze complexity
      ↓
Solve related problems
      ↓
Improve the implementation
```

---

# 🚀 Future Plans

The repository will gradually expand toward more advanced DSA topics, including:

- Graphs
- BFS & DFS
- Shortest Path Algorithms
- Minimum Spanning Trees
- Dynamic Programming
- Backtracking
- Advanced Greedy Problems
- Advanced Tree Problems
- Competitive Programming Problems
- More algorithm benchmarking
- Improved documentation and explanations

---

# 📖 How to Use This Repository

If you are learning DSA yourself, a good way to use this repository is to follow the topics progressively:

```text
Foundations
    ↓
Linked Lists
    ↓
Stacks & Queues
    ↓
Sorting
    ↓
Trees
    ↓
Heaps
    ↓
Greedy Algorithms
    ↓
Advanced Algorithms
    ↓
Problem Solving
```

Try understanding the concept first, then inspect the implementation.

Do not simply copy the code. That defeats the entire purpose of learning DSA and turns the repository into an unusually elaborate photocopier.

---

# 🤝 Contributions

This is primarily a personal learning repository, but suggestions, corrections, alternative approaches, and improvements are welcome.

If you notice:

- An incorrect implementation
- A logical issue
- An inefficient approach
- A documentation error
- A better algorithmic solution

feel free to open an **Issue** or submit a **Pull Request**.

---

# ⭐ Acknowledgment

This repository represents an ongoing learning process rather than a finished DSA library.

The implementations may evolve as my understanding improves, and older solutions may be revisited and optimized over time.

---

## 👨‍💻 Author

**Arefin**

Software Engineering Student  
Learning **C++ • Data Structures • Algorithms • Problem Solving**

---

> **Learn → Implement → Analyze → Practice → Improve**

**The journey continues. 🚀**
