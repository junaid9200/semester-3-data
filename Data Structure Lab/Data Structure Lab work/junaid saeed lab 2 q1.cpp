//

#include<iostream>
using namespace std;
int main()
{
	  
   char input[50];
   char find , replace ;
   cout<<"Enter a word : ";
   cin>>input;
   cout<<"Enter a char to find in the string : ";
   cin>>find;
   cout<<"Enter a character to replace with : ";
   cin>>replace;
   
   char *ptr=input;
   
   while (*ptr!='\0')
   {
   	if(*ptr==find)
   	{
   	   *ptr=replace;
	   }
	   ptr++;
   }
   
    cout<<"Updated string : "<<input;
    ptr=input;
   while (*ptr != '\0')
    {
        if (*ptr >= 'a' && *ptr <= 'z') 
        {
            *ptr = *ptr -32; 
        }
        ptr++;
    }
    cout<<endl;
    cout << "Updated string (after capitalization): " << input;


}

