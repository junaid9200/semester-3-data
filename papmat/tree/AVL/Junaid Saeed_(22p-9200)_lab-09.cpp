#include<iostream>
using namespace std;

struct tree 
{
    int data;
    tree* left;
    tree* right;

    tree(int data) 
	{
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class avltree 
{
public:
    int height(tree* root) 
	{
        if (root == nullptr) 
		{
            return 0;
        } 
		else 
		{
            int left = height(root->left);
            int right = height(root->right);
            if(left>right)
            {
            	return 1+left;
			}
			else 
			{
				return 1+right;
			}
        }
    }

    int balanceFactor(tree* root) 
	{
        if (root == nullptr) 
		{
            return 0;
        } 
		else 
		{
            return height(root->left) - height(root->right);
        }
    }

    tree* insert(tree* root, int data) 
	{
        if (root == nullptr) 
		{
            return new tree(data);
        } 
		else 
		{
            if (data == root->data) 
			{
                cout << "Duplicates exist, element cannot be inserted." << endl;
                return root;
            } 
			else if (data < root->data) 
			{
                root->left = insert(root->left, data);
            } 
			else 
			{
                root->right = insert(root->right, data);
            }

            int balance = balanceFactor(root);

            if (balance > 1 && data < root->left->data) 
			{
				cout<<"right-shift"<<endl;
                return rightRotate(root);
            } 
			else if (balance < -1 && data > root->right->data) 
			{
				cout<<"left-shift"<<endl;
                return leftRotate(root);
            } 
			else if (balance > 1 && data > root->left->data) 
			{
				cout<<"left-right-shift"<<endl;
                root->left = leftRotate(root->left);
                return rightRotate(root);
            } 
			else if (balance < -1 && data < root->right->data) 
			{
				cout<<"right-left-shift"<<endl;
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }
    }
tree* del(tree* root, int data) 
{
    if (root == nullptr) 
	{
        return root;
    } 
	else if (data < root->data) 
	{
        root->left = del(root->left, data);
    } 
	else if (data > root->data) 
	{
        root->right = del(root->right, data);
    } 
	else 
	{
        if (root->left == nullptr) 
		{
            tree* temp = root->right;
            delete root;
            return temp;
        } 
		else if (root->right == nullptr) 
		{
            tree* temp = root->left;
            delete root;
            return temp;
        } 
		else 
		{
            tree* minValueNode = root->right;
            while (minValueNode->left != nullptr) 
			{
                minValueNode = minValueNode->left;
            }
            root->data = minValueNode->data;
            root->right = del(root->right, minValueNode->data);
        }
    }

    if (root == nullptr) 
	{
        return root;
    }

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0) 
	{
		cout<<"right-shift"<<endl;
        return rightRotate(root);
    }

    else if (balance > 1 && balanceFactor(root->left) < 0) 
	{
		cout<<"left-right-shift"<<endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    else if (balance < -1 && balanceFactor(root->right) <= 0) 
	{
		cout<<"leftshift"<<endl;
        return leftRotate(root);
    }

    else if (balance < -1 && balanceFactor(root->right) > 0) 
	{
		cout<<"right-left-shift"<<endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


    tree* rightRotate(tree* root) 
	{
        tree* newRoot = root->left;
        tree* temp = newRoot->right;

        newRoot->right = root;
        root->left = temp;

        return newRoot;
    }

    tree* leftRotate(tree* root) 
	{
        tree* newRoot = root->right;
        tree* temp = newRoot->left;

        newRoot->left = root;
        root->right = temp;

        return newRoot;
    }
    void max(tree* root)
    {
    	tree* curr=root;
    	if(root==nullptr)
    	{
    		cout<<"Tree doesnt exist so max doesnt exist.....!"<<endl;
    		return;
		}
		else
		{
			while(curr->right!=nullptr)
			{
				curr = curr->right;
			}
			cout<<"The max value is : "<<curr->data<<endl;	
		}
	}
	void min(tree* root)
    {
    	tree* curr=root;
    	if(root==nullptr)
    	{
    		cout<<"Tree doesnt exist so max doesnt exist.....!"<<endl;
    		return;
		}
		else
		{
			while(curr->left!=nullptr)
			{
				curr = curr->left;
			}
			cout<<"The min value is : "<<curr->data<<endl;
			
		}
	}
   tree* search(tree* root,int key)
   {
   	tree* curr=root;
   	if(root==nullptr)
   	{
   		cout<<"Tree is empty....!"<<endl;
   		return root;
	   }
	   else
	   {
	   	if(key>curr->data)
	   	{
	   		return search(curr->right,key);
		   }
		   else if(key<curr->data)
		   {
		   	return search(curr->left,key);
		   }
		   else
		   {
		   	return curr;
		   }
	   }
   
   	
   }
   
    void inorder(tree* root) 
	{
        if (root == nullptr) 
		{
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    avltree tree1;
    tree* root = nullptr;
    int value, option;

    while (true) 
	{
    	
        cout << "-----------------------" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Delete a value" << endl;
        cout << "3. Display tree (In order traversal)" << endl;
        cout << "4. Update a value" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Find max" << endl;
        cout << "7. Find min" << endl;
        cout << "8. Exit" << endl;
        cout << "-----------------------" << endl;
        cout<<endl;
        cin >> option;

        if (option == 1) 
		{
            cout << "Enter value to be inserted: ";
            cin >> value;
            root = tree1.insert(root, value);
            cout << "Value inserted successfully." << endl;
        } 
			else if (option ==2)
			{
				if(root==nullptr)
				{
					cout<<"tree not found"<<endl;
					break;
				}
				int del;
				cout<<"Enter the value to be deleted : ";
				cin>>del;
				root=tree1.del(root,del);
			    cout << "Value deleted successfully." << endl;
			}
			
		else if (option == 3) 
		{
            cout << "AVL Tree (In-order Traversal): ";
            tree1.inorder(root);
            cout << endl;
        } 
        	else if (option ==4)
			{
				if(root==nullptr)
				{
					cout<<"root is empty"<<endl;
					break;
				}
				int old;
				cout<<"Enter the value that is going to be update : ";
				cin >>old;
				if(!tree1.search(root,old))
				{
					cout<<"not found...! failed"<<endl;
					break;
				}
				int newn;
				cout<<"Enter the new number :";
				cin>>newn;
				root=tree1.del(root,old);
				root=tree1.insert(root,newn);
				cout<<"Value updated sucessfully"<<endl;
			}
				else if (option ==5)
			{
				int search;
				cout<<"Enter the value to be searched : ";
				cin>>search;
				if(tree1.search(root,search))
				{
					cout<<"key found "<<endl;
				}
				else
				{
					cout<<"key doesnt found "<<endl;
				}
			}
				else if (option ==6)
			{
				tree1.max(root);
			}
				else if (option ==7)
			{
				tree1.min(root);
			}
		else if (option == 8) 
		{
            break;
        }
    }
}

