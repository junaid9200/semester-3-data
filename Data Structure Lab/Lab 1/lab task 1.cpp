#include<iostream>
using namespace std;

void swap(int *ptr1 , int *ptr2){
	static int c = *ptr1;
	static int d = *ptr2;
	*ptr1 = d;
	*ptr2 = c;
	cout<<"\nAfter Swaping"<<endl;
	cout<<"The Value Of a is: "<<*ptr1;
	cout<<"\nThe Value Of b is: "<<*ptr2; 
}

int main(){
	int a , b;
	int *ptr1 , *ptr2;
	
	ptr1 = &a;
	ptr2 = &b;
	
	cout<<"Enter The Value Of a: ";
	cin>>*ptr1;
	cout<<"Enter The Value Of b: ";
	cin>>*ptr2;
	swap(ptr1,ptr2);
}
