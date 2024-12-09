#include <iostream>
#include <cmath>

int main() {
    long long X, K, D;
    std::cin >> X >> K >> D;

    // Calculate the number of steps needed to reach 0
    long long steps_to_zero = std::abs(X) / D;

    // Handle case when K is greater than steps_to_zero
    if (K >= steps_to_zero) {
        long long remaining_moves = K - steps_to_zero;
        if (remaining_moves % 2 == 0) {
            std::cout << std::abs(X - steps_to_zero * D) << std::endl;
        } else {
            std::cout << std::abs(X - steps_to_zero * D - D) << std::endl;
        }
    } 
    // Handle case when K is smaller than steps_to_zero
    else {
        std::cout << std::abs(X - K * D) << std::endl;
    }

    return 0;
}