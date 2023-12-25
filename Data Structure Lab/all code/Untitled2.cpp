#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void addItemAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void addAfterItem(int value, int afterValue) {
        Node* newNode = new Node(value);

        Node* current = head;
        while (current != nullptr && current->data != afterValue) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            cout << "Item not found." << endl;
        }
    }

    void searchItem(int value) {
        Node* current = head;
        int index = 0;
        bool found = false;

        while (current != nullptr) {
            if (current->data == value) {
                cout << "Item " << value << " found at index " << index << endl;
                found = true;
            }
            current = current->next;
            index++;
        }

        if (!found) {
            cout << "Item not found." << endl;
        }
    }

    void deleteItem(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev != nullptr) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Item " << value << " deleted." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Item not found." << endl;
    }

    void deleteAllItems(int value) {
        Node* current = head;
        Node* prev = nullptr;

        bool deleted = false;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev != nullptr) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                current = prev->next;
                deleted = true;
            } else {
                prev = current;
                current = current->next;
            }
        }

        if (deleted) {
            cout << "All items with value " << value << " deleted." << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }

    void editItem(int oldValue, int newValue) {
        Node* current = head;
        bool edited = false;

        while (current != nullptr) {
            if (current->data == oldValue) {
                current->data = newValue;
                cout << "Item " << oldValue << " edited to " << newValue << "." << endl;
                edited = true;
            }
            current = current->next;
        }

        if (!edited) {
            cout << "Item not found." << endl;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "Linked List Menu:" << endl;
        cout << "1. Add item at end" << endl;
        cout << "2. Add item after another item" << endl;
        cout << "3. Search item" << endl;
        cout << "4. Delete item" << endl;
        cout << "5. Delete all items with the same value" << endl;
        cout << "6. Edit item" << endl;
        cout << "7. Display list" << endl;
        cout << "8. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int valueToAdd;
                cout << "Enter the value to add at the end: ";
                cin >> valueToAdd;
                list.addItemAtEnd(valueToAdd);
                break;
            case 2:
                int valueToAddAfter, afterValue;
                cout << "Enter the value to add: ";
                cin >> valueToAdd;
                cout << "Enter the value to add after: ";
                cin >> afterValue;
                list.addAfterItem(valueToAdd, afterValue);
                break;
            case 3:
                int searchValue;
                cout << "Enter the value to search: ";
                cin >> searchValue;
                list.searchItem(searchValue);
                break;
            case 4:
                int deleteValue;
                cout << "Enter the value to delete: ";
                cin >> deleteValue;
                list.deleteItem(deleteValue);
                break;
            case 5:
                int deleteAllValue;
                cout << "Enter the value to delete all occurrences of: ";
                cin >> deleteAllValue;
                list.deleteAllItems(deleteAllValue);
                break;
            case 6:
                int oldValue, newValue;
                cout << "Enter the value to edit: ";
                cin >> oldValue;
                cout << "Enter the new value: ";
                cin >> newValue;
                list.editItem(oldValue, newValue);
                break;
            case 7:
                cout << "Linked List: ";
                list.display();
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}

