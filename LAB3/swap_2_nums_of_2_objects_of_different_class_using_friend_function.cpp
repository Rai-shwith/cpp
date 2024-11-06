#include <iostream>
#include <conio.h> // Not in C++11 and later

using namespace std;

class B;
class A{
    public:
    int a;
    void setvalue(int i){
        a = i;
    }
    friend void swap(A &, B &);
};
class B{
    public:
    int b;
    void setvalue(int i){
        b = i;
    }
    friend void swap(A &, B &);
};

void swap(A &m, B &n){
    int temp = m.a;
    m.a = n.b;
    n.b = temp;
}

int main(){
    A m;
    B n;
    m.setvalue(10);
    n.setvalue(20);
    cout<<"Before Swapping\na = "<<m.a<<endl<<"b = "<<n.b<<endl;
    swap(m, n);
    cout<<"After Swapping\na = "<<m.a<<endl<<"b = "<<n.b<<endl;
    getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
Before Swapping
a = 10
b = 20
After Swapping
a = 20
b = 10

*/
