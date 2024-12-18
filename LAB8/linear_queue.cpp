#include <iostream>
#include <conio.h> // for getch()

#define size 5

using namespace std;

class Queue
{
    int front, rear;
    int arr[size];
    public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            arr[rear] = data;
            cout << data << " is enqueued" << endl;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << arr[front] << " is dequeued" << endl;
            front++;
            if (front > rear)
            {
                front = rear = -1;
            }
        }
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue ob;
    int choice;
    int item;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    for(;;)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be Enqueue: ";
            cin >> item;
            ob.enqueue(item);
            break;
        case 2:
            ob.dequeue();
            break;
        case 3:
            ob.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    getch();
    return 0;
}

/*
OUTPUT:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to be Enqueue: 3
3 is enqueued
Enter your choice: 1
Enter the element to be Enqueue: 5
5 is enqueued
Enter your choice: 1
Enter the element to be Enqueue: 0
0 is enqueued
Enter your choice: 2
3 is dequeued
Enter your choice: 2
5 is dequeued
Enter your choice: 2
0 is dequeued
Enter your choice: 2
Queue is empty
Enter your choice:
*/