#include<iostream>
#include<conio.h>

using namespace std;

void swap(int &x, int &y){
	x = x + y;
	y = x - y;
	x = x - y;
}

int main(){
	int x = 10,y = 20;
	cout<<"Before Swapping\nx = "<<x<<endl<<"y = "<<y<<endl;
	swap(x,y);
	cout<<"After Swapping\nx = "<<x<<endl<<"y = "<<y<<endl;
	getch();
	return 0;
}

/*
OUTPUT:
Before Swapping
x = 10
y = 20
After Swapping
x = 20
y = 10
*/