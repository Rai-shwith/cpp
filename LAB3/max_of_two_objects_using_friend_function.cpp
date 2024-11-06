#include<iostream>
#include<conio.h> // Not in C++11 and later

using namespace std;

class abc;

class xyz{
    int x;
    public:
    void setvalue(int i){
        x = i;
    }
    friend void max(xyz, abc);
};

class abc{
    int a;
    public:
    void setvalue(int i){
        a = i;
    }
    friend void max(xyz, abc);
};  

void max(xyz m, abc n){
    if(m.x > n.a){
        cout<<"Max value is "<<m.x<<endl;
    }
    else{
        cout<<"Max value is "<<n.a<<endl;
    }
}

int main(){
    xyz m;
    abc n;
    m.setvalue(10);
    n.setvalue(20);
    max(m, n);
    getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
Max value is 20
*/