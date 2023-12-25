//

#include<iostream>
using namespace std;

class node
{
    public:
    	
    int val;
    node *next;
    
    node(int val)
    {
    	this->val=val;
    	next=NULL;
	}
	
              
};

class stack 
{
	private: 
	node *top;
	int lim;
	int len;
	
	public:
		stack(int lim)
		{
			this->lim=lim;
			top=NULL;
		}
		
	void push(int val)
	{
		node *temp=new node(val);
		temp->next=top;
		top=temp;
		len++;
		cout<<"The number "<<temp->val<<" is pushed ."<<endl;
		
	}
	int pop()
	{
		node *temp=top;
		int val=top->val;
		top=top->next;
		delete temp;
		temp=NULL;
		len--;
		return val;
	}
	
	void display()
	{
		
        node *temp=top;
        while(temp!=NULL)
        {
        	 cout<<temp->val<<endl;
             temp=temp->next;
		}
           cout<<endl;
	}
		
};


int main()
{
	int s;
	int b;
	
	stack a(2);
	
	cout<<"Enter the number to be pushed : ";
	cin>>s;
	a.push(s);
	cout<<"Enter the number to be pushed : ";
	cin>>b;
	a.push(b);
	cout<<endl;
	cout<<"Before swapping :  "<<endl;
	a.display();
	cout<<"After Swapping : "<<endl;
	b=a.pop();
	s=a.pop();
	cout<<s<<endl<<b;



}

