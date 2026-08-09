#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

string undoStack[100];
int undoTop = -1;

string redoStack[100];
int redoTop = -1;

void pushUndo(string action) { undoStack[++undoTop] = action; }
string popUndo() { return undoStack[undoTop--]; }

void pushRedo(string action) { redoStack[++redoTop] = action; }
string popRedo() { return redoStack[redoTop--]; }

void executeAction(string action) {
    pushUndo(action);
    redoTop = -1;
    cout << "Executed: " << action << "\n";
}

void undo() {
    if (undoTop >= 0) {
        string action = popUndo();
        pushRedo(action);
        cout << "Undone: " << action << "\n";
    }
}

void redo() {
    if (redoTop >= 0) {
        string action = popRedo();
        pushUndo(action);
        cout << "Redone: " << action << "\n";
    }
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    char st[100];
    int top = -1;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st[++top] = '(';
        } else if (c == ')') {
            while (top != -1 && st[top] != '(') {
                result += st[top--];
            }
            if (top != -1) top--;
        } else {
            while (top != -1 && prec(st[top]) >= prec(c)) {
                result += st[top--];
            }
            st[++top] = c;
        }
    }

    while (top != -1) {
        result += st[top--];
    }

    return result;
}

int evaluatePostfix(string exp) {
    int st[100];
    int top = -1;

    for (int i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i])) {
            st[++top] = exp[i] - '0';
        } else {
            int val1 = st[top--];
            int val2 = st[top--];
            switch (exp[i]) {
                case '+': st[++top] = val2 + val1; break;
                case '-': st[++top] = val2 - val1; break;
                case '*': st[++top] = val2 * val1; break;
                case '/': st[++top] = val2 / val1; break;
                case '^': st[++top] = pow(val2, val1); break;
            }
        }
    }
    return st[top];
}

int main() {
    executeAction("Type 'Hello'");
    executeAction("Type 'World'");
    undo();
    redo();

    cout << "\n--- Formula Evaluator ---\n";
    string infix = "5+3*2^2";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << "\n";
    cout << "Postfix: " << postfix << "\n";
    cout << "Evaluated: " << evaluatePostfix(postfix) << "\n";

    return 0;
}