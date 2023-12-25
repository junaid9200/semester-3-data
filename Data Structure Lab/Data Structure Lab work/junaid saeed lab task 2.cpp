//checking (palindrome , frequency )

#include<iostream>
using namespace std;
int main()
{
   int a;
   cout<<"Enter the size of the array : ";
   cin>>a;
   char arr[a];
   char *cr=arr;
    cout<<"Enter elements : ";
   for(int i=0 ;i<a ;i ++)
   {
   	 cin>>*cr;
   	 cr++;
 }
 cr=arr;
  char *cr1 = arr + a - 1;
  bool check = true;
  while (cr1 > cr)
    {
        if (*cr != *cr1)
        {
            check = false;
            break;
        }
        cr++;
        cr1--;
    }
    
    if (check)
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }
    cout<<endl;
    cout<<"Now checking the Frequency"<<endl;
    cr=arr;
     cout<<"Enter element : ";
     char element;
     cin>>element;
     int j=0;
     for(int i=0;i<a;i++)
     {
     	if(*cr==element)
     	{
     		j++;
		 }
		 cr++;
	 }
	 cout<<"Frequency of given element : "<<element<<" : "<<j;
 
 
}

