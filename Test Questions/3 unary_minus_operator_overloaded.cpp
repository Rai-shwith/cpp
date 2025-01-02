// Write a C++ program, to demonstrate unary minus operator is overloaded. 
#include <iostream>
#include <conio.h> // for getch()

using namespace std;

class Space
{
    int x, y, z;
public:
void getdata(int a, int b, int c); 
void display(void);
void operator -();
};

void Space::getdata(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}
void Space::display(void)
{
    cout << "x:" << x << " y:" << y << " z:" << z << "\n";
}
void Space::operator -()
{
    x = -x;
    y = -y;
    z = -z;
}

int main()
{
    Space S;
    S.getdata(10, -20, 30);
    cout << "S: ";
    S.display();
    -S;
    cout << "S: ";
    S.display();
    getch();
    return 0;
}

/*
OUTPUT:
S: x:10 y:-20 z:30
S: x:-10 y:20 z:-30
*/