#include <iostream>
using namespace std;

#define MAX 100

class Queue{
    int front, rear;
    int arr[MAX];

    public:
    Queue(){
        front = rear = -1;
    }

    void enqueue(int val){
        if(rear ==  MAX - 1){
            cout << "Queue Overflow";
            return;
        }
        if(front == -1) front = 0; //first Insertion
        arr[++rear] = val;
        cout << "Enqueued Value: " << val << endl; 
    }

    int dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue Underflow";
            return -1;
        }
        int val = arr[front++];

        if(front > rear) front = rear = -1;

        cout << "Dequeued Value: " << val << endl;

        return val;
    }

    bool isEmpty() { return (front == -1 || front > rear); }
    int peek() {return isEmpty() ? -1 : arr[front];}
    void traversal(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }

        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.traversal();     
    q.dequeue();
    q.traversal();     
}
