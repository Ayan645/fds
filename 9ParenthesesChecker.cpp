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
};

class BalancedExpression {
private:
    char E[20];
    Stack stk;
public:
    void readExpression() { cin >> E; }
    void checkExpression() {
        bool invalid = false, bracketPresent = false;
        int i = 0;
        while (E[i] != '\0') {
            if (E[i] == '(' || E[i] == '{' || E[i] == '[') {
                bracketPresent = true;
                stk.push(E[i]);
            } else if (E[i] == ')') {
                if (stk.pop() != '(') { invalid = true; break; }
            } else if (E[i] == '}') {
                if (stk.pop() != '{') { invalid = true; break; }
            } else if (E[i] == ']') {
                if (stk.pop() != '[') { invalid = true; break; }
            }
            i++;
        }
        if (!bracketPresent) cout << "\nThe expression is without any parenthesis";
        else if (stk.isStackEmpty() && !invalid) cout << "\nThe expression is well parenthesized!";
        else cout << "\nThe expression is NOT well parenthesized!";
    }
};

int main() {
    int choice = 0;
    BalancedExpression obj;
    while (choice != 4) {
        cout << "\n***************WELL FORMED EXPRESSION*****************";
        cout << "\n1. Read Infix Parenthesized Expression";
        cout << "\n2. Check Expression";
        cout << "\n3. Exit Application";
        cout << "\nWhat is your choice::";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter Infix Parenthesized Expression:";
            obj.readExpression();
            break;
        case 2:
            obj.checkExpression();
            break;
        case 3:
            cout << "\nGood Bye!!";
            break;
        }
    }
    return 0;
}

/*
Theory:

This program uses a stack-based approach to check if an expression is well-parenthesized. It involves:
1. **Stack Data Structure**:
   - A stack is a LIFO (Last In First Out) data structure.
   - It allows push (insert) and pop (remove) operations.

2. **Algorithm**:
   - Scan the input expression character by character.
   - Push opening brackets ('(', '{', '[') onto the stack.
   - On encountering closing brackets (')', '}', ']'), check if the top of the stack matches the corresponding opening bracket. If not, the expression is invalid.
   - At the end, if the stack is empty and no invalid conditions were encountered, the expression is well-parenthesized.

3. **Applications**:
   - Syntax validation in compilers.
   - Evaluating mathematical expressions.
   - Parsing nested structures in programming languages.
*/
