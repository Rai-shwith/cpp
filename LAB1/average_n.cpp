// Write a C++ program that calculates the sum and average of n integers entered by the user.
#include<iostream>
#include<conio.h>  // Not in C++11 and later

using namespace std;
int main(){
	int temp,n,sum=0;
	float avg;
	cout<<"Enter the total number of elements"<<endl;
	cin>>n;
	cout<<"Enter n values"<<endl;
	for (int i=0; i<n; i++){
		cout<<"Enter element "<<i+1<<endl;
		cin>>temp;
		sum+=temp;
	}
	cout<<"Sum = "<<sum<<"\nAverage = "<<sum/n<<endl;
	getch();   // Not in C++11 and later
	return 0;
}

/*
OUTPUT:
Enter the total number of elements
5
Enter n values
Enter element 1
1
Enter element 2
2
Enter element 3
3
Enter element 4
4
Enter element 5
5
Sum = 15
Average = 3
*/