// Write a C++ program, to perform addition of two complex numbers, use default and parameterized constructor and display the both complex numbers and sum of two complex numbers. (e.g. 2+3j)

#include<iostream>
#include <conio.h> // comment if you are are using modern compilers

using namespace std;

class Complex {
private:
    int real;
    int imag;
public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // Function to display complex number
    void display() {
        cout << real << " + " << imag << "j" << endl;
    }

    // Function to add two complex numbers
    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main() {
    // Create complex numbers using parameterized constructor
    Complex c1(2, 3);
    Complex c2(4, 5);

    // Display the complex numbers
    cout << "Complex Number 1: ";
    c1.display();
    cout << "Complex Number 2: ";
    c2.display();

    // Add the complex numbers
    Complex c3 = c1.add(c2);

    // Display the sum of complex numbers
    cout << "Sum of Complex Numbers: ";
    c3.display();

    getch(); 
    return 0;
}

/*
OUTPUT:
Complex Number 1: 2 + 3j
Complex Number 2: 4 + 5j
Sum of Complex Numbers: 6 + 8j
*/