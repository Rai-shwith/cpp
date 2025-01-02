// Write a C++ program, using common friend function, the function is called by reference to exchange the private data members of two classes, display the data before exchange and after exchange
#include <iostream>
#include <conio.h> // comment if you are are using modern compilers

using namespace std;

// Forward declaration of class B
class B;

class A
{
private:
    int dataA;

public:
    A(int val)
    {
        dataA = val;
    }

    void display()
    {
        cout << "Data of class A: " << dataA << endl;
    }

    // Declare friend function
    friend void exchange(A &, B &);
};

class B
{
private:
    int dataB;

public:
    B(int val)
    {
        dataB = val;
    }

    void display()
    {
        cout << "Data of class B: " << dataB << endl;
    }

    // Declare friend function
    friend void exchange(A &, B &);
};

// Common friend function to exchange data members of two classes
void exchange(A &objA, B &objB)
{
    int temp = objA.dataA;
    objA.dataA = objB.dataB;
    objB.dataB = temp;
}

int main()
{
    A objA(10);
    B objB(20);

    cout << "Before exchange:" << endl;
    objA.display();
    objB.display();

    // Call friend function to exchange data
    exchange(objA, objB);

    cout << "\nAfter exchange:" << endl;
    objA.display();
    objB.display();

    getch(); // comment if using modern compilers
    return 0;
}

/*
OUTPUT:
Before exchange:
Data of class A: 10
Data of class B: 20

After exchange:
Data of class A: 20
Data of class B: 10
*/