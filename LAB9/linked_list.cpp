#include <iostream>
#include <conio.h> // for _getch()

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class list
{
public:
    Node *head;
    int item;
    list()
    {
        head = NULL;
    }

    void insert_front()
    {
        Node *newNode = new Node;
        newNode->data = item;
        newNode->next = head;
        head = newNode;
    }

    void insert_rear()
    {
        Node *newNode = new Node;
        newNode->data = item;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    void delete_front()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *newNode = head;
            head = head->next;
            delete newNode;
        }
    }

    void delete_rear()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            if (prev == NULL)
            {
                head = NULL;
            }
            else
            {
                prev->next = NULL;
            }
            delete curr;
        }
    }

    void search_and_delete()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            while (curr != NULL)
            {
                if (curr->data == item)
                {
                    if (prev == NULL)
                    {
                        head = curr->next;
                    }
                    else
                    {
                        prev->next = curr->next;
                    }
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            cout << "Element not found" << endl;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *curr = head;
            while (curr != NULL)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    list ob;
    int choice;
    int item;
    for (;;)
    {
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at rear" << endl;
        cout << "3. Delete from front" << endl;
        cout << "4. Delete from rear" << endl;
        cout << "5. Search and delete" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted at front : ";
            cin >> ob.item;
            ob.insert_front();
            break;
        case 2:
            cout << "Enter the element to be inserted at rear : ";
            cin >> ob.item;
            ob.insert_rear();
            break;
        case 3:
            ob.delete_front();
            break;
        case 4:
            ob.delete_rear();
            break;
        case 5:
            cout << "Enter the element to be searched and deleted : ";
            cin >> item;
            ob.search_and_delete();
            break;
        case 6:
            ob.display();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    _getch();
    return 0;
}

?
/*
OUTPUT:
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 6
List is empty
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 1
Enter the element to be inserted at front : 5
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 2
Enter the element to be inserted at rear : 10
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 1
Enter the element to be inserted at front : 15
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 6
15 5 10
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 3
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 6
5 10
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 4
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 6
5
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 4
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
Enter your choice: 6
List is empty
1. Insert at front
2. Insert at rear
3. Delete from front
4. Delete from rear
5. Search and delete
6. Display
7. Exit
*/