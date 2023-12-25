#include <iostream>
#include <string>
using namespace std;


class CircularGame 
{
private:
    string name;
    CircularGame* next;

    CircularGame* head;

public:
    CircularGame() 
	{
		this->head=NULL;
	}

    void insertPlayer(string& name) 
	{
        CircularGame* newPlayer = new CircularGame();
        newPlayer->name = name;

        if (!head) 
		{
            head = newPlayer;
            head->next = head;  
        } 
		else 
		{
            CircularGame* temp = head;
            while (temp->next != head) 
			{
                temp = temp->next;
            }
            temp->next = newPlayer;
            newPlayer->next = head;
        }
    }

    void printPlayers() 
	 {
        if (!head) 
		{
            cout << "No players in the game." << endl;
            return;
        }

        CircularGame* current = head;
        do {
            cout << current->name << " ";
            current = current->next;
        } 
		while (current != head);
        cout << endl;
    }

    void removePlayer() 
	{
        if (!head) 
		{
            cout << "No players left in the game." << endl;
            return;
        }

        CircularGame* temp = head;
        CircularGame* prev = nullptr;
        int count = 1;

        while (count < 4) 
		{
            prev = temp;
            temp = temp->next;
            count++;
        }

        prev->next = temp->next;

        if (temp == head) 
		{
            head = head->next;
        }

        cout << "Removed from game: " << temp->name << endl;
        delete temp;
    }

    const string getWinner() 
	 {
        if (!head) 
		
		{
            return "No winner (no players in the game).";
        }

        if (head->next == head) 
		{
            return head->name;
        }  
		else 
		{
            return "No winner yet.";
        }
    }

    void playGame() 
	{
        for (int i = 1; i <= 5; ++i) 
		{
            cout << "Enter name for player " << i << ": ";
            string playerName;
            cin >> playerName;
            insertPlayer(playerName);
        }

        cout << "Players in the game:" << endl;
        printPlayers();

        int check = 4;
        while (check > 0)
		 {
            cout << "Press Enter to remove a player...";
            cin.ignore();  
            cin.get();     
            removePlayer();
            printPlayers();
            check--;
        }

        cout << "The winner is: " << getWinner() << endl;
    }
};

int main() 
{
    CircularGame game;
    game.playGame();
}

