#include<iostream>
#include<conio.h>
using namespace std;


class node
{
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
	    cout<<"Enter the song name :"<<endl;
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
	else 
	 {
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
			cout<<"Song exists in your playlist ."<<endl;
		
			return 0;
		}
		temp=temp->next;
	}
	cout<<"Not available in the playlist ."<<endl;
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
		cout<<"Playlists : "<<endl;
	while(temp!=0)
	{
		cout<<temp->song<<endl;
		temp=temp->next;
	}
}
}
node *alpha;
int playlist(node *temp)
{
	int choice;
	alpha =temp;
	
		if(temp==0)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
     cout<<"Now Playing....."<<endl;
     	cout<<alpha->song<<endl;
     cout<<"Wanna play the next song ?"<<endl;
     cout<<"YES (1)"<<endl<<"NO (2)"<<endl;
     cin>>choice;
     if(choice==1)
     {
     		alpha=alpha->next;
     		cout<<alpha->song<<endl;
    }
	 else if(choice==2)
	 {
	 	 cout<<"Now Playing....."<<endl;
	 	cout<<alpha->song<<endl;
	 }
}
	
}
int main()
{
	node *head=0;
	int option;
	cout<<"\t\t\t ------------WELCOME ----------"<<endl;
	do
	{
		cout<<endl;
		cout<<"\t\t\t------------------------"<<endl;
	    cout<<"\t\t\t\1 Add Song(1)"<<endl;
    	cout<<"\t\t\t\1 Delete Song(2)"<<endl;
	    cout<<"\t\t\t\1 Print playlist(3)"<<endl;
	    cout<<"\t\t\t\1 Search a Song(4)"<<endl;
	    cout<<"\t\t\t\1 Start playlist(5)"<<endl;
	    cout<<"\t\t\t------------------------"<<endl;
	    cout<<endl;
	    cout<<"\t\t\2Enter option :";
	   
       	cin>>option;
    	if(option==1)
	     {
	      cout<<"How much favourite it is ?"<<endl;
	      cout<<"1.Top Favourite:"<<endl;
	      cout<<"2.Least Favourite"<<endl;
	      int favourite;
	      cin>>favourite;
	      insert(head,favourite);
       	  cout<<"playlist:"<<endl;
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
	cout<<"\t\t\t--------THNKS FOR USING--------"<<endl;
}
