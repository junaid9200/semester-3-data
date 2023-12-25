#include <iostream>
#include <string>

using namespace std;


struct Gem 
{
    string name;
    int power;
    Gem* left;
    Gem* right;

    Gem(string name, int power) 
	{
        this->name = name;
        this->power = power;
        left = nullptr;
        right = nullptr;
    }
};

class magical
{
private:
    Gem* root;
    int bagpw;
    

public:
    magical() 
	{
        root = nullptr;
        bagpw = 0;
    }
    bool gameov=false;

    void insert(string name, int power) 
	{
        root = insert(root, name, power);
    }

    Gem* insert(Gem* node, string name, int power) 
	{
        if (node == nullptr) 
		{
            return new Gem(name, power);
        }
        if (power < node->power) 
		{
            node->left = insert(node->left, name, power);
        }
		 else 
		 {
            node->right = insert(node->right, name, power);
        }
        return node;
    }

    void display() 
	{
        if (root == nullptr) 
		{
            cout << "The magical tree is empty." << endl;
        } 
		else 
		{
            cout << "Choose traversal algorithm:\n";
            cout << "1. Pre-order\n";
            cout << "2. In-order\n";
            cout << "3. Post-order\n";
            int choice;
            cin >> choice;

            
            switch (choice) 
			{
            	
                case 1:
                	cout << "Magical Tree (Pre-Order) :--> ";
                    displayPreorder(root);
                    break;
                case 2:
                	cout << "Magical Tree (In-Order) :--> ";
                    displayInorder(root);
                    break;
                case 3:
                	cout << "Magical Tree (Post-Order) :--> ";
                    displayPostorder(root);
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
    }

    void displayPreorder(Gem* node) 
	{
        if (node != nullptr) 
		{
            cout << node->name << " (" << node->power << ") ";
            displayPreorder(node->left);
            displayPreorder(node->right);
        }
    }

    void displayInorder(Gem* node) 
	{
        if (node != nullptr) 
		{
            displayInorder(node->left);
            cout << node->name << " (" << node->power << ") ";
            displayInorder(node->right);
        }
    }

    void displayPostorder(Gem* node) 
	{
        if (node != nullptr) 
		{
            displayPostorder(node->left);
            displayPostorder(node->right);
            cout << node->name << " (" << node->power << ") ";
        }
    }

    void searchGem() 
	{
        int powerToSearch;
        cout << "Enter the power of the gem you want to search: ";
        cin >> powerToSearch;
        searchGem(root, powerToSearch);
    }

    void searchGem(Gem* node, int powerToSearch) 
	{
        if (node == nullptr) 
		{
            cout << "Gem not found."<<endl;
            return;
        }
        if (node->power == powerToSearch) 
		{
            cout << "Gem found: " <<"["<< node->name << "," << node->power << "]"<<endl;
        } 
		else if (powerToSearch < node->power) 
		{
            searchGem(node->left, powerToSearch);
        } 
		else 
		{
            searchGem(node->right, powerToSearch);
        }
    }

    void findHighestPowerGem()
	 {
        if (root == nullptr) 
		{
            cout << "The magical tree is empty." << endl;
            return;
        }
        Gem* highestPowerGem = findHighestPowerGem(root);
        cout << "Gem with the highest magical power: " << highestPowerGem->name << " (" << highestPowerGem->power << ")" << endl;
    }

    Gem* findHighestPowerGem(Gem* node) 
	{
		
        if (node->right == nullptr) 
		{
		    return node;
        }
        return findHighestPowerGem(node->right);
    }

   void pluckGem(int x)
{
    if (bagpw == x)
    {
        cout << "You won! Now take your bag and run from the forest." << endl;
        gameov = true;
        return;
    }
    else if(bagpw > x)
    {
    	
        cout << "You lose! More power in the bag, and the bag bursts. Now run and save yourself from the witch." << endl;
        gameov = false;
        return;
	}
    else
    {
        int powerToPluck;
        cout << "Enter the power of the gem you want to pluck and put in your bag: ";
        cin >> powerToPluck;
        root = pluckGem(root, powerToPluck);
        if (bagpw >= x)
        {
            cout << "Power in bag : " << bagpw << endl;
        }
        else
        {
           cout << "Power in bag : " << bagpw << endl;
        }
    }
}


    Gem* pluckGem(Gem* node, int powerToPluck) 
	{
        if (node == nullptr) 
		{
            cout << "Gem not found. You lost! ...." << endl;
            gameov = false;
            return nullptr;
        }
        if (powerToPluck == node->power) 
		{
            cout << "You plucked : " << "["<< node->name<< "," << node->power << "]" << endl;
            bagpw += node->power;
            return removeNode(node);
        } 
		else if (powerToPluck < node->power) 
		{
            node->left = pluckGem(node->left, powerToPluck);
        }
		 else 
		 {
            node->right = pluckGem(node->right, powerToPluck);
        }
        return node;
    }

   Gem* removeNode(Gem* node)
{
    if (node->left == nullptr)
    {
        Gem* rightChild = node->right;
        delete node;
        return rightChild;
    }
    else if (node->right == nullptr)
    {
        Gem* leftChild = node->left;
        delete node;
        return leftChild;
    }
    else
    {
        Gem* minValueNode = findMinValueNode(node->right);
        node->name = minValueNode->name;
        node->power = minValueNode->power;
        node->right = removeNode(node->right); 
    }
    return node;
}


    Gem* findMinValueNode(Gem* node) 
	{  
        while (node->left != nullptr) 
		{
            node = node->left;
        }
        return node;
    }
};

int main() 
{
	cout<<"\t\t\t------ WELCOME TO THE MAGICAL FOREST ------- "<<endl;
	cout<<endl;
	int x;
	cout<<"How much the magical power can your bag hold ? "<<endl<<"-->";
	cin>>x;
	
    magical bag;
    bag.insert("Diamond", 50);
    bag.insert("Ruby", 30);
    bag.insert("Sapphire", 70);
    bag.insert("Pearl", 40);
    bag.insert("Opal", 10);
    bag.insert("Garnet", 60);
    bag.insert("Zircon", 20);
    bag.insert("Jade", 5);

    while (!bag.gameov) 
	{
		cout<<endl;
		cout<<"\t\t\t-------------------------------------------"<<endl;
        cout << "\t\t\t1. Display the magical tree"<<endl;
        cout << "\t\t\t2. Search for a gem by specifying its power"<<endl;
        cout << "\t\t\t3. Find the gem with the highest magical power"<<endl;
        cout << "\t\t\t4. Pluck a gem from thne tree "<<endl;
        cout << "\t\t\t5. Exit the forest"<<endl;
        cout<<"\t\t\t-------------------------------------------"<<endl;
        cout << "\t\tEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                bag.display();
                break;
            case 2:
                bag.searchGem();
                break;
            case 3:
                bag.findHighestPowerGem();
                break;
            case 4:
                bag.pluckGem(x);
                break;
            case 5:
            	cout<<"Happy Ending........\1"<<endl;
                bag.gameov = true;
                break;
            default:
                cout << "Invalid choice !";
        }
    }
}

