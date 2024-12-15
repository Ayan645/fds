#include<iostream>
#define MAX 3
using namespace std;

class DQueue {
private:
    int Q[MAX];
    int front, rear;
public:
    DQueue() { front = rear = -1; }

    void addBeginDQueue(int val) {
        if (front != 0) {
            if (front == -1) {
                front = rear = 0;
                Q[front] = val;
            } else {
                Q[--front] = val;
            }
        } else {
            cout << "\nDQueue is full at front!!";
        }
    }

    void delBeginDQueue() {
        if (front != -1) {
            if (front == rear) {
                cout << Q[front] << "  is deleted from DQueue";
                front = rear = -1;
            } else {
                cout << Q[front] << "  is deleted from DQueue";
                front++;
            }
        } else {
            cout << "\nDQueue is Empty!!";
        }
    }

    void addEndDQueue(int val) {
        if (rear != MAX - 1) {
            if (front == -1) {
                front = rear = 0;
                Q[rear] = val;
            } else {
                Q[++rear] = val;
            }
        } else {
            cout << "\nDQueue is full at the rear!!";
        }
    }

    void delEndDQueue() {
        if (rear != -1) {
            if (front == rear) {
                cout << "\n" << Q[rear] << "  is deleted from DQueue";
                front = rear = -1;
            } else {
                cout << "\n" << Q[rear] << "  is deleted from DQueue";
                rear--;
            }
        } else {
            cout << "\nDQueue is Empty!!";
        }
    }

    void displayDQueue() {
        if (front != -1) {
            cout << "\nJob DQueue is:\n";
            for (int i = front; i <= rear; i++) cout << Q[i] << " ";
        } else {
            cout << "\nDQueue Empty!!";
        }
    }
};

int main() {
    int choice = 0, val;
    DQueue obj;
    while (choice != 6) {
        cout << "\n***************Double Ended Queue*****************";
        cout << "\n1. Add element at Begin";
        cout << "\n2. Delete element at Begin";
        cout << "\n3. Add element at End";
        cout << "\n4. Delete element at End";
        cout << "\n5. Display DQueue";
        cout << "\n6. Exit Application";
        cout << "\nWhat is your choice::";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter Job ID:";
            cin >> val;
            obj.addBeginDQueue(val);
            break;
        case 2:
            obj.delBeginDQueue();
            break;
        case 3:
            cout << "\nEnter Job ID:";
            cin >> val;
            obj.addEndDQueue(val);
            break;
        case 4:
            obj.delEndDQueue();
            break;
        case 5:
            obj.displayDQueue();
            break;
        case 6:
            cout << "\nGood Bye!!";
            break;
        }
    }
    return 0;
}

/*
Theory:

This program implements a Double-Ended Queue (DQueue), where elements can be added or removed from both ends.
1. **Double-Ended Queue (DQueue)**:
   - A DQueue is a generalized version of a queue that allows insertion and deletion at both the front and rear ends.

2. **Key Operations**:
   - **Add at Begin**: Adds an element at the front of the queue.
   - **Delete at Begin**: Removes an element from the front of the queue.
   - **Add at End**: Adds an element at the rear of the queue.
   - **Delete at End**: Removes an element from the rear of the queue.
   - **Display**: Shows the current contents of the queue.

3. **Algorithm**:
   - Maintain two pointers, `front` and `rear`, to track the ends of the queue.
   - Perform operations while maintaining the integrity of these pointers, ensuring no overflow or underflow.

4. **Applications**:
   - Job scheduling where jobs can be added or removed from both ends.
   - Managing undo/redo operations in software applications.
   - Caching mechanisms in computer systems.

5. **Example**:
   - Operations: Add 10 at End, Add 20 at Begin, Add 30 at End.
   - DQueue: `20 10 30`
   - Delete at Begin: `10 30`
*/
