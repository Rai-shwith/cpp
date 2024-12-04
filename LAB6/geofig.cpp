// Write a program to calculate the area of a triangle and a rectangle using virtual functions. 
#include<iostream>
#include<conio.h> //for getch()

using namespace std;

class geofig{
    public:
    float a,b,area;
    void get_data(){
        cin>>a>>b;
    }
    virtual void display(){
		// Empty
	}
};

class tri:public geofig{
    public:
    void display(){
        area=0.5*a*b;
        cout<<"Height and base of the triangle are: "<<a<<" and "<<b<<endl;
        cout<<"Area of the triangle is: "<<area<<endl;
    }
};

class rect:public geofig{
    public:
    void display(){
        area=a*b;
        cout<<"Length and breadth of the rectangle are: "<<a<<" and "<<b<<endl;
        cout<<"Area of the rectangle is: "<<area<<endl;
    }
};

int main(){
    geofig *ptr;
	tri t1;
	rect r1;
	char c;
	cout<<"Enter the type of figure (t/r): "<<endl;
    cin>>c;
    if(c=='t'){
        cout<<"Enter the height and base of the triangle: "<<endl;
        ptr=&t1;
        ptr->get_data();
        ptr->display();
    }
    else if(c=='r'){
        cout<<"Enter the length and breadth of the rectangle: "<<endl;
        ptr=&r1;
        ptr->get_data();
        ptr->display();
    }
    else{
        cout<<"Invalid input"<<endl;
    }
    getch();
    return 0;
}

/*
OUTPUT:
Enter the type of figure (t/r):
t
Enter the height and base of the triangle:
5 10
Height and base of the triangle are: 5 and 10
Area of the triangle is: 25
*/