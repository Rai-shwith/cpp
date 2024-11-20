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

class D : public B
{
    int c;

public:
    void mul();
    void display();
};
void D::mul()
{
    c = b * get_a();
}
void D::display()
{
    cout << "a = " << get_a()<<endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

int main()
{
    D d;
	d.get_ab();
    d.mul();
    d.display();
    getch();
    return 0;
}

/*
OUTPUT:
Enter values for a and b: 4 8
a = 4
b = 8
c = 32
*/
