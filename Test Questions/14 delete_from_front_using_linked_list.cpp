// Write a C++ program, that reads a list of integers from the user, and deletes a data from the frontend of created list and display the list contents using Singly Linked List.
#include <iostream>
#include <conio.h> // for getch

using namespace std;

struct Node {
    int data;
    Node *link;
};

class LinkedList {
public:
    Node *head;
    LinkedList() { head = NULL; }

    void construct_linked_list_from_array(int *arr, int n) {
        Node *temp;
        for (int i = 0; i < n; i++) {
            Node *new_node = new Node;
            new_node->data = arr[i];
            new_node->link = NULL;
            if (!head) {
                head = new_node;
                temp = head;
            } else {
                temp->link = new_node;
                temp = temp->link;
            }
        }
    }

    void delete_from_front() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->link;
        delete temp;
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main() {
    int n, arr[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    LinkedList list;
    list.construct_linked_list_from_array(arr, n);
    cout<< "List: ";
    list.display();
    list.delete_from_front();
    cout << "List after deleting from front: ";
    list.display();
    getch();
    return 0;
}
/*
OUTPUT:
Enter the number of elements: 6
Enter the elements: 1 2 3 4 5 6
List: 1 2 3 4 5 6 
List after deleting from front: 2 3 4 5 6 
*/