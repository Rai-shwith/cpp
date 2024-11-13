#include <iostream>
#include <conio.h>

using namespace std;

class Complex{
	float real;
	float img;
public:
	Complex(float r,float i);
	Complex operator +(const Complex&);
	void show();
};

Complex::Complex(float r,float i){
	real = r;
	img = i;
}
void Complex::show(){
	if (img>0){
		cout<<real<<"+"<<img<<"i"<<endl;
	}else{
		cout<<real<<img<<"i"<<endl;
	}
}

Complex Complex::operator +(const Complex &other){
	float r = real + other.real;
	float i = img + other.img;
	Complex sum(r,i);
	return sum;
}

int main(){
	Complex complex1(1,1);
	Complex complex2(1,5);
	Complex complex3(4,1);
	Complex complex4(-10,-5);
	Complex sum1 = complex1+complex2;
	sum1.show();
	Complex sum2 = complex3+complex4;
	sum2.show();
	getch();
	return 0;
}

/*
OUTPUT:
2+6i
-6-4i
*/