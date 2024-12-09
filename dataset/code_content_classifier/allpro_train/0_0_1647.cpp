#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    std::cin >> n;
    
    if (n < 0 || n > 44) {
        std::cout << "Invalid input, n should be between 0 and 44";
    } else {
        int result = fibonacci(n);
        std::cout << result;
    }
    
    return 0;
}