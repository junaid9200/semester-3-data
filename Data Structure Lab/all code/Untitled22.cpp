#include <iostream>
#include <string>

using namespace std;

struct Song {
    string name;
    int favorite_level;
    Song* next;
};

class PlaylistManager {
private:
    Song* head;

public:
    PlaylistManager() {
        head = nullptr;
    }

    void addSong() {
        string name;
        int favorite_level;
        
        cout << "Enter the song name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Specify favorite level:\n";
        cout << "1. Top Favorite\n";
        cout << "2. Least Favorite\n";
        cout << "3. Somewhere between (custom)\n";
        cout << "Enter your choice: ";
        cin >> favorite_level;
        
        Song* new_song = new Song;
        new_song->name = name;
        new_song->favorite_level = favorite_level;
        new_song->next = nullptr;

        if (head == nullptr || favorite_level == 1) {
            new_song->next = head;
            head = new_song;
        } else if (favorite_level == 2) {
            if (head == nullptr) {
                head = new_song;
            } else {
                Song* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = new_song;
            }
        } else {
            int num_songs = getPlaylistLength();
            if (num_songs == 0) {
                head = new_song;
            } else {
                int custom_level;
                cout << "Enter custom priority (between 2 and " << num_songs + 2 << "): ";
                cin >> custom_level;
                if (custom_level < 2) {
                    custom_level = 2;
                } else if (custom_level > num_songs + 2) {
                    custom_level = num_songs + 2;
                }
                if (custom_level == 2) {
                    new_song->next = head;
                    head = new_song;
                } else {
                    Song* prev = head;
                    Song* current = head->next;
                    int current_level = 3;
                    while (current != nullptr && current_level < custom_level) {
                        prev = current;
                        current = current->next;
                        current_level++;
                    }
                    prev->next = new_song;
                    new_song->next = current;
                }
            }
        }
        cout << "Song added successfully.\n";
        printPlaylist();
    }

    void deleteSong() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        string name;
        cout << "Enter the song name to delete: ";
        cin.ignore();
        getline(cin, name);

        if (head->name == name) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << "Song deleted successfully.\n";
            printPlaylist();
            return;
        }

        Song* prev = head;
        Song* current = head->next;
        while (current != nullptr) {
            if (current->name == name) {
                prev->next = current->next;
                delete current;
                cout << "Song deleted successfully.\n";
                printPlaylist();
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Song not found in the playlist.\n";
    }

    void searchSong() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        string name;
        cout << "Enter the song name to search: ";
        cin.ignore();
        getline(cin, name);

        Song* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Song: " << current->name << ", Favorite Level: " << current->favorite_level << endl;
                return;
            }
            current = current->next;
        }

        cout << "Song not found in the playlist.\n";
    }

    void printPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "Playlist:\n";
        Song* current = head;
        while (current != nullptr) {
            cout << "Song: " << current->name << ", Favorite Level: " << current->favorite_level << endl;
            current = current->next;
        }
    }

    void playPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* current = head;
        cout << "Playing: " << current->name << endl;
        current = current->next;

        while (current != nullptr) {
            cout << "Press any key to play the next song (or 'q' to stop): ";
            char choice;
            cin >> choice;
            if (choice == 'q') {
                break;
            }
            cout << "Playing: " << current->name << endl;
            current = current->next;
        }
    }

    int getPlaylistLength() {
        int length = 0;
        Song* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    ~PlaylistManager() {
        while (head != nullptr) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PlaylistManager playlist;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add a Song\n";
        cout << "2. Delete a Song\n";
        cout << "3. Search for a Song\n";
        cout << "4. Print Playlist\n";
        cout << "5. Play Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
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
            case 6:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

