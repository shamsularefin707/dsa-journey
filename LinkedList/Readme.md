# Linked List Implementations

A **Linked List** is a linear data structure where elements (nodes) are not stored in contiguous memory locations. Instead, each node points to the next node using pointers, allowing for dynamic memory allocation and efficient insertions/deletions.

---

## Conceptual Overview

### Singly Linked List
Each node contains a data field and a single pointer (`next`) pointing to the subsequent node. Traversal is strictly forward.

```text
[ Head ] -> [ Data | Next ] -> [ Data | Next ] -> [ Data | Next ] -> NULL
