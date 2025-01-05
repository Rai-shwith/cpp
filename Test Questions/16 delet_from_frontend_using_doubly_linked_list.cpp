// write a C++ program that reads a list of integers from the user, and deletes a data from the front end of created list and display the list contents using linear doubly linked List
#include <iostream>
#include <conio.h> // for getch

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = NULL; }
    
    void insert_rear(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = NULL;
        if(!head) {
            head = new_node;
        } else {
            Node* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }

    void delete_from_front() {
        if(!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head) {
            head->prev = NULL;
        }
        delete temp;
    }

    void display() {
        if(!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
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
    
    DoublyLinkedList list;
    for(int i = 0; i < n; i++) {
        list.insert_rear(arr[i]);
    }
    cout << "List: ";
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
Enter the elements: 2 4 6 8 10 12
List: 2 4 6 8 10 12 
List after deleting from front: 4 6 8 10 12 
*/