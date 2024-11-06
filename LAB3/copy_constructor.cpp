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