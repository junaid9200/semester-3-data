#include <iostream>

// Recursive function to calculate the factorial of a number
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    double x = 3, sum = 0;
    int numTerms = 5;


    for (int i = 0; i < numTerms; i++) {
        double term = 1.0;
        
        // Calculate the numerator (x raised to the power of 2*i+1)
        for (int j = 0; j < 2 * i + 1; j++) {
            term *= x;
        }

        // Calculate the denominator (factorial of 2*i+1) using recursion
        term /= factorial(2 * i + 1);

        // Alternate between adding and subtracting terms
        if (i % 2 == 1) {
            term = -term;
        }

        sum += term;
    }

    std::cout << "Sum of the series: " << sum << std::endl;

    return 0;
}

