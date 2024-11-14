// Write a C++ program to implement a Student class that uses a parameterized constructor to initialize the student's name, roll number, and branch. The program should take input for the student's details and display them using a member function.
#include<iostream>
#include<conio.h>
#include <string>

using namespace std;

class Student{
	string name,branch;
	int rollno;
public:
	Student(string,int,string); // Parameterized Constructor declaration
	void display();
};

Student::Student(string n,int r,string  b){ // Parameterized Constructor definition
	name = n;
    rollno = r;
    branch = b;
}

void Student::display(){
	cout<<"\nStudent Details"<<endl;
	cout<<"Name : "<<name<<"\nRoll No. :"<<rollno<<"Branch : "<<branch<<endl;
}

int main(){
    string name, branch;
    int rollno;
    cout<<"Enter the Name: "<<endl;
	cin>>name;
	cout<<"Enter the Roll No.: "<<endl;
	cin>>rollno;
	cout<<"Enter the Branch: "<<endl;
	cin>>branch;
	Student s(name,rollno,branch);
	s.display();
	getch();
	return 0;
}

/*
OUTPUT:
Enter the Name:
Ashwith
Enter the Roll No.:
29
Enter the Branch:
ECE

Student Details
Name : Ashwith
Roll No. :29
Branch : ECE
*/