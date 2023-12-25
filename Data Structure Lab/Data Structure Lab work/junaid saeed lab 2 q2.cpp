#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

  const int size = 3;
   void get(char grid[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == size / 2 && j == size / 2) {
                grid[i][j] = 'o'; 
            } else {
                grid[i][j] = (rand() % 2 == 0) ? '-' : 'x'; 
            }
        }
    }
}

void print(char grid[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    char grid[size][size];
    get(grid);

    cout << "Welcome to the game " <<endl;
    cout << "Your character is 'o'. Move using 't' (top), 'b' (bottom), 'l' (left), 'r' (right)." << endl;

    bool gameWon = false;
    int playerRow = size / 2;
    int playerCol = size / 2;

    while (!gameWon) {
        print(grid);

        char move;
        cout << "Enter your move (t/b/l/r): ";
        cin >> move;

        char *ptr = &grid[playerRow][playerCol]; 

        switch (move) {
            case 't':
                if (playerRow > 0) {
                    ptr -= size;
                    playerRow--;
                }
                break;
            case 'b':
                if (playerRow < size - 1) {
                    ptr +=size;
                    playerRow++;
                }
                break;
            case 'l':
                if (playerCol > 0) {
                    ptr--;
                    playerCol--;
                }
                break;
            case 'r':
                if (playerCol < size - 1) {
                    ptr++;
                    playerCol++;
                }
                break;
            default:
                cout << "Invalid move! Please use 't', 'b', 'l', or 'r'." << endl;
                continue; 
        }

        if (*ptr == '-') {
            cout << "Move successful. Keep going!" << endl;
        } else if (*ptr == 'x') {
            cout << "You lost, collided" << endl;
            break;
        } else if (*ptr == 'o') {
            cout << "you won" << endl;
            break;
        }

        *ptr = 'o'; 
    }
    print(grid);
     cout << "Game over." << endl;
}

