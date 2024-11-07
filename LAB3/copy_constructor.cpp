// Write a C++ program that demonstrates the use of copy constructors. The program should include a class with a default constructor, a parameterized constructor, and a copy constructor. When an object is copied, the copy constructor should be called, and a message should be displayed.
#include <iostream>
#include <conio.h> // Not in C++11 and later

using namespace std;

class example{
    int data;
    public:
    example () {} // Default Constructor
    example(int i){ // Parameterized Constructor
        data = i;
    }
    example(example &sample){ // Copy Constructor
        data = sample.data;
        cout<<"Copy Constructor Called "<<data<<endl;
    }
}

int main(){
    example e1(10);
    example e2(e1);
    getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
Copy Constructor Called 10
*/