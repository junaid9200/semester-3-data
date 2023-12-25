#include <iostream>
using namespace std;

int main()
{
    // Set the console color to cyan
    cout << "\033[96m";

    // Print the text in cyan color
    cout << "This is cyan text on a black background." << endl;

    // Reset the console color to default
    cout << "\033[0m";
 // Set the console color to green
    cout << "\033[32m";

    // Print the text in green color
    cout << "This is green text." << endl;

    // Reset the console color to default
    cout << "\033[0m";
// Set the console color to red
    cout << "\033[31m";

    // Print the text in red color
    cout << "This is red text." << endl;

    // Reset the console color to default
    cout << "\033[0m";
    // Set the console color to yellow
    cout << "\033[33m";

    // Print the text in yellow color
    cout << "This is yellow text." << endl;

    // Reset the console color to default
    cout << "\033[0m";
     // Set the console color to blue
    cout << "\033[34m";

    // Print the text in blue color
    cout << "This is blue text." << endl;

    // Reset the console color to default
    cout << "\033[0m";
    
    return 0;
}

