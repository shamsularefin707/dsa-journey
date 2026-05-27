#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr){}
};

class Stack{
    Node* top;
    int size;

    public:
    Stack(): top(nullptr), size(0){}

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
        cout << "Pushed " << value << " to stack." << endl;
    }
    
    void pop(){
        if(top == nullptr){
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        size--;
        cout << "Popped " << poppedValue << " from stack." << endl;
    }
    void peek(){
        if(top == nullptr){
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    int getSize(){
        return size;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    cout << "Size: " << s.getSize() << endl;
    s.pop();
    s.peek();
    cout << "Size: " << s.getSize() << endl;
    return 0;
}
