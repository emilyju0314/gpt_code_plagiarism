#include <iostream>

int main() {
    int n, factorial = 1;
    
    // Input
    std::cin >> n;
    
    // Calculate factorial
    for(int i = 1; i <= n; i++) {
        factorial *= i;
    }
    
    // Output
    std::cout << factorial << std::endl;
    
    return 0;
}