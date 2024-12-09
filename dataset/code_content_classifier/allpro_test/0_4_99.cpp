#include <iostream>
#include <cmath>

int main() {
    int t;
    long long x_0, n;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> x_0 >> n;

        // Determine if initial position is even or odd
        bool is_even = x_0 % 2 == 0;

        // Calculate total number of jumps
        long long total_jumps = (long long)std::sqrt(2 * n + 0.25) - 1;
        
        // Update the position of the grasshopper after each jump
        long long final_position = x_0 + n - (total_jumps * (total_jumps + 1) / 2) * (is_even ? 1 : -1);

        std::cout << final_position << std::endl;
    }

    return 0;
}