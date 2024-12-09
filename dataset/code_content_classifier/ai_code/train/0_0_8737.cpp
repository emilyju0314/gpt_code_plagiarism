#include <iostream>
#include <vector>
#include <unordered_map>

bool checkWinningConditions(std::vector<int>& nums, std::vector<char>& colors) {
    // Count the occurrences of each color-number combination
    std::unordered_map<std::string, int> counts;
    for (int i = 0; i < nums.size(); i++) {
        counts[std::to_string(nums[i]) + colors[i]]++;
    }

    // Check if there are three sets of three cards in hand
    int sets = 0;
    for (int i = 1; i <= 9; i++) {
        int redCount = counts[std::to_string(i) + "R"];
        int greenCount = counts[std::to_string(i) + "G"];
        int blueCount = counts[std::to_string(i) + "B"];

        if ((redCount >= 3 && greenCount >= 3 && blueCount >= 3) || (redCount == 3 && greenCount == 3 && blueCount < 3) || (redCount == 3 && greenCount < 3 && blueCount == 3) || (redCount < 3 && greenCount == 3 && blueCount == 3)) {
            sets++;
        }
    }

    return sets >= 3;
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::vector<int> nums(9);
        std::vector<char> colors(9);

        for (int j = 0; j < 9; j++) {
            std::cin >> nums[j];
        }

        for (int j = 0; j < 9; j++) {
            std::cin >> colors[j];
        }

        if (checkWinningConditions(nums, colors)) {
            std::cout << "1" << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }
    }

    return 0;
}