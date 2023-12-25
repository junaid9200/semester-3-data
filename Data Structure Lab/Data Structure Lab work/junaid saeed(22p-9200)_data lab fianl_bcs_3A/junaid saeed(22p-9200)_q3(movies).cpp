#include <iostream>
#include <string>

using namespace std;

class Node 
{
public:
    int movieID;
    string title;
    string genre;
    double ratings;
    Node* left;
    Node* right;

    
    Node(int movieID, string title, string genre, double ratings) 
	{
        this->movieID = movieID;
        this->title = title;
        this->genre = genre;
        this->ratings = ratings;
        left = nullptr;
        right = nullptr;
    }
};

class MovieRecommendationSystem 
{
public:
    Node* root;

    // Define the constructor
    MovieRecommendationSystem() 
	{
        root = nullptr;
    }

    // Insert a movie into the BST
    Node* insertMovie(Node* node, int movieID, string title, string genre, double ratings) 
	{
        if (node == nullptr) 
		{
            node = new Node(movieID, title, genre, ratings);
        }
		else if (movieID < node->movieID) 
		{
            node->left = insertMovie(node->left, movieID, title, genre, ratings);
        } 
		else 
		{
            node->right = insertMovie(node->right, movieID, title, genre, ratings);
        }
        return node;
    }

    // Recommend movies of a given genre
    void recommendMoviesByGenre(Node* node, string genre) 
	{
        if (node == nullptr) 
		{
            return;
        }

        recommendMoviesByGenre(node->left, genre);

        if (node->genre == genre) 
		{
            cout << "Movie ID: " << node->movieID << ", Title: " << node->title << ", Ratings: " << node->ratings << endl;
        }

        recommendMoviesByGenre(node->right, genre);
    }

    // Delete a movie by ID
    Node* deleteMovieByID(Node* node, int movieID) 
	{
        if (node == nullptr) 
		{
            return node;
        }

        if (movieID < node->movieID) 
		{
            node->left = deleteMovieByID(node->left, movieID);
        } 
		else if (movieID > node->movieID) 
		{
            node->right = deleteMovieByID(node->right, movieID);
        } 
		else 
		{
            if (node->left == nullptr) 
			{
                Node* temp = node->right;
                delete node;
                return temp;
            } 
			else if (node->right == nullptr) 
			{
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
            	 Node* temp = findMin(node->right);
                 node->movieID = temp->movieID;
                 node->right = deleteMovieByID(node->right, temp->movieID);
			}

           
        }

        return node;
    }

    // Helper function to find the minimum node in a BST
    Node* findMin(Node* node) 
	{
        while (node->left != nullptr) 
		{
            node = node->left;
        }
        return node;
    }

    // Display movies sorted by ratings
    void display(Node* node) 
	{
        if (node == nullptr) 
		{
            return;
        }
        else
        {
        	display(node->left);
            cout <<"--> "<< "Movie ID: " << node->movieID << "; Title: " << node->title << "; Ratings: " << node->ratings << endl;
            display(node->right);
		}

    }
};

int main() 
{
    MovieRecommendationSystem engine;
    int choice;
       cout << "\t\t\t\t----{ Movie Recommendation System }----" << endl;
    while (true) 
	{
	    cout<<endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tMenu:\n";
        cout << "\t\t\t1. Add a Movie\n";
        cout << "\t\t\t2. Delete a Movie by ID\n";
        cout << "\t\t\t3. Recommend Movies by Genre\n";
        cout << "\t\t\t4. Display Movies Sorted by Ratings\n";
        cout << "\t\t\t5. Exit\n";
        cout << "\t\t\t---------------------------------------" << endl;
        cout<<endl;
        cout<<"\t\t--> Enter your choice : ";
        cin >> choice;
        cout<<endl;
        switch (choice) 
		{
            case 1: 
			{
                int movieID;
                string title, genre;
                double ratings;
                cout << "Enter Movie ID: ";
                cin >> movieID;
                cin.ignore(); // Clear newline character from the buffer
                cout << "Enter Movie Title: ";
                getline(cin, title);
                cout << "Enter Movie Genre: ";
                getline(cin, genre);
                cout << "Enter Ratings: ";
                cin >> ratings;

                engine.root = engine.insertMovie(engine.root, movieID, title, genre, ratings);
                cout << "Movie added successfully!" << endl;
                break;
            }
            case 2: 
			{
                int deleteID;
                cout << "Enter Movie ID to delete: ";
                cin >> deleteID;
                engine.root = engine.deleteMovieByID(engine.root, deleteID);
                cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
                break;
            }
            case 3: 
			{
                string genre;
                cout << "Enter your favorite genre: ";
                cin.ignore(); // Clear newline character from the buffer
                getline(cin, genre);
                engine.recommendMoviesByGenre(engine.root, genre);
                break;
            }
            case 4:
            	{
            		engine.display(engine.root);
                    break;	
				}
            case 5:
            	{
            		cout << "Thanks for checking .. it was a great time with you studing this course." << endl;
                    return 0;
            		
			}
            default:
            	{
            		 cout << "oops , invalid input , try again ..." << endl;
                     break;
            		
				}
        }
    }
}

