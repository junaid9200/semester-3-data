#include<iostream>
#include<cstring>

using namespace std;
int main(){
	char user_input[50];
	char find;
	char replace;
	char *ptr = user_input;
	cout<<"Enter a String: ";
	cin.getline(user_input, 50);
	cout<<"\nEnter a character to find in string: ";
	cin>>find;
	cout<<"\nEnter a character to replace in string: ";
	cin>>replace;
	
	while(*ptr){
        if(*ptr == find){
            *ptr = replace;
        }
        ptr++;
    }
    cout<<"\nUpdated string: "<<user_input<<endl;
    
    ptr = user_input;
    while(*ptr){
    	*ptr=*ptr-32;
    	ptr++;
	}
    cout<<"Capitalized string: "<<user_input<<endl;
}
