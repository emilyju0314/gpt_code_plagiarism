#include <iostream>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int X;
    std::cin >> X;
    
    while (!is_prime(X)) {
        X++;
    }
    
    std::cout << X << std::endl;
    
    return 0;
}