// Write a simple program to demonstrate the use of Stack
#include <iostream>
#include <conio.h> // for _getch()
# define stack_size 5

using namespace std;

class stack
{
    int top;
    int s[stack_size]
public:
	int item;
    stack()
    {
        top = -1;
    }
    void push(int item)
    {
        if (top >= stack_size - 1)
            cout << "Stack Overflow" << endl;
        else
            s[++top] = item;
        cout << item << " pushed into stack" << endl;
    }
    void pop()
    {
        if (top < 0)
            cout << "Stack is empty" << endl;
        else
            cout << s[top--] << " popped from stack" << endl;
    }
    void display()
    {
        if (top < 0)
            cout << "Stack is empty" << endl;
        else
            cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack ob;
    int choice;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    for(;;)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be pushed: ";
            cin >> ob.item;
            ob.push(ob.item);
            break;
        case 2:
            ob.pop();
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
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the element to be pushed: 5
5 pushed into stack

Enter your choice: 1
Enter the element to be pushed: 10
10 pushed into stack

Enter your choice: 1
Enter the element to be pushed: 15
15 pushed into stack

Enter your choice: 2
15 popped from stack

Enter your choice: 3
Stack elements are: 5 10

Enter your choice: 2
10 popped from stack

Enter your choice: 2
5 popped from stack

Enter your choice: 2
Stack is empty
*/