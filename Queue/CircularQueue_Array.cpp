#include <iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int front, rear;
    int currSize, capacity;

    public:
    CircularQueue(int size){
        capacity = size;
        arr = new int[capacity];
        front = -1, rear = -1;
        currSize = 0;
    }

    void push(int val){
        if(isFull()){
            cout << "Queue Overflow\n";
            return;
        }

        rear = (rear + 1)%capacity;
        arr[rear] = val;
        cout << "Pushed: " << val << " into the queue\n";
        currSize++;
    }

    int pop(){
        if(isEmpty()){
            cout << "Queue Underflow\n";
            return -1;
        }

        front = (front+1)%capacity;
        int val = arr[front];
        cout << "Popped: " << val << endl;
        currSize--;
        return val;
    }

    void peek(){
        if(isEmpty()){
            cout << "Queue Underflow\n";
            return;
        }
        if(isFull()){
            cout << "Queue Overflow\n";
            return;
        }

        cout << "Val: " << arr[front] << endl;
    }

    bool isEmpty(){
        return currSize == 0;
    }
    bool isFull(){
        return currSize == capacity;
    }
};

int main(){
    CircularQueue cq(10);
    cq.push(10);
    cq.push(1);
    cq.push(9);
    cq.push(11);
    cq.push(19);
    cq.pop();
    cq.pop();
    cq.peek();


    return 0;
}
