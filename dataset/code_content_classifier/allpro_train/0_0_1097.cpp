#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string entrances;
    std::cin >> entrances;

    std::vector<int> doorCount(26, 0); // Initialize a vector to keep track of number of guests using each entrance
    int maxOpened = 0; // Initialize a variable to keep track of maximum number of doors opened

    for (int i = 0; i < n; i++) {
        doorCount[entrances[i] - 'A']++; // Increment the guest count for the corresponding entrance
        maxOpened = std::max(maxOpened, *max_element(doorCount.begin(), doorCount.end())); // Update the maximum number of doors opened
        if (maxOpened > k) {
            std::cout << "YES" << std::endl; // If more doors are opened than guards available, output "YES"
            return 0;
        }
    }

    std::cout << "NO" << std::endl; // If all doors can be guarded, output "NO"

    return 0;
}