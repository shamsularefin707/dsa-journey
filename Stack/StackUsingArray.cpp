#include <iostream>
using namespace std;

#define MAX 100

class Stack{
    int arr[MAX];
    int top;

    public:
    Stack(): top(-1){}

    void push(int value){
        if(top == MAX - 1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " to stack." << endl;
        return;
    }

    int pop(){
        if(top == -1){
            cout << "Stack Underflow\n";
            return -1; 
        }
        return arr[top--];
    }
    int peek(){
        if(top == -1){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1) return true;
        return false;
    }
    int size(){
        return top + 1;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element after pop: " << s.peek() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
