#include <iostream>
#include <cstring>
using namespace std;

class Arraylist {
public:
    char *arr;
    int size_of_string;
    int capacity;

    Arraylist(int size_of_string, const char *ptr) {
        this->size_of_string = size_of_string;
        arr = new char[size_of_string + 1]; // +1 for null-terminator
        for (int i = 0; i < size_of_string; i++) {
            arr[i] = ptr[i];
        }
        arr[size_of_string] = '\0'; // Null-terminate the string
        capacity = size_of_string;
    }

    void insert(char character, int position) {
        if (position < 0 || position > size_of_string) {
            cout << "Invalid position for insertion." << endl;
            return;
        }

        if (size_of_string == capacity) {
            cout << "Array is full. Cannot insert more characters." << endl;
            return;
        }

        for (int i = size_of_string; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = character;
        size_of_string++;
    }

    void remove(int position) {
        if (position < 0 || position >= size_of_string) {
            cout << "Invalid position for removal." << endl;
            return;
        }

        for (int i = position; i < size_of_string - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size_of_string--;
    }

    void display_array() {
        cout << "Displaying Default random string: " << arr << endl;
    }

    ~Arraylist() {
        delete[] arr;
    }
};

int main() {
    char random_char[] = "ahdme";
    char arranged_char[] = "ahmed";
    int user_input;
    int size_of_string = strlen(arranged_char);
    Arraylist list(size_of_string, random_char);

    list.display_array();
    while (true) {
        cout << "\nChoose an option below:" << endl;
        cout << "1- Insert" << endl;
        cout << "2- Remove" << endl;
        cout << "3- Exit" << endl;
        cout << "Your Input: ";
        cin >> user_input;

        switch (user_input) {
            case 1:
                char character_to_insert;
                int position_to_insert;
                cout << "Enter the character to insert: ";
                cin >> character_to_insert;
                cout << "Enter the position to insert: ";
                cin >> position_to_insert;
                list.insert(character_to_insert, position_to_insert);
                list.display_array();
                break;
            case 2:
                int position_to_remove;
                cout << "Enter the position to remove: ";
                cin >> position_to_remove;
                list.remove(position_to_remove);
                list.display_array();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

