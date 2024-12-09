#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long long n;
        std::cin >> n;

        // Calculate the sum of numbers 0 to k using a formula
        long long k = (std::sqrt(8*n + 1) - 1) / 2;

        // Calculate the starting point for the range
        long long l = n - k*(k+1)/2;

        std::cout << l << " " << l+k << std::endl;
    }

    return 0;
}