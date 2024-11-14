// Write a C++ program that calculates the average of two numbers entered by the user.
#include<iostream.h>
#include<conio.h>  //for getch()

int main(){
    int a,b;
    float avg;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    avg=(a+b)/2.0;
    cout<<"Average of "<<a<<" and "<<b<<" is "<<avg<<endl;
    getch();
    return 0;
}

/*
OUTPUT:
Enter two numbers
5
6
Average of 5 and 6 is 5.5
*/