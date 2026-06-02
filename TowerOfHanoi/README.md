# Tower of Hanoi Implementation in C++

The **Tower of Hanoi** is a classic mathematical puzzle and a textbook example of a problem easily solved using **recursion**. 

### 📐 Rules of the Puzzle:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
3. No larger disk may be placed on top of a smaller disk.

---

## 💻 Implementations Included

This directory contains two distinct recursive approaches to solving the puzzle, demonstrating different ways to handle function parameters and state tracking.

### 1. Explicit Auxiliary Passing (`TowerOfHanoi_ExplicitAux.cpp`)
* **Concept:** This approach passes all three pegs (`src`, `dest`, `aux`) explicitly as arguments through every recursive function call.
* **Key Feature:** The roles of the pegs swap explicitly in the arguments during recursion to track which peg acts as the temporary holding area.

### 2. Implicit Auxiliary Calculation (`TowerOfHanoi_ImplicitAux.cpp`)
* **Concept:** This approach optimizes the function signature by only requiring the `src` and `dest` pegs. 
* **Key Feature:** It dynamically calculates the auxiliary peg mathematically using character arithmetic:
  $$\text{aux} = 'A' + 'B' + 'C' - \text{src} - \text{dest}$$
  This keeps the function signature cleaner and reduces the number of arguments passed on the call stack.

---

## 📊 Complexity Analysis

Both implementations share the same algorithmic complexity because they execute the exact same sequence of logical moves.

| Metric | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(2^n)$ | The total number of moves required is $2^n - 1$, where $n$ is the number of disks. |
| **Space Complexity** | $O(n)$ | Driven by the maximum depth of the recursive function call stack. |

---

## 🚀 How to Run

Compile either file using a standard C++ compiler (like `g++`):

```bash
# Compile the explicit version
g++ -o hanoi_explicit TowerOfHanoi_ExplicitAux.cpp

# Run the executable
./hanoi_explicit
