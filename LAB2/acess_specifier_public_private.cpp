#include<iostream>
#include<conio.h> // Not in C++11 and later

using namespace std;

class Disp{
	int y;
public:
	int x;
	void display(){
		cout<<"x = "<<x<<endl;
	}

	void setY(int val){
        y = val;
    }
    void showY(){
        cout<<"y = "<<y<<endl;
    }

};

int main(){
	Disp obj1;
	obj1.x = 5;
	obj1.display();
    obj1.setY(10);
    obj1.showY();
	getch(); // Not in C++11 and later
	return 0;
}

/*
OUTPUT:
x = 5
y = 10
*/