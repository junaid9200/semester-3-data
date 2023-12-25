#include<iostream>
#include<string>
using namespace std;

struct stack_node {
    string data;
    stack_node* next_ptr;
    stack_node(string data) : data(data), next_ptr(nullptr) {}
};

struct list_node {
    string word;
    list_node* next_ptr;
    list_node(string word) : word(word), next_ptr(nullptr) {}
};

class link_list {
public:
    list_node* head;
    list_node* current;
    stack_node* stack;
    stack_node* top;

    link_list() : head(nullptr), current(nullptr), stack(nullptr), top(nullptr) {}

    ~link_list() {
        // Destructor to deallocate memory for nodes
        while (head != nullptr) {
            list_node* temp = head;
            head = head->next_ptr;
            delete temp;
        }
        while (top != nullptr) {
            stack_node* temp = top;
            top = top->next_ptr;
            delete temp;
        }
    }

    void push(string to_push) {
        if (stack == nullptr) {
            stack_node* new_node = new stack_node(to_push);
            top = new_node;
        }
        else {
            stack_node* temp = top;
            top = new stack_node(to_push);
            top->next_ptr = temp;
        }
    }

    string pop() {
        if (top == nullptr) {
            return ""; // Handle empty stack case
        }
        stack_node* temp2 = top;
        top = top->next_ptr;
        string popped_data = temp2->data;
        delete temp2; // Deallocate memory for popped node
        return popped_data;
    }

    void add_word(string word) {
        if (head == nullptr) {
            list_node* new_node = new list_node(word);
            head = new_node;
            current = new_node;
        }
        else {
            list_node* new_node = new list_node(word);
            current->next_ptr = new_node;
            current = new_node;
        }
    }

    void reverse_words() {
    current = head;
    stack = nullptr;
    // Push words onto the stack
    while (current != nullptr) {
        push(current->word);
        current = current->next_ptr;
    }
    current = head;
    // Pop words from the stack and update the linked list
    while (current != nullptr) {
        current->word = pop();
        current = current->next_ptr;
    }
    current = head; // Reset the current pointer to the head after reversing
}

    void display_list() {
        current = head;
        while (current != nullptr) {
            cout << current->word << " ";
            current = current->next_ptr;
        }
    }
};

int main() {
    while (true) {
        int no_of_words = 0;
        int user_choice = 0;
        string user_word;
        link_list obj_list;

        cout << "Hello Ken, let's help you out with the message!" << endl;
        cout << "How many words are in the message to work my magic on: ";
        cin >> no_of_words;

        if (no_of_words <= 0) {
            cout << "Invalid input. Number of words must be positive." << endl;
            return 1; // Exit with an error code
        }

        for (int i = 0; i < no_of_words; i++) {
            cout << "Enter the word " << i + 1 << ": ";
            cin >> user_word;
            obj_list.add_word(user_word);
        }

        cout << "\nDisplaying Original Message." << endl;
    obj_list.display_list();

    obj_list.reverse_words();

    cout << "\nDecrypted Message: ";
    obj_list.display_list();
    cout << endl;
        cout << "Ken, Now head there and get your treasure!" << endl;
        cout << "Your Wizard friend got your back to help ya out." << endl;
        cout << "Ken, You got another message?" << endl;
        cout << "Press 1 to enter message again." << endl;
        cout << "Press 2 to exit." << endl;
        cin >> user_choice;

        switch (user_choice) {
            case 1:
                break;
            case 2:
                cout << "Good Job Ken, you found your treasure!" << endl;
                return 0;
            default:
                cout << "Invalid input." << endl;
                return 1; // Exit with an error code
        }
    }
    return 0;
}

