#include<iostream>
#include<conio.h> // Not in C++11 and later

using namespace std;
class sample2;
class sample1{
    int a;
public:
    void setA(int x){
        a = x;
    }
    friend float mean(sample1, sample2);
};
class sample2{
    int b;
public:
    void setB(int y){
        b = y;
    }
    friend float mean(sample1, sample2);
};
float mean(sample1 s1, sample2 s2){
    return float(s1.a + s2.b)/2;
}
int main(){
    sample1 s1;
    sample2 s2;
    s1.setA(25);
    s2.setB(30);
    cout<<"Mean = "<<mean(s1, s2)<<endl;
    getch(); // Not in C++11 and later
    return 0;
}

/*
OUTPUT:
Mean = 27.5
*/