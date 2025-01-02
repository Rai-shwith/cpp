// Create a base class Student which reads and displays roll_no of the student. Derive a class test from student class which reads and prints two subject marks, now derive one more class result which inherits the marks from test class of the student, find total marks and display the sum. Use appropriate type of inheritance to implement above program.

#include<iostream>
#include <conio.h> // comment if you are are using modern compilers

using namespace std;

// Base class Student
class Student {
protected:
    int roll_no;
public:
    void readRollNo() {
        cout << "Enter Roll No: ";
        cin >> roll_no;
    }

    void displayRollNo() {
        cout << "Roll No: " << roll_no << endl;
    }
};

// Derived class Test from Student
class Test : public Student {
protected:
    int marks1, marks2;
public:
    void readMarks() {
        cout << "Enter Marks for Subject 1: ";
        cin >> marks1;
        cout << "Enter Marks for Subject 2: ";
        cin >> marks2;
    }

    void displayMarks() {
        cout << "Marks for Subject 1: " << marks1 << endl;
        cout << "Marks for Subject 2: " << marks2 << endl;
    }
};

// Derived class Result from Test
class Result : public Test {
private:
    int total;
public:
    void calculateTotal() {
        total = marks1 + marks2;
    }

    void displayResult() {
        displayRollNo(); // Display roll number from Student class
        displayMarks();  // Display marks from Test class
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result r;

    // Read roll number and marks
    r.readRollNo();
    r.readMarks();

    // Calculate total marks
    r.calculateTotal();

    // Display result
    cout << "\nStudent Result:" << endl;
    r.displayResult();

    getch(); 
    return 0;
}

/*
OUTPUT:
Enter Roll No: 29
Enter Marks for Subject 1: 10
Enter Marks for Subject 2: 20

Student Result:
Roll No: 29
Marks for Subject 1: 10
Marks for Subject 2: 20
Total Marks: 30
*/