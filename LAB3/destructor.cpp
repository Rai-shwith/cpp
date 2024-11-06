#include <iostream>
// #include <conio.h> // Not in C++11 and later

using namespace std;
int count = 0;
class alpha{
    public:
    alpha(){
        count++;
        cout<<"No. of object created "<<count<<endl;
    }
    ~alpha(){
        count--;
        cout<<"No. of object remaining "<<count<<endl;
    }
};

int main(){
    cout<<"Enter main function"<<endl;
    alpha a1, a2, a3,a4;
    {
        cout<<"Entering Block 1"<<endl;
        alpha a5;
    }
    {
        cout<<"Entering Block 2"<<endl;
        alpha a6;
    }
    cout<<"Re-Entering main function"<<endl;
    // getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
Enter main function
No. of object created 1
No. of object created 2
No. of object created 3
No. of object created 4
Entering Block 1
No. of object created 5
No. of object remaining 4
Entering Block 2
No. of object created 5
No. of object remaining 4
Re-Entering main function
No. of object remaining 3
No. of object remaining 2
No. of object remaining 1
No. of object remaining 0
*/