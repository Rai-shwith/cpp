// Write a C++ program that demonstrates the use of friend functions to calculate the area of a rectangle. The program should involve a Rectangle class with private data members for length and breadth, and a friend function Area() that calculates the area of the rectangle.
#include<iostream>
#include<conio.h> // Not in C++11 and later

using namespace std;

class Rectangle{
    int length;
    int breadth;
public:
    void setDimensions(int l, int b){
        length = l;
        breadth = b;
    }
    friend void Area(Rectangle);
    };  
    
void Area(Rectangle r){
    cout<<"Area = "<<r.length*r.breadth<<endl;
}
int main(){
    Rectangle r;
    r.setDimensions(10, 20);
    Area(r);
    getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
Area = 200
*/