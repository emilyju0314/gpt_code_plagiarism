#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        long long a, b;
        std::cin >> a >> b;

        // Calculate the absolute difference between a and b
        long long diff = std::abs(a - b);

        // Calculate the sum of all integers from 1 to n (n*(n+1)/2)
        long long sum = (diff * (diff + 1)) / 2;

        // Output the sum, which is the minimum number of operations required
        std::cout << sum << std::endl;
    }

    return 0;
}