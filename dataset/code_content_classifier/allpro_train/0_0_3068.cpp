#include <iostream>
#include <cmath>

int main() {
    int m, n;
    std::cin >> m >> n;

    // If the number of animals is less than n or the number of wolves is greater than the number of goats,
    // it's impossible to transport all the animals without anyone getting upset
    if (m < n || m > 2 * n) {
        std::cout << -1 << std::endl;
    } else {
        // Calculate the minimum number of times Vasya will have to cross the river
        int min_crossings = ceil((double)(m + n - 1) / (double)n);
        
        // Vasya needs to cross the river one extra time to return to the initial bank
        std::cout << min_crossings + 1 << std::endl;
    }

    return 0;
}