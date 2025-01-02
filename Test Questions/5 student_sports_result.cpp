// Create a class Student which reads and displays roll_no of the student. Create another class Test which reads and prints two subject marks, now create one more class SportsMark which reads and prints sports marks of the student, derive a single class Result from all above mentioned classes to find total marks of the student and display it. Use appropriate type of inheritance to implement above program.

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

// Base class Test
class Test {
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

// Base class SportsMark
class SportsMark {
protected:
    int sportsMarks;
public:
    void readSportsMarks() {
        cout << "Enter Sports Marks: ";
        cin >> sportsMarks;
    }

    void displaySportsMarks() {
        cout << "Sports Marks: " << sportsMarks << endl;
    }
};

// Derived class Result from Student, Test, and SportsMark
class Result : public Student, public Test, public SportsMark {
private:
    int total;
public:
    void calculateTotal() {
        total = marks1 + marks2 + sportsMarks;
    }

    void displayResult() {
        displayRollNo();       // Display roll number from Student class
        displayMarks();        // Display marks from Test class
        displaySportsMarks();  // Display sports marks from SportsMark class
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result r;

    // Read roll number, subject marks, and sports marks
    r.readRollNo();
    r.readMarks();
    r.readSportsMarks();

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
Enter Sports Marks: 30

Student Result:
Roll No: 29
Marks for Subject 1: 10
Marks for Subject 2: 20
Sports Marks: 30
Total Marks: 60
*/