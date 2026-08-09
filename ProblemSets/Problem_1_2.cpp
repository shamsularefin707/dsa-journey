#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int values[100];
int valTop = -1;

char ops[100];
int opTop = -1;

void pushVal(int val) { values[++valTop] = val; }
int popVal() { return values[valTop--]; }

void pushOp(char op) { ops[++opTop] = op; }
char popOp() { return ops[opTop--]; }
char peekOp() { return ops[opTop]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluate(string tokens) {
    valTop = -1;
    opTop = -1;

    for (int i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ') continue;

        if (tokens[i] == '(') {
            pushOp(tokens[i]);
        } 
        else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            pushVal(val);
            i--;
        } 
        else if (tokens[i] == ')') {
            while (opTop != -1 && peekOp() != '(') {
                int val2 = popVal();
                int val1 = popVal();
                char op = popOp();
                pushVal(applyOp(val1, val2, op));
            }
            if (opTop != -1) popOp();
        } 
        else {
            while (opTop != -1 && precedence(peekOp()) >= precedence(tokens[i])) {
                int val2 = popVal();
                int val1 = popVal();
                char op = popOp();
                pushVal(applyOp(val1, val2, op));
            }
            pushOp(tokens[i]);
        }
    }

    while (opTop != -1) {
        int val2 = popVal();
        int val1 = popVal();
        char op = popOp();
        pushVal(applyOp(val1, val2, op));
    }

    return popVal();
}

int main() {
    string expr = "2+3+(5+7)/2+10";
    cout << "Input: " << expr << endl;
    cout << "Output: " << evaluate(expr) << endl;
    return 0;
}