#include<iostream>
#include <string>
using namespace std;
int main(){
	cout<<"Welcome !"<<endl; 
	string user_input;
	int option;
	cout<<"\nEnter a string: ";
	cin>>user_input;
	cout<<"\nSelect One Of The Options Below."<<endl;
	cout<<"1- Check If String is Palindromw."<<endl;
	cout<<"2- Check The Frequency Of Character."<<endl;
	cout<<"3- Exit."<<endl;
	cin>>option;
	int length_of_string = user_input.size();
	length_of_string = length_of_string - 1;
	char *ptr1 = &user_input[0];
	char *ptr2 = &user_input[length_of_string];
	bool palindrome = true;
	if(option==1){
		while(ptr1<ptr2){
			if(*ptr1!=*ptr2){
				palindrome = false;
				break;
			}
			ptr1++;
			ptr2--;		
		}
		if(palindrome){
			cout << "\nThe String is Palindrome."<<endl;
    	} 
		else{
        	cout << "\nThe String is not Palindrome."<<endl;
    	}
	}
	if(option==2){
		char char1;
    	cout<<"Enter The Character To Count Frequency: ";
    	cin>>char1;
    	length_of_string = length_of_string + 1;
    	ptr1 = &user_input[0];
    	int number_of_frequency = 0;
    	for(int i=0;i<length_of_string;i++){
    		if(*ptr1==char1){
    			number_of_frequency++;	
			}
			ptr1++;
		}
		cout<<"\nThe Frequency Of Entered Number is: "<<number_of_frequency;
	}
	if(option==3){
		cout<<"Thanks for using our programe."<<endl;
		abort();
	}  
}
