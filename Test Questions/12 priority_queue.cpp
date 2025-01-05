#include <iostream>
#define QUEUE_SIZE 5

using namespace std;

class PriorityQueue {
public:
    int frontIndex, rearIndex, queueArray[QUEUE_SIZE];

    PriorityQueue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    void enqueue(int element) {
        if (rearIndex == QUEUE_SIZE - 1) {
            cout << "Queue overflow." << endl;
            return;
        }
        int shiftIndex = rearIndex;
        while (shiftIndex >= frontIndex && element < queueArray[shiftIndex]) {
            queueArray[shiftIndex + 1] = queueArray[shiftIndex];
            shiftIndex--;
        }
        queueArray[shiftIndex + 1] = element;
        rearIndex++;
    }

    void dequeue() {
        if (frontIndex > rearIndex) {
            cout << "Queue underflow." << endl;
        } else {
            cout << "Dequeued: " << queueArray[frontIndex] << endl;
            frontIndex++;
        }
    }

    void display() {
        if (frontIndex > rearIndex) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Priority Queue contents: ";
            for (int i = frontIndex; i <= rearIndex; i++) {
                cout << queueArray[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                pq.enqueue(value);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
/*
OUTPUT:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 2
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 6
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 1
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Priority Queue contents: 1 2 6 
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 
*/