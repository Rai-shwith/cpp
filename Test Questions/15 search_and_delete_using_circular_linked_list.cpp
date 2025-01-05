// Write a C++ programs, that reads a list of integers form that reads a list of integers from the user, and search for a particular key in the created list if search is successful then delete it and update the rest list and display the list contents using Circular linked list.
#include <iostream>
#include <conio.h> // for getch

using namespace std;

struct Node {
    int data;
    Node* link;
};

class CircularLinkedList {
public:
    Node* last;
    CircularLinkedList() { last = NULL; }

    void insert_rear(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        if(!last) {
            last = new_node;
            last->link = last;
        } else {
            new_node->link = last->link;
            last->link = new_node;
            last = new_node;
        }
    }

    void construct_linked_list_from_array(int* arr, int n) {
        for(int i = 0; i < n; i++){
            insert_rear(arr[i]);
        }
    }

    void search_and_delete(int key) {
        if(!last) {
            cout << "List is empty" << endl;
            return;
        }
        Node *curr = last->link, *prev = last;
        do {
            if(curr->data == key) {
                // If there's only one node in the list
                if(curr == last && curr->link == last) {
                    delete curr;
                    last = NULL;
                }
                // If the key is in the first node of the list
                else if(curr == last->link) {
                    last->link = curr->link;
                    delete curr;
                }
                // If the key is in the last node of the list
                else if(curr == last) {
                    prev->link = curr->link;
                    last = prev;
                    delete curr;
                }
                // Otherwise, it's in a middle node
                else {
                    prev->link = curr->link;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->link;
        } while(curr != last->link);
        cout << "Key not found" << endl;
    }

    void display() {
        if(!last) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = last->link;
        do {
            cout << temp->data << " ";
            temp = temp->link;
        } while(temp != last->link);
        cout << endl;
    }
};

int main() {
    int n, arr[100], key;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    CircularLinkedList list;
    list.construct_linked_list_from_array(arr, n);
    cout << "Enter the key to search and delete: ";
    cin >> key;
    list.search_and_delete(key);
    cout << "List after deleting the key: ";
    list.display();
    getch();
    return 0;
}