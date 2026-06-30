//Infix to Postfix
#include <iostream>
using namespace std;

#define MAX_SIZE 100
char arr[MAX_SIZE];

class Stack{
    char data[MAX_SIZE];
    int top;
    public: 
    Stack(): top(-1) {}
  
    void push(char val){
        if(top == MAX_SIZE - 1){
            cout << "Stack Overflow\n";
        } else {
            top++;
            data[top] = val;
        }
    }
    char pop(){
        if(top == -1){
            cout << "Stack Underflow\n"; 
            return '\0';
        }
        char val = data[top];
        top--;
        return val;
    }
    char peek(){
        if(top == -1){
            cout << "Stack is empty\n"; 
            return '\0';
        }
        return data[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

bool isCharacter(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
}

bool isSpace(char ch){
    return ch == ' ';
}
bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
void infixToPostfix(const char* infix, char* postfix){
    Stack s;
    int j = 0;
    for(int i = 0; infix[i] != '\0'; i++){
        char ch  = infix[i];

        if(isSpace(ch)){
            continue;
        }
        if(isalpha(ch)){
            while(isalnum(ch) || ch == '_'){
                postfix[j++] = infix[i++];

            }
            postfix[j++] = ' ';
            i--;
        }else if(isDigit(ch) || ch == '.'){
            while(isDigit(infix[i]) || infix[i] == '.'){
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }else if(ch == '('){
            s.push(ch);
        }else if(ch == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                postfix[j++] = s.pop();
                postfix[j++] = ' ';
                
            } 
            if(!s.isEmpty() && s.peek() == '('){
                s.pop();
            }
        }else if(isOperator(ch)){
            while(!s.isEmpty() && s.peek() != '(' && precedence(s.peek()) >= precedence(ch)){
                postfix[j++] = s.pop();
                postfix[j++] = ' ';
            } 
            s.push(ch);
        }
    }
    while(!s.isEmpty() && s.peek() != '('){
        postfix[j++] = s.pop();
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int main(){
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    cout << "Enter an infix expression: ";
    cin.getline(infix, MAX_SIZE);
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}