#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int severity;
};

class MinHeapPriorityQueue {
    Patient heap[100];
    int size;

public:
    MinHeapPriorityQueue() : size(0) {}

    void enqueue(Patient p) {
        heap[size] = p;
        int curr = size;
        size++;

        while (curr > 0 && heap[curr].severity < heap[(curr - 1) / 2].severity) {
            swap(heap[curr], heap[(curr - 1) / 2]);
            curr = (curr - 1) / 2;
        }
    }

    Patient dequeue() {
        Patient root = heap[0];
        heap[0] = heap[size - 1];
        size--;

        int curr = 0;
        while (2 * curr + 1 < size) {
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;
            int smallest = left;

            if (right < size && heap[right].severity < heap[left].severity) {
                smallest = right;
            }

            if (heap[curr].severity > heap[smallest].severity) {
                swap(heap[curr], heap[smallest]);
                curr = smallest;
            } else {
                break;
            }
        }
        return root;
    }

    bool empty() { return size == 0; }
};

class CircularQueue {
    Patient arr[5];
    int front, rear, count;

public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    bool isFull() { return count == 5; }
    bool isEmpty() { return count == 0; }

    void enqueue(Patient p) {
        if (isFull()) return;
        rear = (rear + 1) % 5;
        arr[rear] = p;
        count++;
    }

    Patient dequeue() {
        Patient p = arr[front];
        front = (front + 1) % 5;
        count--;
        return p;
    }
};

int main() {
    MinHeapPriorityQueue er;
    er.enqueue({"Patient A", 3});
    er.enqueue({"Patient B", 1});
    er.enqueue({"Patient C", 2});

    cout << "ER Treatment Order:\n";
    while (!er.empty()) {
        Patient p = er.dequeue();
        cout << p.name << " (Severity: " << p.severity << ")\n";
    }

    return 0;
}