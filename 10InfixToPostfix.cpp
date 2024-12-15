#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

class Stack {
private:
    char S[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isStackEmpty() { return top == -1; }
    bool isStackFull() { return top == MAX - 1; }
    void push(char token) {
        if (!isStackFull()) S[++top] = token;
        else cout << "\nStack is full!!";
    }
    char pop() {
        if (!isStackEmpty()) return S[top--];
        else {
            cout << "\nStack is Empty!!";
            return '\0';
        }
    }
    char Top() { return S[top]; }
};

class ExpressionConversion {
private:
    char E[20];
    Stack stk;
public:
    void readExpression() { cin >> E; }
    void displayExpression() { cout << "\nThe input infix expression is: " << E; }
    int ICP(char t) {
        switch (t) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(': return 4;
        }
        return 0;
    }
    int ISP(char t) {
        switch (t) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        }
        return 0;
    }
    void in2Post() {
        char POST[20];
        int i = 0, j = 0;
        while (E[i] != '\0') {
            if (strchr("+-*/^(", E[i])) {
                if (stk.isStackEmpty()) stk.push(E[i]);
                else {
                    while (ICP(E[i]) <= ISP(stk.Top()) && !stk.isStackEmpty()) POST[j++] = stk.pop();
                    stk.push(E[i]);
                }
            } else if (E[i] == ')') {
                while (stk.Top() != '(') POST[j++] = stk.pop();
                stk.pop();
            } else POST[j++] = E[i];
            i++;
        }
        while (!stk.isStackEmpty()) POST[j++] = stk.pop();
        POST[j] = '\0';
        cout << "\nThe postfix expression is: " << POST;
    }
};

int main() {
    int choice = 0;
    ExpressionConversion obj;
    while (choice != 4) {
        cout << "\n***************INFIX to POSTFIX*****************";
        cout << "\n1. Read Infix Expression";
        cout << "\n2. Display Infix Expression";
        cout << "\n3. Convert Expression";
        cout << "\n4. Exit Application";
        cout << "\nWhat is your choice::";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter Infix Parenthesized Expression:";
            obj.readExpression();
            break;
        case 2:
            obj.displayExpression();
            break;
        case 3:
            obj.in2Post();
            break;
        case 4:
            cout << "\nGood Bye!!";
            break;
        }
    }
    return 0;
}

/*
Theory:

This program converts an infix expression (e.g., A+B*C) to a postfix expression (e.g., ABC*+).
1. **Infix, Postfix, and Prefix Expressions**:
   - **Infix**: Operators are between operands (e.g., A+B).
   - **Postfix**: Operators follow operands (e.g., AB+).
   - **Prefix**: Operators precede operands (e.g., +AB).

2. **Algorithm**:
   - **Incoming Precedence (ICP)**: Determines how the incoming operator interacts with the stack.
   - **In-Stack Precedence (ISP)**: Determines how operators inside the stack compare to incoming ones.
   - Use a stack to hold operators. Operands go directly to the output string.

3. **Applications**:
   - Simplifies evaluation of expressions, especially in compilers.
   - Eliminates the need for parentheses to denote operation order.

4. **Example**:
   - Input: `(A+B)*C`
   - Postfix Output: `AB+C*`
*/
