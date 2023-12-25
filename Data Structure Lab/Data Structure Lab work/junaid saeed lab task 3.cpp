// hottest day of the week.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
          {
    srand(time(0));

    int temp[4][7];
    int *tempPtr = &temp[0][0];
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 7; ++j) {
            *tempPtr = rand() % 21 + 10; // Generates random number between 10 and 30
            ++tempPtr;
        }
    }

    tempPtr = &temp[0][0];

    cout << "Temperatures of Each week :" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << *tempPtr << "     ";
            ++tempPtr;
        }
        cout << endl;
    }
    
    tempPtr = &temp[0][0];
    for (int i = 0; i < 4; ++i) {
        int maxTemp = *tempPtr;
        int hottestDay = 0;
        for (int j = 1; j < 7; ++j) {
            ++tempPtr;
            if (*tempPtr > maxTemp) {
                maxTemp = *tempPtr;
                hottestDay = j;
            }
        }
        cout<<endl;
        cout << "Hottest day of week : " << i + 1 << " is : day " << hottestDay + 1 << " having temperature : " << maxTemp<< endl;
        ++tempPtr;
    }
}
