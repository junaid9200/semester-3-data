//swapping two numbers using pointers.

#include<iostream>
using namespace std;
void swapfunc(int *p , int *p2)
{
     int *swap= new int;
     *swap=*p;
     *p=*p2;
     *p2=*swap;
     cout<<"the numbers after  swapping are : "<<*p<<" "<<*p2<<endl;
}


int main()
{
     int a,b;
     int *num1=&a;
     int *num2=&b;
     cout<<"Enter the two numbers : ";
     cin>>*num1>>*num2;
     cout<<"the numbers before swapping are : "<<*num1<<" "<<*num2<<endl;
     swapfunc(num1 , num2);
     
}

