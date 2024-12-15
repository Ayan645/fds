#include<iostream>
#define MAX 3
using namespace std;

typedef struct Job {
    int ID;        // ID number of a job
    string name;   // Name of the job
} JOB;

class Queue {
private:
    JOB Q[MAX];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isQueueEmpty() { return front == -1; }
    bool isQueueFull() { return rear == MAX - 1; }

    void enQueue(JOB j) {
        if (!isQueueFull()) {
            if (front == -1) {
                front = rear = 0;
                Q[rear] = j;
            } else {
                Q[++rear] = j;
            }
        } else {
            cout << "\nQueue is full!!";
        }
    }

    void dQueue() {
        if (!isQueueEmpty()) {
            if (front == rear) {
                cout << "\n" << Q[front].ID << "  is deleted from Queue";
                front = rear = -1;
            } else {
                cout << "\n" << Q[front].ID << "  is deleted from Queue";
                front++;
            }
        } else {
            cout << "\nQueue is Empty!!";
        }
    }

    void displayQueue() {
        if (!isQueueEmpty()) {
            cout << "\nJob Queue is:\n";
            for (int i = front; i <= rear; i++) {
                cout << "|" << Q[i].ID << "-" << Q[i].name << "| ";
            }
        } else {
            cout << "\nQueue Empty!!";
        }
    }
};

int main() {
    int choice = 0;
    JOB j;
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
            cout << "\nEnter Job ID:";
            cin >> j.ID;
            cout << "\nEnter Job Name:";
            cin >> j.name;
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

This program simulates a job queue using a simple array-based implementation, with operations to add, delete, and display jobs.
1. **Queue**:
   - A queue is a linear data structure that follows the **FIFO (First In, First Out)** principle.
   - Elements are added at the rear and removed from the front.

2. **Key Operations**:
   - **Enqueue (Insertion)**: Adds a job (with ID and Name) at the rear of the queue.
   - **Dequeue (Deletion)**: Removes a job from the front of the queue.
   - **Display**: Displays all jobs currently in the queue.

3. **Algorithm**:
   - Maintain two pointers, `front` and `rear`, to track the positions of the first and last elements in the queue.
   - Enqueue increments the `rear` pointer, and Dequeue increments the `front` pointer. If both pointers are reset to `-1`, the queue is empty.

4. **Limitations**:
   - Static allocation of the queue size (`MAX = 3`) means the size is fixed and cannot grow dynamically.

5. **Applications**:
   - Job scheduling in operating systems.
   - Task management systems.
   - Printing job queues in printers.

6. **Example**:
   - Input: Add Job1 (ID: 101), Add Job2 (ID: 102), Display Queue.
   - Output: `|101-Job1| |102-Job2|`
   - Delete Job: Removes Job1 from the queue.
*/ 
