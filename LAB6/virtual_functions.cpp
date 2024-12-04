
#include <iostream>
#include <conio.h> // for getch()
using namespace std;

class Base{
    public:
    void display(){
        cout<<"Display Base class"<<endl;
    }
    virtual void show(){
        cout<<"Show Base class"<<endl;
    }
};

class Derived:public Base{
    public:
    void display(){
        cout<<"Display Derived class"<<endl;
    }
    void show(){
        cout<<"Show Derived class"<<endl;
    }
};

int main(){
    Base b;
    Derived d;
    Base *bptr;
    cout<<"bptr points to Base class"<<endl;
    bptr=&b;
    bptr->display();
    bptr->show();
    cout<<"bptr points to Derived class"<<endl;
    bptr=&d;
    bptr->display();
    bptr->show();
    getch();
    return 0;
}

/*
OUTPUT:
bptr points to Base class
Display Base class
Show Base class
bptr points to Derived class
Display Base class
Show Derived class
*/