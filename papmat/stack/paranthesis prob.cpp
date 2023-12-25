#include<iostream>
using namespace std;

class node {
public:
    char data;
    node* next;
    node() : data('0'), next(nullptr) {}
    node(char data) : data(data), next(nullptr) {}
};

class check {
private:
    node* head = nullptr;
    node* temp = nullptr;

public:
    bool paren(string str) {
        bool ans = true;
        int length = str.length(); // Use the length function for strings

        for (int i = 0; i < length; i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                push(str[i]);
            }
            else if (str[i] == ')') {
                if (top() == '(') {
                    pop();
                }
                else {
                    ans = false;
                    break;
                }
            }
            else if (str[i] == '}') {
                if (top() == '{') {
                    pop();
                }
                else {
                    ans = false;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (top() == '[') {
                    pop();
                }
                else {
                    ans = false;
                    break;
                }
            }
        }

        if (temp != nullptr) {
            return false;
        }
        return ans;
    }

    void push(char data) {
        node* new_node = new node(data);
        
        if (head == nullptr) {
            temp = new_node;
            head = new_node;
        }
        else {
            new_node->next = temp;
            temp = new_node;
        }
    }

    char pop() {
        if (temp == nullptr) {
            cout << "Underflow" << endl;
            return '\0'; // Return a default value
        }
        else {
            node* trash = temp;
            temp = temp->next;
            char data = trash->data; // Store the data before deleting the node
            delete trash;
            return data;
        }
    }

    char top() {
        if (temp == nullptr) {
            cout << "Stack is empty" << endl;
            return '\0'; // Return a default value
        }
        char info = temp->data;
        return info;
    }
};

int main() {
    cout << "Enter string:";
    string str;
    cin >> str;
    check pare;
    if (pare.paren(str)) {
        cout << "Valid string" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
}
