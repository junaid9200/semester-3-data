#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next_node;
    Node* pre_node;

    Node(int data) {
        this->data = data;
        next_node = nullptr;
        pre_node = nullptr;
    }
};

class link_list {
public:
    Node* head;
    Node* tail; // New tail pointer to keep track of the last node

    link_list() {
        head = nullptr;
        tail = nullptr; // Initialize tail to nullptr
    }

    bool Add() {
        int choice;
        int data;
        int position;
        int size = 0;
        while (true) {
            cout << "Adding Item:" << endl;
            cout << "Enter Item Data: ";
            cin >> data;
            Node* new_node = new Node(data);
            cout << "Select 1 Of Following:" << endl;
            cout << "1- Add At Start" << endl;
            cout << "2- Add At End" << endl;
            cout << "3- Add After Specific Item" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                if (head == nullptr) {
                    head = new_node;
                    tail = new_node; // Update tail when adding the first node
                }
                else {
                    new_node->next_node = head;
                    head->pre_node = new_node;
                    head = new_node;
                }
                return false;
            case 2:
                if (head == nullptr) {
                    head = new_node;
                    tail = new_node;
                }
                else {
                    tail->next_node = new_node;
                    new_node->pre_node = tail;
                    tail = new_node;
                }
                return false;
            case 3:
                cout << "Enter Position: ";
                cin >> position;
                size = length_of_list();
                if (position <= 0 || position >= size) {
                    cout << "Invalid Position ! Try Again." << endl;
                }
                else {
                    Node* current = head;
                    for (int i = 0; i < position - 1; i++) {
                        current = current->next_node;
                    }
                    Node* temp = current->next_node;
                    current->next_node = new_node;
                    new_node->pre_node = current;
                    new_node->next_node = temp;
                    if (temp != nullptr) {
                        temp->pre_node = new_node;
                    }
                }
                return false;
            default:
                cout << "Invalid Input ! Try Again." << endl;
            }
        }
    }

    int length_of_list() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            current = current->next_node;
            ++length;
        }
        return length;
    }

    void display() {
        int item_no = 0;
        Node* current = head;
        cout << "Displaying Items." << endl;
        if (head == nullptr) {
            cout << "List is Empty." << endl;
        }
        else {
            while (current != nullptr) {
                cout << "Item Data " << item_no + 1 << ": " << current->data << endl;
                current = current->next_node;
                item_no++;
            }
        }
    }

    void search() {
        int key;
        cout << "Enter the Item Data to Search: ";
        cin >> key;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                cout << "Item Data Found !" << endl;
                cout << current->data << endl;
                return;
            }
            else {
                current = current->next_node;
            }
        }
        cout << "Item Not Found !" << endl;
    }

    void delete_item() {
        int choice;
        int key;
        Node* prev = nullptr;
        Node* current;
        bool itemFound = false;
        cout << "Enter Item Data to Delete: ";
        cin >> key;
        while (true) {
            cout << "Select one of the following options:" << endl;
            cout << "1- Delete the first item with matched key." << endl;
            cout << "2- Delete all items with matched key." << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                current = head;
                while (current != nullptr) {
                    if (current->data == key) {
                        if (prev == nullptr) {
                            // Deleting the first item with matched key
                            head = current->next_node;
                            if (head != nullptr) {
                                head->pre_node = nullptr;
                            }
                            delete current;
                            cout << "Item Deleted Successfully." << endl;
                            return;
                        }
                        else {
                            prev->next_node = current->next_node;
                            if (current->next_node != nullptr) {
                                current->next_node->pre_node = prev;
                            }
                            delete current;
                            cout << "Item Deleted Successfully." << endl;
                            return;
                        }
                    }
                    prev = current;
                    current = current->next_node;
                }
                cout << "Item not found in the list." << endl;
            case 2:
                current = head;
                while (current != nullptr) {
                    if (current->data == key) {
                        if (prev == nullptr) {
                            // Deleting the first item with matched key
                            head = current->next_node;
                            if (head != nullptr) {
                                head->pre_node = nullptr;
                            }
                            delete current;
                            current = head;
                            itemFound = true;
                        }
                        else {
                            prev->next_node = current->next_node;
                            if (current->next_node != nullptr) {
                                current->next_node->pre_node = prev;
                            }
                            delete current;
                            current = prev->next_node;
                            itemFound = true;
                        }
                    }
                    else {
                        prev = current;
                        current = current->next_node;
                    }
                }
                if (itemFound) {
                    cout << "All items with the matched key have been deleted." << endl;
                }
                else {
                    cout << "Item not found in the list." << endl;
                }
            default:
                cout << "Invalid Input! Try Again." << endl;
            }
        }
    }
};

int main() {
    int user_input;
    link_list list;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1- Add Item." << endl;
        cout << "2- Display Items." << endl;
        cout << "3- Search Item." << endl;
        cout << "4- Delete Items." << endl;
        cout << "5- Exit." << endl;
        cin >> user_input;
        switch (user_input) {
        case 1:
            list.Add();
            break;
        case 2:
            list.display();
            break;
        case 3:
            list.search();
            break;
        case 4:
            list.delete_item();
            break;
        case 5:
            cout << "Thanks For Using Programe." << endl;
            return 0;
        default:
            cout << "Invalid Input ! Try Again." << endl;
        }
    }
    return 0;
}
