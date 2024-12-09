#include <iostream>

int main() {
    // Input
    long long n;
    std::cin >> n;

    // Initialize counter
    int count = 0;

    // Check each number from 1 to n
    for (long long i = 1; i <= n; i++) {
        bool divisible = true;
        for (int j = 2; j <= 10; j++) {
            if (i % j != 0) {
                divisible = false;
                break;
            }
        }
        if (divisible) {
            count++;
        }
    }

    // Output the result
    std::cout << count << std::endl;

    return 0;
}