#include<iostream>
using namespace std;

void hanoi(int num_disks, char source, char destination, char auxiliary);
 
class Stack{
public:
    static const int max_size = 100;
    int data[max_size];
    int size;

    Stack() {
        size = 0;
    }

    int get_size() {
        return size;
    }

    bool is_empty() {
        return size == 0;
    }
    
    int To_pop() {
        if (!is_empty()) {
            return data[--size];
        }
        else {
            cout << "Stack Underflowing !" << endl;
            return -1;
        }
    }

    void push_stack(int key) {
        if (size < max_size) {
            data[size++] = key;
        }
        else {
            cout << "Stack Overflowing !" << endl;
        }
    }

    int top() {
        if (!is_empty()) {
            return data[size - 1];
        }
        else {
            cout << "Stack Is Empty !" << endl;
            return -1;
        }
    }
};

void display_move(int disk, char source, char destination) {
    cout << "Move Disk - " << disk << " from Rod - " << source << " To Rod - " << destination << endl;
}

int main() {
    int number_of_disks;
	while(true){
		cout << "Enter The Number Of Disks: ";
    	cin >> number_of_disks;
    	if(number_of_disks <= 0){
        	cout << "Number Of Disks Should be Greater Than 0." << endl;
    	}
    	else{
    		break;
		}
	}
    hanoi(number_of_disks, 'A', 'B', 'C');
    return 0;
}

void hanoi(int num_disks, char source, char destination, char auxiliary) {
    Stack rod_A, rod_B, rod_C;
    for (int i = num_disks; i >= 1; --i) {
        rod_A.push_stack(i);
    }

    char temp;
    if (num_disks % 2 == 0) {
        temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    int total_moves = (1 << num_disks) - 1;

    for (int move = 1; move <= total_moves; ++move) {
        if (move % 3 == 1) {
            if (!rod_A.is_empty() && (rod_B.is_empty() || rod_A.top() < rod_B.top())) {
                rod_B.push_stack(rod_A.To_pop());
                display_move(rod_B.top(), source, destination);
            }
            else {
                rod_A.push_stack(rod_B.To_pop());
                display_move(rod_A.top(), destination, source);
            }
        }
        else if (move % 3 == 2) {
            if (!rod_A.is_empty() && (rod_C.is_empty() || rod_A.top() < rod_C.top())) {
                rod_C.push_stack(rod_A.To_pop());
                display_move(rod_C.top(), source, auxiliary);
            }
            else {
                rod_A.push_stack(rod_C.To_pop());
                display_move(rod_A.top(), auxiliary, source);
            }
        }
        else {
            if (!rod_C.is_empty() && (rod_B.is_empty() || rod_C.top() < rod_B.top())) {
                rod_B.push_stack(rod_C.To_pop());
                display_move(rod_B.top(), auxiliary, destination);
            }
            else {
                rod_C.push_stack(rod_B.To_pop());
                display_move(rod_C.top(), destination, auxiliary);
            }
        }
    }
    cout << "Total Moves Required are: " << total_moves << endl;
}

