// Write a program to demonstrate the use of pointers to objects.
#include<iostream>
#include<conio.h> //for getch()

using namespace std;
class Date{
    private:
    int day,month,year;
    public:
    Date(){
        day=month=year=0;
    }
    void setDate(int d,int m,int y){
        day=d;
        month=m;
        year=y;
    }
    void printDate(){
        cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl;
    }
};
int main(){
    Date D1,*dptr;
    cout<<"Initializing using the object"<<endl;
    D1.setDate(2,12,2024);
    cout<<"Printing using the object"<<endl;
    D1.printDate();
    dptr=&D1;
    cout<<"Printing using the object pointer"<<endl;
    dptr->printDate();
    cout<<"Initializing using the object pointer"<<endl;
    dptr->setDate(3,12,2024);
    cout<<"Printing using the object"<<endl;
    D1.printDate();
    cout<<"Printing using the object pointer"<<endl;
    dptr->printDate();
    getch();
    return 0;
}

/*
OUTPUT
Initializing using the object
Printing using the object
Date: 2/12/2024
Printing using the object pointer
Date: 2/12/2024
Initializing using the object pointer
Printing using the object
Date: 3/12/2024
Printing using the object pointer
Date: 3/12/2024
*/