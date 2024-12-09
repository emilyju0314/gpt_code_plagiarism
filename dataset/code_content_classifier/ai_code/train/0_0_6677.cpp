#include <iostream>
#include <cmath>

int main() {
    int x;
    std::cin >> x;

    // Handling the case when x is negative
    x = std::abs(x);

    // Calculating the sum of jumps until it exceeds x
    int sum = 0, jumps = 0;
    while (sum < x || (sum - x) % 2 != 0) {
        jumps++;
        sum += jumps;
    }

    std::cout << jumps << std::endl;

    return 0;
}