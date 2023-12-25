#include <iostream>
using namespace std;
// declaring node class
class node{
	public:
    string name;
    int favorite_level;
    node* next=nullptr;
};
//declaring playlist class for adding function to program
class playlist{
	public:
    node* head=nullptr;
    void printPlaylist(){
        if(head == nullptr){
            cout<<"Playlist is empty."<<endl;
        }
        else{
        	cout<<"Playlist:\n";
        	node* current = head;
        	while(current != nullptr){
            cout<<"Song: "<<current->name<<", Favorite Level: "<<current->favorite_level<<endl;
            current = current->next;
        	}	
		}
    }	
    void addSong() {
        string name;
        int favorite_level;
        cout<<"Enter the name of song: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Select favorite level."<<endl;
        cout<<"1. Top Favorite."<<endl;
        cout<<"2. Least Favorite."<<endl;
        cout<<"3. Custom."<<endl;
        cout<<"Enter your choice: ";
        cin>>favorite_level;
        node* new_song = new node;
        new_song->name = name;
        new_song->favorite_level = favorite_level;
        new_song->next = nullptr;
        if(head == nullptr || favorite_level == 1){
            new_song->next=head;
            head = new_song;
        } 
		else if(favorite_level == 2){
             if(head == nullptr) {
                head = new_song;
             }
			 else{
                node* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = new_song;
            }
        }
        // for custom 
		else{
			int custom_level;
            int num_songs=playlist_length();
            if(num_songs==0){
                head = new_song;
            }
			else{
                cout<<"Enter custom priority (between 2 and "<<num_songs + 2<<"): ";
                cin>>custom_level;
                if(custom_level<2){
                    custom_level=2;
                }
				else if(custom_level>num_songs + 2){
                    custom_level=num_songs + 2;
                }
                if(custom_level==2){
                    new_song->next=head;
                    head = new_song;
                }
				else{
                    node* prev=head;
                    node* current=head->next;
                    int current_level=3;
                    while(current!=nullptr&&current_level<custom_level){
                        prev = current;
                        current = current->next;
                        current_level++;
                    }
                    prev->next = new_song;
                    new_song->next = current;
                }
            }
        }
        cout<<"Song added successfully.\n";
        printPlaylist();
    }
    void deleteSong() {
        if(head == nullptr) {
            cout<<"List is Empty."<<endl;
        }
        string name;
        cout<<"Enter the song name to delete: ";
        cin.ignore();
        getline(cin, name);
        if(head->name==name){
            node* temp=head;
            head = head->next;
            delete temp;
            cout<<"Song deleted successfully.\n";
            printPlaylist();
            return;
        }
        node* prev = head;
        node* current = head->next;
        while(current != nullptr){
            if(current->name == name){
                prev->next = current->next;
                delete current;
                cout<<"Song deleted successfully.\n";
                printPlaylist();
                return;
            }
            prev=current;
            current=current->next;
        }
        cout<<"Not Found!"<<endl;
    }
    void playPlaylist(){
        if(head==nullptr){
            cout<<"Playlist is empty.\n";
            return;
        }
		else{
			node* current = head;
        	cout<<"Playing: "<<current->name<<endl;
        	current=current->next;	
		}	
    }
    int playlist_length() {
        int length = 0;
        node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }
    void searchSong(){
    	string name;
        cout<<"Enter song name to search: ";
        cin.ignore();
        getline(cin, name);
        node* current=head;
        if(head==nullptr){
            cout<<"Playlist is empty.\n";
            return;
        }
        while(current != nullptr){
            if(current->name==name){
                cout<<"Song: "<<current->name<<", Favorite Level: "<<current->favorite_level<<endl;
                return;
            }
            current=current->next;
        }
        cout<<"Song not found in the playlist.\n";
    }    
};
int main() {
    playlist playlist;
	int user_input;
    while(true){
        cout<<"Menu:"<<endl;
        cout<<"1. Add a Song"<<endl;
        cout<<"2. Delete a Song"<<endl;
        cout<<"3. Search for a Song"<<endl;
        cout<<"4. Print Playlist"<<endl;
        cout<<"5. Play Playlist"<<endl;
        cout<<"Your Input: ";
        cin>>user_input;
        switch(user_input){
            case 1:
                playlist.addSong();
                break;
            case 2:
                playlist.deleteSong();
                break;
            case 3:
                playlist.searchSong();
                break;
            case 4:
                playlist.printPlaylist();
                break;
            case 5:
                playlist.playPlaylist();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

