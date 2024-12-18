// Write a program to implement a circular queue .
#include <iostream>
#include <conio.h> // for getch()

#define size 3

using namespace std;

class CircularQueue
{
    int front, rear;
    int arr[size];
	int count;
    public:
    CircularQueue()
    {	count = 0;
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
	{	
        if (count == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear+1)%size;
            arr[rear] = data;
			count = count+1;
            cout << data << " is enqueued" << endl;
        }
    }
    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << arr[front] << " is dequeued" << endl;
            front = (front+1)%size;
            count--;
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
			int j = 0;
			int i = front;
            while (j<count)
            {
                cout << arr[i] << " ";
				i = (i+1)%size;
				j++;
            }
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue ob;
    int choice;
    int item;
	cout<<"Circular Queue\n";
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
            cout << "Enter the element to be Enqueue : ";
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
Circular Queue
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to be Enqueue : 1
1 is enqueued
Enter your choice: 1
Enter the element to be Enqueue : 2
2 is enqueued
Enter your choice: 1
Enter the element to be Enqueue : 3
3 is enqueued
Enter your choice: 1
Enter the element to be Enqueue : 4
Queue is full
Enter your choice: 3
Queue elements are: 1 2 3
Enter your choice: 2
1 is dequeued
Enter your choice: 2
2 is dequeued
Enter your choice: 2
3 is dequeued
Enter your choice: 2
Queue is empty
Enter your choice:
*/