// Write a C++ program that accepts the name, roll number, and marks of a student, then displays the student's details using a class.
#include <iostream>
#include <conio.h> //for getch() comment this line if you using visual studio 2010 or older
#include <string>

using namespace std;

class Student {
        string name;
        int roll;
        float marks;
    public:
        void display() {
            cout << "Name: " << name << endl;
            cout << "Roll: " << roll << endl;
            cout << "Marks: " << marks << endl;
        }
        void set(string n, int r, float m) {
            name = n;
            roll = r;
            marks = m;
        }
};

int main(){
    Student s1;
    string name;
    int roll;
    float marks;
    cout << "Enter name, roll and marks of student" << endl;
    cin >> name >> roll >> marks;
    s1.set(name, roll, marks);
    s1.display();
    getch();
    return 0;
}

/*
OUTPUT:
Enter name, roll and marks of student
Ashwith
29
90
Name: Ashwith 
Roll: 29
Marks: 90
*/