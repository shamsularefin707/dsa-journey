# Stack Implementations & Applications

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The last element added to the stack is the first one to be removed. 

This directory contains foundational implementations of the Stack data structure along with common algorithmic applications.

---

## Files Included

| File Name | Description |
| :--- | :--- |
| `StackUsingArray.cpp` | Implementation of a fixed-size stack using a static array. |
| `StackUsingLinkedList.cpp` | Implementation of a dynamic stack using a linked list (prevents stack overflow). |
| `InfixToPostfix.cpp` | Application: Converts standard infix mathematical expressions to postfix notation. |
| `PostfixEvaluation.cpp` | Application: Evaluates the numerical result of a postfix expression. |

---

## Operations & Time Complexity

For both the array and linked list implementations, core stack operations are highly efficient:

* **Push** (Insert element at the top): `O(1)`
* **Pop** (Remove element from the top): `O(1)`
* **Peek/Top** (View top element without removing): `O(1)`
* **isEmpty** (Check if stack is empty): `O(1)`

---

## Compilation & Execution

To compile and run any of the implementations locally using `g++`, run the following commands in your terminal:

```bash
# Compile the file
g++ FileName.cpp -o program

# Run the executable
./program
