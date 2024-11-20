// Write a program to demonstrate Multilevel Inheritance.
#include <iostream>
#include <conio.h> // for getch()
#include <string>
using namespace std;

class Studet
{
protected:
    string name;
    int roll;

public:
    void get_data(int r, string n)
    {
        name = n;
        roll = r;
    }
    void put_data()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll << endl;
    }
};
class Test : public Studet
{
protected:
    float sub1, sub2;
    public:
    void get_test(float m1,float m2)
    {
        sub1 = m1;
        sub2 = m2;
    }
    void put_test()
    {
        cout << "Marks in Subject 1: " << sub1 << endl;
        cout << "Marks in Subject 2: " << sub2 << endl;
    }
};
class Result : public Test
{
    float total;
    public:
    void display()
    {
        total = sub1 + sub2;
        put_data();
        put_test();
        cout << "Total Marks: " << total << endl;
    }
};

int main(){
	string name;
	int rollno;
	float subj1,subj2;
    Result r;
    cout<<"Enter the roll number of the student: "<<endl;
    cin>>rollno;
    cout<<"Enter the name of the student: "<<endl;
    cin>>name;
    cout<<"Enter the marks of two subjects: "<<endl;
    cin>>subj1>>subj2;
    r.get_data(rollno,name);
    r.get_test(subj1,subj2);
    cout<<"\n\n**********RESULT**********\n\n";
    r.display();
    cout<<"\n\n**************************\n\n";
    getch();
    return 0;
}
/*
OUTPUT:
Enter the roll number of the student:
29
Enter the name of the student:
Ashwith
Enter the marks of two subjects:
99 100


**********RESULT**********

Name: Ashwith
Roll NO: 29
Marks in Subject 1: 99
Marks in Subject 2: 100
Total Marks: 199


**************************
*/