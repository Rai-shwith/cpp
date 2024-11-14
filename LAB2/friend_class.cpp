// Write a C++ program that demonstrates the use of friend classes. The program should have two classes, sample1 and sample2. The sample1 class should be able to access the private members of the sample2 class through a friend relationship.
#include <iostream>
#include <conio.h> // Not in C++11 and later

using namespace std;

class sample1;
class sample2
{
    int y, z;

public:
    void setValues(int a, int b)
    {
        y = a;
        z = b;
    }
    friend class sample1;
};
class sample1
{
public:
    void display1(sample2 s)
    {
        cout << "y = " << s.y << endl;
    }

    void display2(sample2 s)
    {
        cout << "z = " << s.z << endl;
    }
};

int main()
{
    sample1 s1;
    sample2 s2;
    s2.setValues(10, 20);
    s1.display1(s2);
    s1.display2(s2);
    getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
y = 10
z = 20
*/