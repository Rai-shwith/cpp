// Write a C++ programs, that reads a list of integers form that reads a list of integers from the user, and search for a particular key in the created list if search is successful then delete it and update the rest list and display the list contents using singly linked list.
#include <iostream>
#include <conio.h> // for getch

using namespace std;

struct Node
{
    int data;
    Node *link;
};

class LinkedList
{
public:
    Node *head; // head of list
    LinkedList()
    {
        head = NULL;
    }
    void construct_linked_list_from_array(int *, int);
    void search_and_delete(int key);
    void display();
};

void LinkedList::construct_linked_list_from_array(int *arr, int n)
{
    Node *temp;
    for (int i = 0; i < n; i++)
    {
        Node *new_node = new Node;
        new_node->data = arr[i];
        new_node->link = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->link = new_node;
            temp = temp->link;
        }
    }
}

void LinkedList::search_and_delete(int key)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == key)
    {
        Node *temp = head;
        head = head->link;
        delete temp;
        return;
    }
    Node *temp = head;
    while (temp->link != NULL)
    {
        if (temp->link->data == key)
        {
            Node *temp1 = temp->link;
            temp->link = temp->link->link;
            delete temp1;
            return;
        }
        temp = temp->link;
    }
    cout << "Key not found" << endl;
}

void LinkedList::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main(){
    int n,a[100],key;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    LinkedList list;
    list.construct_linked_list_from_array(a,n);
    cout<<"Enter the key to search and delete: ";
    cin>>key;
    list.search_and_delete(key);
    cout<<"List after deleting the key: ";
    list.display();
    getch();
    return 0;
}
/*
OUTPUT:
Enter the number of elements: 5
Enter the elements: 1 2 3 4 5
Enter the key to search and delete: 3
List after deleting the key: 1 2 4 5 
*/