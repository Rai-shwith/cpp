// Write a C++ program that calculates the sum and average of n integers entered by the user using array.
#include<iostream>
#include<conio.h>  //for getch()

using namespace std;
int main(){
	int a[50],n,sum=0;
	float avg;
	cout<<"Enter the total number of elements"<<endl;
	cin>>n;
	cout<<"Enter n values"<<endl;
	for (int i=0; i<n; i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<"Sum = "<<sum<<"\nAverage = "<<sum/n<<endl;
	getch();
	return 0;
}

/*
OUTPUT:
Enter the total number of elements
5
Enter n values
1
2
3
4
5
Sum = 15
Average = 3
*/