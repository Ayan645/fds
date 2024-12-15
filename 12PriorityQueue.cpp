#include<iostream>
#define MAX 3
using namespace std;

template <class T>
class ITEM {
public:
    T data;
    int priority;

    bool operator <=(ITEM& ob2) {
        return priority <= ob2.priority;
    }
};

class Queue {
private:
    ITEM<string> Q[MAX];
    int front, rear;
public:
    Queue() { front = rear = -1; }
    bool isQueueEmpty() { return front == -1; }
    bool isQueueFull() { return rear == MAX - 1; }
    void enQueue(ITEM<string> item) {
        int i;
        ITEM<string> temp;
        if (!isQueueFull()) {
            if (front == -1) {
                front = rear = 0;
                Q[rear] = item;
            } else {
                Q[++rear] = item;
                for (i = rear; i > 0; i--) {
                    if (Q[i] <= Q[i - 1]) {
                        temp = Q[i];
                        Q[i] = Q[i - 1];
                        Q[i - 1] = temp;
                    }
                }
            }
        } else {
            cout << "\nQueue is full!!";
        }
    }
    void dQueue() {
        int i;
        if (!isQueueEmpty()) {
            if (front == rear) {
                cout << "\n" << Q[front].data << " is deleted from Queue";
                front = rear = -1;
            } else {
                cout << "\n" << Q[front].data << " is deleted from Queue";
                for (i = 0; i < rear; i++) Q[i] = Q[i + 1];
                rear--;
            }
        } else {
            cout << "\nQueue is Empty!!";
        }
    }
    void displayQueue() {
        if (!isQueueEmpty()) {
            cout << "\nJob Queue is:\n";
            for (int i = front; i <= rear; i++)
                cout << "|" << Q[i].data << "-" << Q[i].priority << "| ";
        } else {
            cout << "\nQueue Empty!!";
        }
    }
};

int main() {
    int choice = 0;
    ITEM<string> j;
    Queue obj;
    while (choice != 4) {
        cout << "\n***************JOB QUEUE*****************";
        cout << "\n1. Add Job in Queue";
        cout << "\n2. Delete Job from Queue";
        cout << "\n3. Display Job Queue";
        cout << "\n4. Exit Application";
        cout << "\nWhat is your choice::";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter Item Name:";
            cin >> j.data;
            cout << "\nEnter Job priority:";
            cin >> j.priority;
            obj.enQueue(j);
            break;
        case 2:
            obj.dQueue();
            break;
        case 3:
            obj.displayQueue();
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

This program implements a priority queue using an array-based approach, where elements are inserted in order based on their priority.
1. **Priority Queue**:
   - A priority queue is a special type of queue where each element is associated with a priority.
   - Elements with higher priority are served before elements with lower priority.

2. **Key Operations**:
   - **Enqueue (Insertion)**: Adds an item to the queue, maintaining the order based on priority.
   - **Dequeue (Removal)**: Removes the item with the highest priority.
   - **Display**: Shows the current elements in the queue along with their priorities.

3. **Algorithm**:
   - Insert elements in sorted order after every insertion to ensure higher priority elements are at the front.
   - For deletion, remove the front element, as it has the highest priority.

4. **Applications**:
   - Process scheduling in operating systems.
   - Handling tasks in real-time systems.
   - Pathfinding algorithms like Dijkstra’s.

5. **Example**:
   - Input: `["Task1", 2], ["Task2", 1], ["Task3", 3]`
   - Queue: `|Task2-1| Task1-2 | Task3-3|`
   - Dequeue: Removes `Task2`.
*/ 
