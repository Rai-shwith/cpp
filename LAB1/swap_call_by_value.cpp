#include<iostream>
#include<conio.h>

using namespace std;

int swap(int x, int y){
	int temp = x;
	x = y;
	y = x;
	cout<<"After Swapping\nx = "<<x<<endl<<"y = "<<y<<endl;
	return 0;
}

int main(){
	int x = 10,y = 20;
	cout<<"Before Swapping\nx = "<<x<<endl<<"y = "<<y<<endl;
	swap(x,y);
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