// Write a program to demonstrate the use of private inheritance.
#include <iostream>
#include <conio.h> // for getch()

using namespace std;

class B
{
    int a;

public:
    int b;
    void get_ab();
    int get_a();
    void show_a();
};

void B::get_ab()
{
    cout << "Enter values for a and b: ";
    cin >> a >> b;
}
int B::get_a()
{
    return a;
}
void B::show_a()
{
    cout << "a = " << a << endl;
}

class D : private B
{
    int c;

public:
    void mul();
    void display();
};
void D::mul()
{
    get_ab();
    c = b * get_a();
}
void D::display()
{
    show_a();
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

int main()
{
    D d;
    d.mul();
    d.display();
    getch();
    return 0;
}

/*
OUTPUT:
Enter values for a and b: 5 10
a = 5
b = 10
c = 50
*/
