#include <iostream>
using namespace std;

const int maxnu = 5;

struct Stack 
{
    int top;
    int item[maxnu];
};

void initstack(Stack& stack) 
{
    stack.top = -1;
}

bool isfull(Stack& stack) 
{
    return stack.top == maxnu - 1;
}

bool isempty(Stack& stack) 
{
    return stack.top == -1;
}

void push(Stack& stack, int disk) 
{
    if (isfull(stack)) 
	{
        cout << "stack is full" << endl;
        return;
    }
    stack.item[++stack.top] = disk;
}

int pop(Stack& stack) 
{
    if (isempty(stack)) 
	{
        cout << "stack is empty" << endl;
        return -1;
    }
    return stack.item[stack.top--];
}

void movedisk(char fromrod, char torod, int disk) 
{
	cout<<"---------------------------------------------------"<<endl;
    cout<<"\t" << "Move disk " << disk << " from rod " << fromrod << " to rod " << torod << endl;
    cout<<"---------------------------------------------------"<<endl;
}

void hanoi(int num, Stack& source, Stack& dest, Stack& aux, char sourcerod, char destrod, char auxrod) 
{
    int total = (1 << num) - 1; 

    for (int i = num; i >= 1; --i)
    {
    	push(source, i);
	}
    for (int move = 1; move <= total; ++move) 
	{
        if (move % 3 == 1) 
		{
            if (!isempty(source))
			{
                int disk = pop(source);
                movedisk(sourcerod, destrod, disk);
                push(dest, disk);
            }
        } 
		else if (move % 3 == 2) 
		{
            if (!isempty(source)) 
			{
                int disk = pop(source);
                movedisk(sourcerod, auxrod, disk);
                push(aux, disk);
            }
        }
		else if (move % 3 == 0) 
		{
            if (!isempty(aux))
			{
                if (isempty(dest) || aux.item[aux.top] < dest.item[dest.top]) 
				{
                    int disk = pop(aux);
                    movedisk(auxrod, destrod, disk);
                    push(dest, disk);
                }
				else 
				{
                    int disk = pop(dest);
                    movedisk(destrod, auxrod, disk);
                    push(aux, disk);
                }
            }
        }
    }
    cout<<endl;
    cout <<"--->"<< " Total moves: " << total << endl;
}

int main() 
{
	 cout<<"\t\t\t-----------Tower of Hanoi----------"<<endl;
	 cout<<endl;
    int nd;
    cout << "Enter the number of disks: ";
    cin >> nd;
   
    Stack source, aux, dest;
    initstack(source);
    initstack(aux);
    initstack(dest);

    hanoi(nd, source, dest, aux, 'A', 'C', 'B');

}

