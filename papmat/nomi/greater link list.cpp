#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int countLessThanAll(LinkedList& otherList) {
        if (head == nullptr || otherList.head == nullptr) {
            return 0;
        }

        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            Node* otherCurrent = otherList.head;
            int val = current->data;

            while (otherCurrent != nullptr && otherCurrent->data < val) {
                otherCurrent = otherCurrent->next;
            }

            if (otherCurrent == nullptr) {
                count++;
            }

            current = current->next;
        }

        return count;
    }

    int countGreaterThanAll(LinkedList& otherList) {
        if (head == nullptr || otherList.head == nullptr) {
            return 0;
        }

        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            Node* otherCurrent = otherList.head;
            int val = current->data;

            while (otherCurrent != nullptr && otherCurrent->data > val) {
                otherCurrent = otherCurrent->next;
            }

            if (otherCurrent == nullptr) {
                count++;
            }

            current = current->next;
        }

        return count;
    }
};

int main() {
    LinkedList list1;
    list1.insert(5);
    list1.insert(8);
    list1.insert(10);

    LinkedList list2;
    list2.insert(1);
    list2.insert(6);
    list2.insert(9);
    list2.insert(11);

    int lessThanCount = list2.countLessThanAll(list1);
    int greaterThanCount = list2.countGreaterThanAll(list1);

    std::cout << "Number of elements in the 2nd list less than all elements of the 1st list: " << lessThanCount << std::endl;
    std::cout << "Number of elements in the 2nd list greater than all elements of the 1st list: " << greaterThanCount << std::endl;

    return 0;
}

