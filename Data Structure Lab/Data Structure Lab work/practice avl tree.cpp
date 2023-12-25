//

#include<iostream>
using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
  int height;	
};

int height(node* root)
{
	if(root==nullptr)
	{
		return 0;
	}
	else
	{
		return root->height;
	}
}

int getbalance(node* root)
{
	if(root==nullptr)
	{
		return 0;
	}
	else
	{
		return height(root->left)- height(root->right);
	}
}
int max (int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
node* rightrotation(node* root)
{
	node* x=root->left;
	node* y=x->right;
	
	x->right=root;
	y->left=y;
	
	y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
	
}
node* newnode(int data)
{
	node* node1=new node;
	node1->data=data;
	node1->left=nullptr;
	node1->right=nullptr;
	node1->height=1;
	return node1;
}
node* insert(int data , node* root)
{
	if(root == nullptr)
	{
		return newnode(data);
	}
	else
	{
		if(data == root->data)
		{
			cout<<"Can not insert duplicate exists"<<endl;
			return 0;
		}
		else if(data > root->data)
		{
			node->right=insert(node->right,root);
		}
		else
		{
			node->left=insert(node->left,root);
		}
		
	}
	root->height=1+max(height(root->left),height(root->right));
	int balance=getbalance(root);
	if(balance > 1 || balance < -1)
	{
		if(balance == 1)
	}
}
int main()
{


}

