#include<iostream>
#include<conio.h>
using namespace std;
class node{
	public:
	string song;
	node* next;
};
int count=0;
node *temp;
int insert(node* &temp_head,int fav)
{
    node *new_node=new node;
	new_node->next=0;
	cout<<"Enter song:";
	cin>>new_node->song;
	if(fav==1)
{
	if(temp_head==0)
	{
		temp_head=new_node;
		temp=new_node;
	}
	else
	  new_node->next=temp_head;
	  temp_head=new_node;
	  temp=temp_head;
}
     else if(fav==2)
{
     if(temp_head==0)
	{
		temp_head=new_node;
		temp=new_node;
	}
	else{
    temp->next=new_node;
    temp=new_node;
        }
}
}
int delet(node* &temp_head,string name)
{
	node *trash=new node;
	trash=temp_head;

	if(trash==0)
	{
		cout<<"Empty"<<endl;
		return 0;
	}
	while(trash!=0)
	{
		if(trash->next->song==name)
		{
			trash->next=trash->next->next;
			break;
		}
		trash=trash->next;
	}
//	delete trash;
}
int search(node *temp,string name)
{
	if(temp==0)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
	while(temp!=0)
	{
		if(temp->song==name)
		{
			cout<<"Song present"<<endl;
		
			return 0;
		}
		temp=temp->next;
	}
	cout<<"Not present"<<endl;
}
}

int print_song(node *temp)
{
	if(temp==0)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
	while(temp!=0)
	{
		cout<<temp->song<<endl;
		temp=temp->next;
	}
}
}
int playlist(node *temp)
{
		if(temp==0)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
	cout<<temp->song<<endl;
	
}
	
}
int main()
{
	node *head=0;
	int option;
	do
	{
	cout<<"Add Song:"<<endl;
	cout<<"Delete Song:"<<endl;
	cout<<"Print Song:"<<endl;
	cout<<"Search a Song:"<<endl;
	cout<<"Start playlist :"<<endl;
	cout<<"Enter option:";
	cin>>option;
	if(option==1)
	{
	cout<<"Enter song type:"<<endl;
	cout<<"1.Favourite:"<<endl;
	cout<<"2.Un_Favourite"<<endl;
	int favourite;
	cin>>favourite;
	insert(head,favourite);
	print_song(head);
    }
    else if(option==2)
    {
    	string name;
    	cout<<"Enter song name:";
    	cin>>name;
    	delet(head,name);
	}
    else if(option==3)
    {
    	print_song(head);
    	
	}
	else if(option==4)
	{
		string name;
    	cout<<"Enter song name:";
    	cin>>name;
		search(head,name);
		
	}
	else if(option==5)
	{
		playlist(head);
	}
	
}
	while(option<6);
}
