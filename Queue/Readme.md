# Queue Implementations

A **Queue** is a linear data structure that operates on the **FIFO (First In, First Out)** principle. The first element added to the queue is the first one to be removed. 

This directory contains static array-based implementations of both standard linear queues and circular queues.

---

## Files Included

| File Name | Description |
| :--- | :--- |
| `LinearQueue_Array.cpp` | Standard sequential queue utilizing static sizing. Elements are enqueued at the back and dequeued from the front. |
| `CircularQueue_Array.cpp` | Efficient queue structure utilizing modular arithmetic to connect the end back to the front, preventing memory wastage common in linear array queues. |

---

## Core Operations & Complexity

Queue implementations focus on highly optimal access routines:

* **Enqueue / Push** (Insert element at the rear): `O(1)`
* **Dequeue / Pop** (Remove element from the front): `O(1)`
* **Peek / Front** (Inspect the front-most element): `O(1)`
* **isEmpty / isFull** (Check structural limitations): `O(1)`

---

## Compilation & Execution

To compile and execute these implementations locally using `g++`, open your terminal and run:

```bash
# Navigate to the Queue directory
cd Queue

# Compile the Linear Queue implementation
g++ LinearQueue_Array.cpp -o linear_queue

# Run the executable
./linear_queue
