// Write a C++ program that stores and displays the details of n students. The program should ask the user to input the name, roll number, and marks of each student, and then display the details of all the students.
#include <iostream>
// #include <conio.h> //for getch() comment this line if you using visual studio 2010 or older
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
    Student s[3];
    string name;
    int roll,n;
    float marks;
    cout << "Enter number of students" << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter name, roll and marks of student" << endl;
        cin >> name >> roll >> marks;
        s[i].set(name, roll, marks);
    }
    cout << "Details of students" << endl;
    for(int i=0;i<n;i++){
        s[i].display();
    }
    // getch();
    return 0;
}

/*
OUTPUT:
Enter number of students
3
Enter name, roll and marks of student
Ashwith 29 90
Enter name, roll and marks of student
Arya 24 90
Enter name, roll and marks of student
Arnav 23 90
Details of students
Name: Ashwith
Roll: 29
Marks: 90
Name: Arya
Roll: 24
Marks: 90
Name: Arnav
Roll: 23
Marks: 90
*/