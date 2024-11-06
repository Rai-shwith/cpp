// Student Class implementation using default constructor
#include<iostream>
#include<conio.h>
#include <string>

using namespace std;

class Student{
	string name,branch;
	int rollno;
public:
	Student(); // Default Constructor declaration
	void display();
};

Student::Student(){ // Default Constructor definition
	cout<<"Enter the Name: "<<endl;
	cin>>name;
	cout<<"Enter the Roll No.: "<<endl;
	cin>>rollno;
	cout<<"Enter the Branch: "<<endl;
	cin>>branch;
}

void Student::display(){
	cout<<"\nStudent Details"<<endl;
	cout<<"Name : "<<name<<"\nRoll No. :"<<rollno<<"Branch : "<<branch<<endl;
}

int main(){
	Student s;
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
Roll No. :29Branch : ECE
*/