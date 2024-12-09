#include <iostream>
#include <vector>
#include <algorithm>

bool checkIdentical(std::vector<int>& dice1, std::vector<int>& dice2) {
    return std::is_permutation(dice1.begin(), dice1.end(), dice2.begin());
}

int main() {
    std::vector<int> dice1(6);
    std::vector<int> dice2(6);

    // Input for first dice
    for (int i = 0; i < 6; i++) {
        std::cin >> dice1[i];
    }

    // Input for second dice
    for (int i = 0; i < 6; i++) {
        std::cin >> dice2[i];
    }

    // Sort the dice values
    std::sort(dice1.begin(), dice1.end());
    std::sort(dice2.begin(), dice2.end());

    // Check if dices are identical
    if (checkIdentical(dice1, dice2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}