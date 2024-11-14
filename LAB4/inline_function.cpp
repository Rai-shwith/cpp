// Write a C++ program using an inline function to find the maximum of two integers.
#include <iostream>
#include <conio.h> // for getch()

using namespace std;
inline int Max(int x, int y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << "Max (20,10): " << Max(20, 10) << endl;
    cout << "Max (0,200): " << Max(0, 200) << endl;
    cout << "Max (100,1010): " << Max(100, 1010) << endl;
    getch();
    return 0;
}

/*
OUTPUT:
Max (20,10): 20
Max (0,200): 200
Max (100,1010): 1010
*/