#include <iostream>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    
    int totalVariants = 0;
    
    for (int k = 5; k <= 7; k++) {
        totalVariants += factorial(n) / (factorial(k) * factorial(n - k));
    }
    
    std::cout << totalVariants << std::endl;
    
    return 0;
}