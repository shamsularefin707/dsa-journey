#include <iostream>
#include <sstream>
using namespace std;

#define MAX_SIZE 100
int arr[MAX_SIZE];

class Stack{
    int data[MAX_SIZE];
    int top;
    public: 
    Stack(): top(-1) {}
  
    void push(int val){
        if(top == MAX_SIZE - 1){
            cout << "Stack Overflow\n";
        } else {
            top++;
            data[top] = val;
        }
    }
    int pop(){
        if(top == -1){
            cout << "Stack Underflow\n"; 
            return 0;
        }
        int val = data[top];
        top--;
        return val;
    }
    int peek(){
        if(top == -1){
            cout << "Stack is empty\n"; 
            return 0;
        }
        return data[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};

bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
}
bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int postfixEvaluation(string postfix){
    Stack s;
    stringstream ss(postfix);
    string ch;
    while(ss >> ch){
        if(!isOperator(ch[0])){
            s.push(stoi(ch));
        }else{
            int operand2 = s.pop();
            int operand1 = s.pop();
            
            switch(ch[0]){
                case '+' : s.push(operand1 + operand2); break;
                case '-' : s.push(operand1 - operand2); break;
                case '*' : s.push(operand1 * operand2); break;
                case '/' : s.push(operand1 / operand2); break;
            }
        }
    }
    return s.pop();
}

int main(){
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);
    int result = postfixEvaluation(postfix);
    cout << "Result: " << result << endl;
    return 0;
}